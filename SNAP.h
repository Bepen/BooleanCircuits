/*
CSC 173 Project 4
Created By Bepen Neupane and Sailesh Kaveti
NetID: bneupane skaveti

*/
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
struct SNAP** createSNAPTable();
int getSNAPHashKey(struct SNAP* snap);
void insertSNAPTuple(struct SNAP** snapTable, int studentID, char* name, char* address, char* phone);
void deleteSNAPTuple(struct SNAP** snapTable, int studentID, char* name, char* address, char* phone);
void printSNAPTable(struct SNAP** snapTable);

#endif
