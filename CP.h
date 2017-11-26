#ifndef _CP_h_gf
#define _CP_h_gf
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct CP {
  char* course;
  char* preReq;
  struct CP* next;
};

struct CP** createTable();
int getCPKey(struct CP* cp);
void insertTuple(struct CP** cpTable, char* course, char* preReq);
void deleteTuple(struct CP** cpTable, char* course, char* preReq);
void printTable(struct CP** cpTable);
void lookup(struct CP** cpTable, char* course, char* preReq);

#endif
