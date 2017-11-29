/*
CSC 173 Project 4
Created By Bepen Neupane and Sailesh Kaveti
NetID: bneupane skaveti
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "SNAP.h"

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

struct SNAP** createSNAPTable() {
  struct SNAP** snapTab = malloc(1009*sizeof(struct SNAP));
  return snapTab;
}

int getSNAPHashKey(struct SNAP* snap) {
  return snap->studentID % 1009;
}

void insertSNAPTuple(struct SNAP** snapTable, int studentID, char* name, char* address, char* phone) {
  struct SNAP* snapTemp = newSNAP(studentID, name, address, phone);
  int key = getSNAPHashKey(snapTemp);
  if(snapTable[key] == NULL) {
    //printf("Inserted\n");
    snapTable[key] = snapTemp;
  } else {
    while (snapTable[key]->next != NULL) {
      if (snapTable[key]->studentID == studentID && strcmp(snapTable[key]->name, name) == 0 && strcmp(snapTable[key]->address, address) == 0 && strcmp(snapTable[key]->phone, phone) == 0) {
        break;
      }
      snapTable[key] = snapTable[key]->next;
    }
  }

  if (snapTable[key]->studentID != studentID || strcmp(snapTable[key]->name, name) != 0 || strcmp(snapTable[key]->address, address) != 0 || strcmp(snapTable[key]->phone, phone) != 0) {
    snapTable[key]->next = snapTemp;
  }
}

void deleteSNAPTuple(struct SNAP** snapTable, int studentID, char* name, char* address, char* phone) {
  struct SNAP* snapTemp = newSNAP(studentID, name, address, phone);
  struct SNAP* snapFiller = newSNAP(0, "", "", "");
  if (studentID != 0 && strcmp(name, "*") != 0 && strcmp(address, "*") != 0 && strcmp(phone, "*") != 0) {
    int key = getSNAPHashKey(snapTemp);
    if (strcmp(snapTable[key]->name, name) == 0 && strcmp(snapTable[key]->address, address) == 0 && snapTable[key]->studentID == studentID && strcmp(snapTable[key]->phone, phone) == 0) {
      //printf("Reaches Here");
      snapTable[key] = snapFiller;
    }
    while(snapTable[key]->next != NULL) {
      if (strcmp(snapTable[key]->name, name) == 0 && strcmp(snapTable[key]->address, address) == 0 && snapTable[key]->studentID == studentID && strcmp(snapTable[key]->phone, phone) == 0) {
        //printf("Reaches Here");
        snapTable[key] = snapFiller;
        break;
      } else {
        //printf("Reaches Here");
        snapTable[key] = snapTable[key]->next;
      }
    }
    if (strcmp(snapTable[key]->name, name) == 0 && strcmp(snapTable[key]->address, address) == 0 && snapTable[key]->studentID == studentID && strcmp(snapTable[key]->phone, phone) == 0) {
      //printf("Reaches Here");
      snapTable[key] = snapFiller;
    }
  }
}


void printSNAPTable(struct SNAP** snapTable) {
  for (int i = 0; i < 1009; i++) {
    if (snapTable[i] != NULL) {
      while(snapTable[i] != NULL){
        //printf("Index: %d\n", i);
        if (snapTable[i]->studentID == 0) {
          //printf("Reaches Filler\n");
          snapTable[i] = snapTable[i]->next;
        }
        else {
          //printf("Else Statement\n");
          printf("Student ID: %d  Name: %s  Address: %s  Phone: %s\n", snapTable[i]->studentID, snapTable[i]->name, snapTable[i]->address, snapTable[i]->phone);
          snapTable[i] = snapTable[i]->next;
        }
        if (snapTable[i] == NULL) {
          //printf("NULL Reached");
          break;
        }
      }
    }
  }
}

void lookupSNAP(struct SNAP** snapTable, int studentID, char* name, char* address, char* phone) {
  //struct SNAP* snapTemp = newSNAP(studentID, name, address, phone);
  struct SNAP** snapTableTemp = createSNAPTable();
  //Only Name is defined
  if (studentID == 0 && strcmp(address, "*") == 0 && strcmp(phone, "*") == 0) {
    //printf("Enters\n");
    for (int i = 0; i < 1009; i++) {
      if (snapTable[i] != NULL) {
        //printf("Enters at %d:\n", i);
        while(snapTable[i] != NULL) {
          if (strcmp(snapTable[i]->name, name) == 0) {
            insertSNAPTuple(snapTableTemp, snapTable[i]->studentID, snapTable[i]->name, snapTable[i]->address, snapTable[i]->phone);
            break;
          } else {
            snapTable[i] = snapTable[i]->next;
          }
          if (snapTable[i] == NULL) {
            //printf("NULL Reached");
            break;
          }
        }
      }
    }
  }
  printSNAPTable(snapTable);
}

void runSNAP() {
  struct SNAP** snapTable = createSNAPTable();
  struct SNAP** snapTable2 = createSNAPTable();
  printf("\nRunning SNAP Relation***********************\n");
  printf("Inserting 3 different tuples: \n");
  printf("C. Brown with student ID 12345 from 12 Apple St. 555-1234\n");
  printf("L.Van Pelt with student ID 67890 from 34 Pear Ave. 555-5678\n");
  printf("P. Patty with student ID 22222 from 56 Grape Blvd. 555-9999\n");
  insertSNAPTuple(snapTable, 12345, "C. Brown", "12 Apple St.", "555-1234");
  insertSNAPTuple(snapTable, 67890, "L. Van Pelt", "34 Pear Ave.", "555-5678");
  insertSNAPTuple(snapTable, 22222, "P. Patty", "56 Grape Blvd.", "555-9999");
  printf("Deleting P. Patty's information\n");
  deleteSNAPTuple(snapTable, 22222, "P. Patty", "56 Grape Blvd.", "555-9999");
  //testing snapTable, remove before submission
  insertSNAPTuple(snapTable2, 12345, "C. Brown", "12 Apple St.", "555-1234");
  printf("Looking up the address and phone number for C.Brown using Student ID:\n");
  lookupSNAP(snapTable2, 12345, "C. Brown", "*", "*");
  printf("\nPrinting SNAP Table:\n");
  printSNAPTable(snapTable);
  printf("Ending SNAP Relation***********************\n\n");
}
