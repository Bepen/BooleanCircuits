#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "CP.h"

struct SNAP* newSNAP(int studentID, char* name, char* address, char* phone) {
  struct SNAP *snap = malloc(sizeof(struct SNAP));
  snap->name = (char*)malloc(sizeof(char) * (15));
  snap->address = (char*)malloc(sizeof(char) * (20));
  snap->phone = (char*)malloc(sizeof(char) * (20));
  strcpy(snap->name, name);
  strcpy(snap->address, address);
  strcpy(snap->phone, phone);
  snap->studentID = studentID;
  snap->next = NULL;
  return snap;
}

struct SNAP** createSnap() {
  struct SNAP** snapTab = malloc(1009*sizeof(struct CSG));
  return snapTab;
}

int getHashKey(struct SNAP* snap) {
  return snap->studentID % 1009;
}

void insertTuple(struct SNAP** snapTable, int studentID, char* name, char* address, char* phone) {
  struct SNAP* snapTemp = newSNAP(studentID, name, address, phone);
  int key = getHashKey(csgTemp);
  if(csgTable[key] == NULL) {
    csgTable[key] = csgTemp;
  } else {
    while (snapTable[key]->next != NULL) {
      if (snapTable[key]->studentID == studentID && strcmp(snapTable[key]->name, name) == 0 && strcmp(snapTable[key]->address, address) == 0 && strcmp(snapTable[key]->phone, phone) == 0) {
        break;
      }
      snapTable[key] = snapTable[key]->next;
    }
  }
  if (snapTable[key]->studentID == studentID && strcmp(snapTable[key]->name, name) == 0 && strcmp(snapTable[key]->address, address) == 0 && strcmp(snapTable[key]->phone, phone) == 0) {
    snapTable[key]->next = snapTemp;
  }
}

void printTable(struct SNAP** snapTable) {

}
