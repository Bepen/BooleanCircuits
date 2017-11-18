//test2
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
}

void deleteTuple(struct CDH** cdhTable, char* course, char* day, char* hour){
  struct CDH* cdhTemp = newCDH(course, day, hour);
  struct CDH* cdhFiller = newCDH("", "", "");
  if (strcmp(course, "*") != 0 && strcmp(day, "*") != 0 && strcmp(hour, "*") != 0) {
    int key = getHashKey(cdhTemp);
    if (strcmp(cdhTable[key]->course, course) == 0 && strcmp(cdhTable[key]->day, day) == 0 && strcmp(cdhTable[key]->hour, hour) == 0) {
      cdhTable[key] = cdhFiller;
    }
    while(cdhTable[key]->next != NULL) {
      if (strcmp(cdhTable[key]->course, course) == 0 && strcmp(cdhTable[key]->day, day) == 0 && strcmp(cdhTable[key]->hour, hour) == 0) {
        cdhTable[key] = cdhFiller;
        break;
      } else {
        cdhTable[key] = cdhTable[key]->next;
      }
    }
  }
}

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
  insertTuple(cdhTable, "PSY101", "M", "9AM");
  deleteTuple(cdhTable, "PSY101", "M", "9AM");
  insertTuple(cdhTable, "STT213", "M", "9AM");
  deleteTuple(cdhTable, "STT213", "M", "9AM");
  printTable(cdhTable);
}
