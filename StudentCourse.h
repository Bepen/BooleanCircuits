#ifndef _StudentCourse_h_gf
#define _StudentCourse_h_gf
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct SNAPSC {
  char* name;
  int studentID;
  char* address;
  char* phone;
  struct SNAPSC* next;
};

struct CSGSC {
  char* course;
  int studentID;
  char* grade;
  struct CSGSC* next;
};

struct SNAPSC* newSNAPSC(int studentID, char* name, char* address, char* phone);
struct SNAPSC** createSNAPSCTable();
struct CSGSC* newCSGSC(char* course, int studentID, char* grade);
struct CSGSC** createCSGSCTable();
int getSNAPSCHashKey(struct SNAPSC* snap);
void insertSNAPSCTuple(struct SNAPSC** snapTable, int studentID, char* name, char* address, char* phone);
void deleteSNAPSCTuple(struct SNAPSC** snapTable, int studentID, char* name, char* address, char* phone);
void printSNAPSCTable(struct SNAPSC** snapTable);
struct SNAPSC** lookupSNAPSC(struct SNAPSC** snapTable, int studentID, char* name, char* address, char* phone);
int getCSGSCHashKey(struct CSGSC* csg);
void insertCSGSCTuple(struct CSGSC** csgTable, char* course, int studentID, char* grade);
void deleteCSGSCTuple(struct CSGSC** csgTable, char* course, int studentID, char* grade);
void printCSGSCTable(struct CSGSC** csgTable);
struct CSGSC** lookupCSGSC(struct CSGSC** csgTable, char* course, int studentID, char* grade);


#endif
