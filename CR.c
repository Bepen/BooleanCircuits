/*
CSC 173 Project 4
Created By Bepen Neupane and Sailesh Kaveti
NetID: bneupane skaveti

*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "CR.h"

struct CR* newCR(char* course, char* room){
  struct CR *cr = malloc(sizeof(struct CR));
  cr->course = (char*)malloc(sizeof(char) * (6));
  cr->room = (char*)malloc(sizeof(char) * (50));
  strcpy(cr->course, course);
  strcpy(cr->room, room);
  cr->next = NULL;
  return cr;
}

struct CR** createCRTable() {
  struct CR** crTab = malloc(1009*sizeof(struct CR));
  return crTab;
}

int getCRKey(struct CR* cr) {
  int key = 0;
	int l = strlen(cr->course);
	for(int i=0; i < l; i++) {
		key += cr->course[i];
	}
	l = strlen(cr->room);
	for(int i = 0; i < l; i++) {
		key += cr->room[i];
	}
	key *= 997;
    return key%1009;
}

void insertCRTuple(struct CR** crTable, char* course, char* room) {
  struct CR* crTemp = newCR(course, room);
  int key = getCRKey(crTemp);
  if (crTable[key] == NULL) {
    crTable[key] = crTemp;
  } else {
    while(crTable[key]->next != NULL){
      if (strcmp(crTable[key]->course, course) == 0 && strcmp(crTable[key]->room, room) == 0) {
        break;
      }
      crTable[key] = crTable[key]->next;
    }
    if (strcmp(crTable[key]->course, course) != 0 || strcmp(crTable[key]->room, room) != 0) {
      crTable[key]->next = crTemp;
    }
  }
}

void deleteCRTuple(struct CR** crTable, char* course, char* room) {
  struct CR* crFiller = newCR("", "");
  struct CR* crTemp = newCR(course, room);
  if (strcmp(room, "*") == 0) {
    for (int i = 0; i < 1009; i++) {
      if (crTable[i] == NULL) {
        //printf("%d\n", i);
        continue;
      }
      if (strcmp(crTable[i]->course, course) == 0) {
        crTable[i] = crFiller;
      }
      while(crTable[i]->next != NULL) {
        if (strcmp(crTable[i]->course, course) == 0) {
          crTable[i] = crFiller;
        } else {
          crTable[i] = crTable[i]->next;
        }
      }
      if (strcmp(crTable[i]->course, course) == 0) {
        crTable[i] = crFiller;
      }
    }
  } else {
    int key = getCRKey(crTemp);
    if (crTable[key] == NULL) {
      return;
    }
    while (crTable[key]->next != NULL) {
      if (strcmp(crTable[key]->course, course) == 0 && strcmp(crTable[key]->room, room) == 0) {
        crTable[key] = crFiller;
      } else {
        crTable[key] = crTable[key]->next;
      }
    }
    if (strcmp(crTable[key]->course, course) == 0 && strcmp(crTable[key]->room, room) == 0) {
      crTable[key] = crFiller;
    }
  }
}

void printCRTable(struct CR** crTable) {
  for (int i = 0; i < 1009; i++) {
    if (crTable[i] != NULL) {
      if (strcmp(crTable[i]->course, "") != 0) {
        printf("Course: %s  Room: %s  \n", crTable[i]->course, crTable[i]->room);
      }
      while(crTable[i]->next != NULL){
        if (strcmp(crTable[i]->course, "") == 0) {
          crTable[i] = crTable[i]->next;
        } else {
          crTable[i] = crTable[i]->next;
          printf("Course: %s  Room: %s  \n", crTable[i]->course, crTable[i]->room);
        }
        if (crTable[i]->next == NULL) {
          break;
        }
      }
    }
  }
}

void lookupCR(struct CR** crTable, char* course, char* room) {
  struct CR* crTemp = newCR(course, room);
  struct CR** crTempTable = createCRTable();
  int key = getCRKey(crTemp);
  if (crTable[key] == NULL) {
    //printf("NULL\n");
    return;
  }
  while (crTable[key]->next != NULL) {
    if (strcmp(crTable[key]->course, course) == 0 && strcmp(crTable[key]->room, room) == 0) {
      insertCRTuple(crTempTable, course, room);
      break;
    } else {
      crTable[key] = crTable[key]->next;
    }
  }
  if (strcmp(crTable[key]->course, course) == 0 && strcmp(crTable[key]->room, room) == 0) {
    insertCRTuple(crTempTable, course, room);
  }
  printCRTable(crTempTable);
}


void runCR() {
  struct CR** crTable = createCRTable();
  printf("\nRunning CR Relation***********************\n");
  printf("Inserting 3 different tuples: \n");
  printf("CS101 takes place in Turing Aud.\n");
  printf("EE200 takes place in 25 Ohm Hall\n");
  printf("PH100 takes place in Newton Lab\n");
  insertCRTuple(crTable, "CS101", "Turing Aud.");
  insertCRTuple(crTable, "EE200", "25 Ohm Hall");
  insertCRTuple(crTable, "PH100", "Newton Lab");
  printf("Deleting Tuple with EE200 in 25 Ohm Hall\n");
  deleteCRTuple(crTable, "EE200", "25 Ohm Hall");
  printf("Lookup CSC101 in Turing Aud.:\n");
  lookupCR(crTable, "CS101", "Turing Aud.");
  printf("\nPrinting CR Table:\n");
  printCRTable(crTable);
  //struct CR* cr = newCR("CS101", "Turing Aud");
  //printf("%d\n", getCRKey(cr));
  printf("Ending CR Relation***********************\n\n");
}
