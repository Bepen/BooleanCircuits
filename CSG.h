/*
CSC 173 Project 4
Created By Bepen Neupane and Sailesh Kaveti
NetID: bneupane skaveti
*/
#ifndef _CSG_h_gf
#define _CSG_h_gf
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct CSG {
  char* course;
  int studentID;
  char* grade;
  struct CSG* next;
};

struct CSG* newCSG(char* course, int studentID, char* grade);
struct CSG** createCSGTable();
int getCSGHashKey(struct CSG* csg);
void insertCSGTuple(struct CSG** csgTable, char* course, int studentID, char* grade);
void deleteCSGTuple(struct CSG** csgTable, char* course, int studentID, char* grade);
void printCSGTable(struct CSG** csgTable);
void lookupCSG(struct CSG** csgTable, char* course, int studentID, char* grade);
void runCSG();
#endif
