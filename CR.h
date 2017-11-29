/*
CSC 173 Project 4
Created By Bepen Neupane and Sailesh Kaveti
NetID: bneupane skaveti
*/
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

struct CR** createCRTable();
int getCRKey(struct CR* cr);
void insertCRTuple(struct CR** crTable, char* course, char* room);
void deleteCRTuple(struct CR** crTable, char* course, char* room);
void printCRTable(struct CR** crTable);
void lookupCR(struct CR** crTable, char* course, char* room);

#endif
