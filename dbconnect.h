#ifndef DBCONNECT_H
#define DBCONNECT_H


#include <stdio.h>
#include <sqlite3.h>
#include <string.h>


sqlite3* db_open(const char *db_name);
void db_close(sqlite3 *db);


#endif // DBCONNECT_H
