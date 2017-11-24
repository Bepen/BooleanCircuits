//test1
#ifndef _CDH_h_gf
#define _CDH_h_gf
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct CDH {
  char* course;
  char* day;
  char* hour;
  struct CDH* next;
};

struct CDH* newCDH(char* course, char* day, char* hour);
struct CDH** createTable();
int getHashKey(struct CDH* cdh);
void deleteTuple(struct CDH** cdhTable, char* course, char* day, char* hour);
void printTable(struct CDH** cdhTable);
void insertTuple(struct CDH** cdhTable, char* course, char* day, char* hour);
void lookup(struct CDH** cdhTable, char* course, char* day, char* hour);

#endif
