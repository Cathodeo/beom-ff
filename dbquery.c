#include "dbquery.h"

char* query_first(sqlite3 *db, const char *query) {
    sqlite3_stmt *stmt;
    int rc;

    // Prepare the SQL statement
    rc = sqlite3_prepare_v2(db, query, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return NULL;
    }

    // Execute the query
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        // Get the first column as a string
        const unsigned char *result = sqlite3_column_text(stmt, 0);
        if (result) {
            // Allocate memory for the result and copy the string
            char *res_str = strdup((const char *)result);
            sqlite3_finalize(stmt); // Clean up the statement
            return res_str; // Return the result
        }
    } else if (rc == SQLITE_DONE) {
        fprintf(stderr, "Query returned no rows.\n");
    } else {
        fprintf(stderr, "Error executing query: %s\n", sqlite3_errmsg(db));
    }

    // Clean up and return NULL if no result was found or an error occurred
    sqlite3_finalize(stmt);
    return NULL;
}

int* querry_array(sqlite3 *db, const char *query, int *out_count) {
    sqlite3_stmt *stmt;
    int rc;
    int *result_array = NULL;
    int capacity = 10; // Initial capacity for the array
    int count = 0;     // Number of elements in the array

    // Prepare the SQL statement
    rc = sqlite3_prepare_v2(db, query, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        *out_count = 0;
        return NULL;
    }

    // Allocate initial memory for the array
    result_array = (int *)malloc(capacity * sizeof(int));
    if (!result_array) {
        fprintf(stderr, "Memory allocation failed.\n");
        sqlite3_finalize(stmt);
        *out_count = 0;
        return NULL;
    }

    // Execute the query and collect results
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        if (count >= capacity) {
            // Reallocate if capacity is exceeded
            capacity *= 2;
            int *temp = (int *)realloc(result_array, capacity * sizeof(int));
            if (!temp) {
                fprintf(stderr, "Memory reallocation failed.\n");
                free(result_array);
                sqlite3_finalize(stmt);
                *out_count = 0;
                return NULL;
            }
            result_array = temp;
        }

        // Fetch the integer from the first column
        result_array[count++] = sqlite3_column_int(stmt, 0);
    }

    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Error executing query: %s\n", sqlite3_errmsg(db));
        free(result_array);
        sqlite3_finalize(stmt);
        *out_count = 0;
        return NULL;
    }

    // Finalize the statement
    sqlite3_finalize(stmt);

    // Return the count and the result array
    *out_count = count;
    return result_array;
}

