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

struct CP** createCPTable();
int getCPKey(struct CP* cp);
void insertCPTuple(struct CP** cpTable, char* course, char* preReq);
void deleteCPTuple(struct CP** cpTable, char* course, char* preReq);
void printCPTable(struct CP** cpTable);
void lookupCP(struct CP** cpTable, char* course, char* preReq);

#endif
