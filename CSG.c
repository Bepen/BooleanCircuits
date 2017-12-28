/*
CSC 173 Project 4
Created By Bepen Neupane and Sailesh Kaveti
NetID: bneupane skaveti

*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "CSG.h"

//creates the CSG tuple
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
//creates a table where CSG tuples are stored
struct CSG** createCSGTable() {
  struct CSG** csgTab = malloc(1009*sizeof(struct CSG));
  return csgTab;
}
//gets key for the tuple so the tuple can be placed in the correct bucket in the hash table
int getCSGHashKey(struct CSG* csg) {
  return csg->studentID % 1009;
}
//inserts tuple into the table
void insertCSGTuple(struct CSG** csgTable, char* course, int studentID, char* grade) {
  struct CSG* csgTemp = newCSG(course, studentID, grade);
  int key = getCSGHashKey(csgTemp);
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
//deletes tuple from the table
void deleteCSGTuple(struct CSG** csgTable, char* course, int studentID, char* grade) {
  struct CSG* csgTemp = newCSG(course, studentID, grade);
  struct CSG* csgFiller = newCSG("", 0, "");
  char string[50];
  sprintf(string, "%d", studentID);
  char* idString = string;
  //all three defined
  if (strcmp(course, "*") != 0 && strcmp(idString, "*") != 0 && strcmp(grade, "*") != 0) {
    //printf("Gets here");
    int key = getCSGHashKey(csgTemp);
    if (strcmp(csgTable[key]->course, course) == 0 && strcmp(csgTable[key]->grade, grade) == 0 && csgTable[key]->studentID == studentID) {
      //printf("Reaches Here");
      csgTable[key] = csgFiller;
    }
    while(csgTable[key]->next != NULL) {
      if (strcmp(csgTable[key]->course, course) == 0 && strcmp(csgTable[key]->grade, grade) == 0 && csgTable[key]->studentID == studentID) {
        //printf("Reaches Here");
        csgTable[key] = csgFiller;
        break;
      } else {
        //printf("Reaches Here");
        csgTable[key] = csgTable[key]->next;
      }
    }
  }
  //only studentID defined
  else if (strcmp(course, "*") == 0 && strcmp(grade, "*") == 0) {
    int key = getCSGHashKey(csgTemp);
    while(csgTable[key]->next != NULL) {
      if (csgTable[key]->studentID == studentID) {
        //printf("Reaches Here");
        csgTable[key] = csgFiller;
      } else {
        //printf("Reaches Here");
        csgTable[key] = csgTable[key]->next;
      }
    }
    if (csgTable[key]->studentID == studentID) {
      //printf("Reaches Here");
      csgTable[key] = csgFiller;
    }
  }

  //only course is defined
  else if (studentID == 0 && strcmp(grade, "*") == 0) {
    for (int i = 0; i < 1009; i++) {
      if (csgTable[i] == NULL) {
        //printf("%d\n", i);
        continue;
      }
      if (strcmp(csgTable[i]->course, course) == 0){
        csgTable[i] = csgFiller;
      }
      while(csgTable[i]->next != NULL) {
        //printf("%d\n", i);
        if (strcmp(csgTable[i]->course, course) == 0){
          csgTable[i] = csgFiller;
        } else {
          csgTable[i] = csgTable[i]->next;
        }
      }

      if (strcmp(csgTable[i]->course, course) == 0){
        csgTable[i] = csgFiller;
      }
    }
  }
}
//prints the CSG table
void printCSGTable(struct CSG** csgTable) {
  for (int i = 0; i < 1009; i++) {
    if (csgTable[i] != NULL) {
      if (strcmp(csgTable[i]->course, "") != 0) { //if the tuple isn't filled with empty strings, it will print
        printf("Course: %s  Student ID: %d  Grade: %s \n", csgTable[i]->course, csgTable[i]->studentID, csgTable[i]->grade);
      }
      while(csgTable[i]->next != NULL){
        if (strcmp(csgTable[i]->course, "") == 0) {//if the tuple isn't filled with empty strings, it will print
          csgTable[i] = csgTable[i]->next;
        } else {
          csgTable[i] = csgTable[i]->next;
          printf("Course: %s  Student ID: %d  Grade: %s  \n", csgTable[i]->course, csgTable[i]->studentID, csgTable[i]->grade);
        }

        if (csgTable[i]->next == NULL) {
          break;
        }
      }
    }
  }
}

//looks for tuples that match the condition given
void lookupCSG(struct CSG** csgTable, char* course, int studentID, char* grade) {
  struct CSG* csgTemp = newCSG(course, studentID, grade);
  struct CSG** csgTableTemp = createCSGTable();
  int key = getCSGHashKey(csgTemp);
  if (strcmp(course, "*") == 0 && strcmp(grade, "*") == 0) {
    while(csgTable[key] != NULL) {
      if (csgTable[key]->studentID == studentID) {
        //printf("Reaches Here");
        insertCSGTuple(csgTableTemp, csgTable[key]->course, csgTable[key]->studentID, csgTable[key]->grade);
        csgTable[key] = csgTable[key]->next;
      } else {
        //printf("Reaches Here");
        csgTable[key] = csgTable[key]->next;
      }
    }
  } else {
    while(csgTable[key]->next != NULL) {
      if (csgTable[key]->studentID == studentID && strcmp(csgTable[key]->course, course)) {
        //printf("Reaches Here");
        insertCSGTuple(csgTableTemp, csgTable[key]->course, csgTable[key]->studentID, csgTable[key]->grade);
        break;
      } else {
        //printf("Reaches Here");
        csgTable[key] = csgTable[key]->next;
      }
    }
  }
  printCSGTable(csgTableTemp);
}
//runs the CSG relation, called in main.c
void runCSG() {
  struct CSG** csgTable = createCSGTable();
  printf("\nRunning CSG Relation***********************\n");
  printf("Inserting 8 different tuples: \n");
  printf("A in CS101 for student 12345\n");
  printf("C in EE200 for student 12345\n");
  printf("D in EE200 for student 49192\n");
  printf("C- in PH100 for student 81824\n");
  printf("D+ in EN150 for student 20310\n");
  printf("B+ in EE200 for student 22222\n");
  printf("A- in CS101 for student 33333\n");
  printf("C+ in PH100 for student 67890\n");
  insertCSGTuple(csgTable, "CS101", 12345, "A");
  insertCSGTuple(csgTable, "EE200", 12345, "C");
  insertCSGTuple(csgTable, "EE200", 49192, "D");
  insertCSGTuple(csgTable, "PH100", 81824, "C-");
  insertCSGTuple(csgTable, "EN150", 20310, "D+");
  insertCSGTuple(csgTable, "EE200", 22222, "B+");
  insertCSGTuple(csgTable, "CS101", 33333, "A-");
  insertCSGTuple(csgTable, "PH100", 67890, "C+");
  printf("Looking up the grade for student in CSC101 with an ID of 12345:\n");
  lookupCSG(csgTable, "CSC101", 12345, "*");
  printf("Deleting the student 20310 in EN150 with a D+ \n");
  deleteCSGTuple(csgTable, "EN150", 20310, "D+");
  printf("Deleting the student 12345 \n");
  deleteCSGTuple(csgTable, "*", 12345, "*");
  printf("Deleting all of the students in PH100\n");
  deleteCSGTuple(csgTable, "PH100", 0, "*");
  printf("\nPrinting CSG Table:\n");
  printCSGTable(csgTable);
  printf("Ending CSG Relation***********************\n\n");
}
