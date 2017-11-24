#ifndef _SNAP_h_gf
#define _SNAP_h_gf
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct SNAP {
  char* name;
  int studentID;
  char* address;
  char* phone;
  struct SNAP* next;
};

struct SNAP* newSNAP(int studentID, char* name, char* address, char* grade);
struct SNAP** createTable();
int getHashKey(struct SNAP* snap);
void insertTuple(struct SNAP** snapTable, int studentID, char* name, char* address, char* phone);
void deleteTuple(struct SNAP** snapTable, int studentID, char* name, char* address, char* phone);
void printTable(struct SNAP** snapTable);

#endif
