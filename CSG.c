#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "CSG.h"

struct CSG* newCSG(char* course, int studentID, char* grade){
  struct CSG *csg = malloc(sizeof(struct CSG));
  csg->course = (char*)malloc(sizeof(char) * (6));
  csg->grade = (char*)malloc(sizeof(char) * (3));
  strcpy(csg->course, course);
  strcpy(csg->grade, grade);
  csg->studentID = studentID;
  csg->next = NULL;
  return csg;
}

struct CSG** createTable() {
  struct CSG** csgTab = malloc(1009*sizeof(struct CSG));
  return csgTab;
}

int getHashKey(struct CSG* csg) {
  return csg->studentID % 1009;
}

void insertTuple(struct CSG** csgTable, char* course, int studentID, char* grade) {
  struct CSG* csgTemp = newCSG(course, studentID, grade);
  int key = getHashKey(csgTemp);
  if(csgTable[key] == NULL){
    csgTable[key] = csgTemp;
    //printf("hello");
  } else{
    while(csgTable[key]->next != NULL){
      csgTable[key] = csgTable[key]->next;
    }
    csgTable[key]->next = csgTemp;
  }
  //csgTable[key] = csgTemp;
}

void deleteTuple(struct CSG** csgTable, char* course, int studentID, char* grade) {
  struct CSG* csgTemp = newCSG(course, studentID, grade);
  char string[50];
  sprintf(string, "%d", studentID);
  char* idString = string;
  //all three defined
  if (strcmp(course, "*") != 0 && strcmp(idString, "*") != 0 && strcmp(grade, "*") != 0) {
    int key = getHashKey(csgTemp);
    while(csgTable[key]->next != NULL) {
      if (strcmp(csgTable[key]->course, course) == 0 && strcmp(csgTable[key]->grade, grade) == 0 && csgTable[key]->studentID == studentID) {
        //printf("Reaches Here");
        csgTable[key] = csgTable[key]->next;
        break;
      } else {
        printf("Reaches Here");
        csgTable[key]->next = csgTable[key];
      }
    }
  }
}


void printTable(struct CSG** csgTable) {
  for (int i = 0; i < 1009; i++) {
    if (csgTable[i] != NULL) {
      printf("Course: %s. Student ID: %d. Grade: %s. Key %d\n", csgTable[i]->course, csgTable[i]->studentID, csgTable[i]->grade, getHashKey(csgTable[i]));
      while(csgTable[i]->next != NULL){
        csgTable[i] = csgTable[i]->next;
        printf("Course: %s. Student ID: %d. Grade: %s, Key: %d\n", csgTable[i]->course, csgTable[i]->studentID, csgTable[i]->grade, getHashKey(csgTable[i]));
        if (csgTable[i]->next == NULL) {
          break;
        }
      }
    }
  }
}

int main(int argc, char* argv[]) {
  struct CSG** csgTable = createTable();
  insertTuple(csgTable, "CSC101", 12345, "A");
  insertTuple(csgTable, "CSC101", 67890, "B");
  insertTuple(csgTable, "EE200", 12345, "C");
  insertTuple(csgTable, "EE200", 22222, "B+");
  insertTuple(csgTable, "CSC101", 33333, "A-");
  insertTuple(csgTable, "PH100", 67890, "C+");
  deleteTuple(csgTable, "EE200", 12345, "C");
  printTable(csgTable);
}
