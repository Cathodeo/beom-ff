#ifndef DBQUERY_H
#define DBQUERY_H

#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <string.h>
#include "dbconnect.h"


char* query_first(sqlite3 *db, const char *query);
int* querry_array(sqlite3 *db, const char *query, int *out_count);



#endif
