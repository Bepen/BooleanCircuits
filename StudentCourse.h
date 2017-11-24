#ifndef _StudentCourse_h_gf
#define _StudentCourse_h_gf
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

struct CSG {
  char* course;
  int studentID;
  char* grade;
  struct CSG* next;
};

struct SNAP* newSNAP(int studentID, char* name, char* address, char* phone);
struct SNAP** createSNAPTable();
struct CSG* newCSG(char* course, int studentID, char* grade);
struct CSG** createCSGTable();
int getSNAPHashKey(struct SNAP* snap);
void insertSNAPTuple(struct SNAP** snapTable, int studentID, char* name, char* address, char* phone);
void deleteSNAPTuple(struct SNAP** snapTable, int studentID, char* name, char* address, char* phone);
void printSNAPTable(struct SNAP** snapTable);
void lookupSNAP(struct SNAP** snapTable, int studentID, char* name, char* address, char* phone);
int getCSGHashKey(struct CSG* csg);
void insertCSGTuple(struct CSG** csgTable, char* course, int studentID, char* grade);
void deleteCSGTuple(struct CSG** csgTable, char* course, int studentID, char* grade);
void printCSGTable(struct CSG** csgTable);
void lookupCSG(struct CSG** csgTable, char* course, int studentID, char* grade);


#endif
