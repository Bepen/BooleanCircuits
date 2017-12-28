/*
CSC 173 Project 4
Created By Bepen Neupane and Sailesh Kaveti
NetID: bneupane skaveti

*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "CP.h"

struct CP* newCP(char* course, char* preReq){
  struct CP *cp = malloc(sizeof(struct CP));
  cp->course = (char*)malloc(sizeof(char) * (6));
  cp->preReq = (char*)malloc(sizeof(char) * (3));
  strcpy(cp->course, course);
  strcpy(cp->preReq, preReq);
  cp->next = NULL;
  return cp;
}

struct CP** createCPTable() {
  struct CP** cpTab = malloc(1009*sizeof(struct CP));
  return cpTab;
}

int getCPKey(struct CP* cp) {
  int key = 0;
	int l = strlen(cp->course);
	for(int i=0; i < l; i++) {
		key += cp->course[i];
	}
	l = strlen(cp->preReq);
	for(int i = 0; i < l; i++) {
		key += cp->preReq[i];
	}
	key *= 997;
    return key%1009;
}

void insertCPTuple(struct CP** cpTable, char* course, char* preReq) {
  struct CP* cpTemp = newCP(course, preReq);
  int key = getCPKey(cpTemp);
  if (cpTable[key] == NULL) {
    cpTable[key] = cpTemp;
  } else {
    while(cpTable[key]->next != NULL){
      if (strcmp(cpTable[key]->course, course) == 0 && strcmp(cpTable[key]->preReq, preReq) == 0) {
        break;
      }
      cpTable[key] = cpTable[key]->next;
    }
    if (strcmp(cpTable[key]->course, course) != 0 || strcmp(cpTable[key]->preReq, preReq) != 0) {
      cpTable[key]->next = cpTemp;
    }
  }
}

void deleteCPTuple(struct CP** cpTable, char* course, char* preReq) {
  struct CP* cpFiller = newCP("", "");
  struct CP* cpTemp = newCP(course, preReq);
  if (strcmp(preReq, "*") == 0) {
    for (int i = 0; i < 1009; i++) {
      if (cpTable[i] == NULL) {
        //printf("%d\n", i);
        continue;
      }
      if (strcmp(cpTable[i]->course, course) == 0) {
        cpTable[i] = cpFiller;
      }
      while(cpTable[i]->next != NULL) {
        if (strcmp(cpTable[i]->course, course) == 0) {
          cpTable[i] = cpFiller;
        } else {
          cpTable[i] = cpTable[i]->next;
        }
      }
      if (strcmp(cpTable[i]->course, course) == 0) {
        cpTable[i] = cpFiller;
      }
    }
  } else {
    int key = getCPKey(cpTemp);
    if (cpTable[key] == NULL) {
      return;
    }
    while (cpTable[key]->next != NULL) {
      if (strcmp(cpTable[key]->course, course) == 0 && strcmp(cpTable[key]->preReq, preReq) == 0) {
        cpTable[key] = cpFiller;
      } else {
        cpTable[key] = cpTable[key]->next;
      }
    }
    if (strcmp(cpTable[key]->course, course) == 0 && strcmp(cpTable[key]->preReq, preReq) == 0) {
      cpTable[key] = cpFiller;
    }
  }
}

void printCPTable(struct CP** cpTable) {
  for (int i = 0; i < 1009; i++) {
    if (cpTable[i] != NULL) {
      if (strcmp(cpTable[i]->course, "") != 0) {
        printf("Course: %s  Prerequisite: %s  \n", cpTable[i]->course, cpTable[i]->preReq);
      }
      while(cpTable[i]->next != NULL){
        if (strcmp(cpTable[i]->course, "") == 0) {
          cpTable[i] = cpTable[i]->next;
        } else {
          cpTable[i] = cpTable[i]->next;
          printf("Course: %s  Prerequisite: %s  \n", cpTable[i]->course, cpTable[i]->preReq);
        }
        if (cpTable[i]->next == NULL) {
          break;
        }
      }
    }
  }
}

void lookupCP(struct CP** cpTable, char* course, char* preReq) {
  struct CP* cpTemp = newCP(course, preReq);
  struct CP** cpTempTable = createCPTable();
  int key = getCPKey(cpTemp);
  if (cpTable[key] == NULL) {
    return;
  }
  while (cpTable[key]->next != NULL) {
    if (strcmp(cpTable[key]->course, course) == 0 && strcmp(cpTable[key]->preReq, preReq) == 0) {
      insertCPTuple(cpTempTable, course, preReq);
      break;
    } else {
      cpTable[key] = cpTable[key]->next;
    }
  }
  if (strcmp(cpTable[key]->course, course) == 0 && strcmp(cpTable[key]->preReq, preReq) == 0) {
    insertCPTuple(cpTempTable, course, preReq);
  }
  printCPTable(cpTempTable);
}


void runCP() {
  /*
  struct CP* cpTemp = newCP("coolg", "hehex");
  printf("%d", getCPKey(cpTemp));
  */
  struct CP** cpTable = createCPTable();
  printf("\nRunning CP Relation***********************\n");
  printf("Inserting 10 different tuples: \n");
  printf("CS101's prerequisite is CS100 \n");
  printf("EE200's prerequisite is EE005 \n");
  printf("EE200's prerequisite is CS100 \n");
  printf("CS120's prerequisite is CS101 \n");
  printf("CS121's prerequisite is CS120 \n");
  printf("CS205's prerequisite is CS101 \n");
  printf("CS205's prerequisite is CS120 \n");
  printf("CS206's prerequisite is CS121 \n");
  printf("CS206's prerequisite is CS205 \n");
  printf("CS120's prerequisite is CS101 \n");
  insertCPTuple(cpTable, "CS101", "CS100");
  insertCPTuple(cpTable, "EE200", "EE005");
  insertCPTuple(cpTable, "EE200", "CS100");
  insertCPTuple(cpTable, "CS120", "CS101");
  insertCPTuple(cpTable, "CS121", "CS120");
  insertCPTuple(cpTable, "CS205", "CS101");
  insertCPTuple(cpTable, "CS205", "CS120");
  insertCPTuple(cpTable, "CS206", "CS121");
  insertCPTuple(cpTable, "CS206", "CS205");
  insertCPTuple(cpTable, "CS120", "CS101");
  printf("Delete all CS120 courses:\n");
  deleteCPTuple(cpTable, "CS120", "*");
  printf("Delete EE200 with prerequisite CS100:\n");
  deleteCPTuple(cpTable, "EE200", "CS100");
  printf("Looking for course CS101 with prerequisite of CS100:\n");
  lookupCP(cpTable, "CS101", "CS100");
  printf("\nPrinting CP Table:\n");
  printCPTable(cpTable);
  printf("Ending CP Relation***********************\n");

}
