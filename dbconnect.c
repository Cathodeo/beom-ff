#include "dbconnect.h"


sqlite3* db_open(const char *db_name) {
	sqlite3 *db;
	int rc = sqlite3_open(db_name, &db);
	rc = sqlite3_open(db_name, &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        return NULL;
    }
    return db;
}

void db_close(sqlite3 *db) {
    if (db != NULL) { // Ensure db is valid
        sqlite3_close(db); // Close the database
        printf("Database closed successfully.\n");
    }
}



