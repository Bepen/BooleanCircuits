#ifndef _CR_h_gf
#define _CR_h_gf
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct CR {
  char* course;
  char* room;
  struct CR* next;
};

struct CR** createTable();
int getCRKey(struct CR* cr);
void insertTuple(struct CR** crTable, char* course, char* room);
void deleteTuple(struct CR** crTable, char* course, char* room);
void printTable(struct CR** crTable);
void lookup(struct CR** crTable, char* course, char* room);

#endif
