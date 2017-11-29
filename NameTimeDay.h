#ifndef _NameTimeDay_h_gf
#define _NameTimeDay_h_gf
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct SNAPNTD {
  char* name;
  int studentID;
  char* address;
  char* phone;
  struct SNAPNTD* next;
};

struct CSGNTD {
  char* course;
  int studentID;
  char* grade;
  struct CSGNTD* next;
};

struct CDHNTD {
  char* course;
  char* day;
  char* hour;
  struct CDHNTD* next;
};

struct CRNTD {
  char* course;
  char* room;
  struct CRNTD* next;
};

struct SNAPNTD* newSNAPNTD(int studentID, char* name, char* address, char* phone);
struct SNAPNTD** createSNAPNTDTable();
int getSNAPNTDHashKey(struct SNAPNTD* snap);
void insertSNAPNTDTuple(struct SNAPNTD** snapTable, int studentID, char* name, char* address, char* phone);
void deleteSNAPNTDTuple(struct SNAPNTD** snapTable, int studentID, char* name, char* address, char* phone);
void printSNAPNTDTable(struct SNAPNTD** snapTable);
struct SNAPNTD** lookupSNAPNTD(struct SNAPNTD** snapTable, int studentID, char* name, char* address, char* phone);

struct CSGNTD* newCSGNTD(char* course, int studentID, char* grade);
struct CSGNTD** createCSGNTDTable();
int getCSGNTDHashKey(struct CSGNTD* csg);
void insertCSGNTDTuple(struct CSGNTD** csgTable, char* course, int studentID, char* grade);
void deleteCSGNTDTuple(struct CSGNTD** csgTable, char* course, int studentID, char* grade);
void printCSGNTDTable(struct CSGNTD** csgTable);
struct CSGNTD** lookupCSGNTD(struct CSGNTD** csgTable, char* course, int studentID, char* grade);

struct CDHNTD* newCDHNTD(char* course, char* day, char* hour);
struct CDHNTD** createCDHNTDTable();
int getCDHNTDHashKey(struct CDHNTD* cdh);
void deleteCDHNTDTuple(struct CDHNTD** cdhTable, char* course, char* day, char* hour);
void printCDHNTDTable(struct CDHNTD** cdhTable);
void insertCDHNTDTuple(struct CDHNTD** cdhTable, char* course, char* day, char* hour);
struct CDHNTD** lookupCDHNTD(struct CDHNTD** cdhTable, char* course, char* day, char* hour);

struct CRNTD* newCRNTD(char* course, char* room);
struct CRNTD** createCRNTDTable();
int getCRNTDKey(struct CRNTD* cr);
void insertCRNTDTuple(struct CRNTD** crTable, char* course, char* room);
void deleteCRNTDTuple(struct CRNTD** crTable, char* course, char* room);
void printCRNTDTable(struct CRNTD** crTable);
struct CRNTD** lookupCRNTD(struct CRNTD** crTable, char* course, char* room);

#endif
