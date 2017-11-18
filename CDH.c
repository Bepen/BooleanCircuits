#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "CDH.h"

struct CDH* newCDH(char* course, char* day, char* hour){
  struct CDH *cdh = malloc(sizeof(struct CDH));
  cdh->course = (char*)malloc(sizeof(char) * (6));
  cdh->day = (char*)malloc(sizeof(char) * (2));
  cdh->hour = (char*)malloc(sizeof(char) * (4));
  strcpy(cdh->course, course);
  strcpy(cdh->day, day);
  strcpy(cdh->hour, hour);
  cdh->next = NULL;
  return cdh;
}

struct CDH** createTable() {
  struct CDH** cdhTab = malloc(1009*sizeof(struct CDH));
  return cdhTab;
}

int getHashKey(struct CDH* cdh) {
  int key = 0;
	int length = strlen(cdh->course);
	for(int i = 0; i < length; i++) {
		key += (int)cdh->course[i];
	}
  if(strcmp(cdh->day, "M") == 0){
    key *= 3;
  }
  if(strcmp(cdh->day, "Tu") == 0){
    key *= 5;
  }
  if(strcmp(cdh->day, "W") == 0){
    key *= 7;
  }
  if(strcmp(cdh->day, "Th") == 0){
    key *= 11;
  }
  if(strcmp(cdh->day, "F") == 0){
    key *= 13;
  }
  else{
    key *= 1;
  }
	key *= 997;
  return key % 1009;
}

void insertTuple(struct CDH** cdhTable, char* course, char* day, char* hour) {
  struct CDH* cdhTemp = newCDH(course, day, hour);
  int key = getHashKey(cdhTemp);
  if(cdhTable[key] == NULL){
    cdhTable[key] = cdhTemp;
    //printf("hello");
  } else{
    while(cdhTable[key]->next != NULL){
      cdhTable[key] = cdhTable[key]->next;
    }
    cdhTable[key]->next = cdhTemp;
  }
  //csgTable[key] = csgTemp;
}
/*
void deleteTuple(struct CSG** csgTable, char* course, int studentID, char* grade) {
  struct CSG* csgTemp = newCSG(course, studentID, grade);
  struct CSG* csgFiller = newCSG("", 0, "");
  char string[50];
  sprintf(string, "%d", studentID);
  char* idString = string;
  //all three defined
  if (strcmp(course, "*") != 0 && strcmp(idString, "*") != 0 && strcmp(grade, "*") != 0) {
    //printf("Gets here");
    int key = getHashKey(csgTemp);
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
    int key = getHashKey(csgTemp);
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
}
*/

void printTable(struct CDH** cdhTable) {
  for (int i = 0; i < 1009; i++) {
    if (cdhTable[i] != NULL) {
      if (strcmp(cdhTable[i]->course, "") != 0) {
        printf("Course: %s. Day: %s. Hour: %s. Key %d\n", cdhTable[i]->course, cdhTable[i]->day, cdhTable[i]->hour, getHashKey(cdhTable[i]));
      }
      while(cdhTable[i]->next != NULL){
        if (strcmp(cdhTable[i]->course, "") == 0) {
          cdhTable[i] = cdhTable[i]->next;
        } else {
          cdhTable[i] = cdhTable[i]->next;
          printf("Course: %s. Day: %s. Hour: %s. Key %d\n", cdhTable[i]->course, cdhTable[i]->day, cdhTable[i]->hour, getHashKey(cdhTable[i]));
        }

        if (cdhTable[i]->next == NULL) {
          break;
        }
      }
    }
  }
}

int main(int argc, char* argv[]) {
  struct CDH** cdhTable = createTable();
  insertTuple(cdhTable, "CS101", "M", "9AM");
  insertTuple(cdhTable, "CS101", "W", "9AM");
  insertTuple(cdhTable, "CS101", "F", "9AM");
  insertTuple(cdhTable, "EE200", "Tu", "10AM");
  insertTuple(cdhTable, "EE200", "W", "1PM");
  insertTuple(cdhTable, "EE200", "Th", "10AM");
  printTable(cdhTable);
}
