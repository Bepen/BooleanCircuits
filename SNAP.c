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

void insertTuple(struct SNAP** snap, int studentID, char* name, char* address, char* phone) {
  
}
