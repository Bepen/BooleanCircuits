#ifndef _NameTimeDay_h_gf
#define _NameTimeDay_h_gf
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

struct CDH {
  char* course;
  char* day;
  char* hour;
  struct CDH* next;
};

struct CR {
  char* course;
  char* room;
  struct CR* next;
};

struct SNAP* newSNAP(int studentID, char* name, char* address, char* phone);
struct SNAP** createSNAPTable();
int getSNAPHashKey(struct SNAP* snap);
void insertSNAPTuple(struct SNAP** snapTable, int studentID, char* name, char* address, char* phone);
void deleteSNAPTuple(struct SNAP** snapTable, int studentID, char* name, char* address, char* phone);
void printSNAPTable(struct SNAP** snapTable);
struct SNAP** lookupSNAP(struct SNAP** snapTable, int studentID, char* name, char* address, char* phone);

struct CSG* newCSG(char* course, int studentID, char* grade);
struct CSG** createCSGTable();
int getCSGHashKey(struct CSG* csg);
void insertCSGTuple(struct CSG** csgTable, char* course, int studentID, char* grade);
void deleteCSGTuple(struct CSG** csgTable, char* course, int studentID, char* grade);
void printCSGTable(struct CSG** csgTable);
struct CSG** lookupCSG(struct CSG** csgTable, char* course, int studentID, char* grade);

struct CDH* newCDH(char* course, char* day, char* hour);
struct CDH** createCDHTable();
int getCDHHashKey(struct CDH* cdh);
void deleteCDHTuple(struct CDH** cdhTable, char* course, char* day, char* hour);
void printCDHTable(struct CDH** cdhTable);
void insertCDHTuple(struct CDH** cdhTable, char* course, char* day, char* hour);
struct CDH** lookupCDH(struct CDH** cdhTable, char* course, char* day, char* hour);

struct CR* newCR(char* course, char* room);
struct CR** createCRTable();
int getCRKey(struct CR* cr);
void insertCRTuple(struct CR** crTable, char* course, char* room);
void deleteCRTuple(struct CR** crTable, char* course, char* room);
void printCRTable(struct CR** crTable);
struct CR** lookupCR(struct CR** crTable, char* course, char* room);

#endif
