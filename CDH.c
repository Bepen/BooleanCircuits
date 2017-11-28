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
      if (cdhTable[i]->next == NULL) {
        if (strcmp(cdhTable[i]->course, "") != 0) {
          printf("Course: %s. Day: %s. Hour: %s. Key %d\n", cdhTable[i]->course, cdhTable[i]->day, cdhTable[i]->hour, getHashKey(cdhTable[i]));
          continue;
        }
      }
      //cdhTable[i] = cdhTable[i]->next;
      while(cdhTable[i]->next!= NULL){
        if (strcmp(cdhTable[i]->course, "") == 0) {
          cdhTable[i] = cdhTable[i]->next;
        } else {
          printf("Course: %s. Day: %s. Hour: %s. Key %d\n", cdhTable[i]->course, cdhTable[i]->day, cdhTable[i]->hour, getHashKey(cdhTable[i]));
          cdhTable[i] = cdhTable[i]->next;
        }
        if (cdhTable[i]->next == NULL) {
          break;
        }
      }
    }
  }
}

void insertTuple(struct CDH** cdhTable, char* course, char* day, char* hour) {
  struct CDH* cdhTemp = newCDH(course, day, hour);
  int key = getHashKey(cdhTemp);
  if(cdhTable[key] == NULL) {
    //printf("Inserted\n");
    cdhTable[key] = cdhTemp;
  } else {
    while (cdhTable[key]->next != NULL) {
      if (strcmp(cdhTable[key]->course, course) == 0 && strcmp(cdhTable[key]->day, day) == 0 && strcmp(cdhTable[key]->hour, hour) == 0) {
        break;
      }
      cdhTable[key] = cdhTable[key]->next;
    }
  }

  if (strcmp(cdhTable[key]->course, course) != 0 || strcmp(cdhTable[key]->day, day) != 0 || strcmp(cdhTable[key]->hour, hour) != 0) {
    cdhTable[key]->next = cdhTemp;
  }
}

void lookup(struct CDH** cdhTable, char* course, char* day, char* hour) {
  struct CDH* cdhTemp = newCDH(course, day, hour);
  struct CDH** cdhTableTemp = createTable();
  int broke = 0;
  int key = getHashKey(cdhTemp);
  while(cdhTable[key] != NULL) {
    //printf("Key: %d\n", key);
    //printf("Course: %s. Day: %s. Hour: %s. Key %d\n", cdhTable[key]->course, cdhTable[key]->day, cdhTable[key]->hour, getHashKey(cdhTable[key]));
    //printf("%s \n", cdhTable[key]->hour);
    if (strcmp(cdhTable[key]->course, course) == 0 && strcmp(cdhTable[key]->day, day) == 0) {
      insertTuple(cdhTableTemp, cdhTable[key]->course, cdhTable[key]->day, cdhTable[key]->hour);
      break;
      broke = 1;
    } else {
      //printf("Reaches Here");
      cdhTable[key] = cdhTable[key]->next;
    }
    //cdhTable[key] = cdhTable[key]->next;
  }
  printTable(cdhTableTemp);
}

int main(int argc, char* argv[]) {
  struct CDH** cdhTable = createTable();
  insertTuple(cdhTable, "CS101", "M", "9AM");
  insertTuple(cdhTable, "CS101", "M", "9AM");
  insertTuple(cdhTable, "CS101", "W", "9AM");
  insertTuple(cdhTable, "CS101", "F", "9AM");
  insertTuple(cdhTable, "EE200", "Tu", "10AM");
  insertTuple(cdhTable, "EE200", "Tu", "11AM");
  insertTuple(cdhTable, "EE200", "W", "1PM");
  insertTuple(cdhTable, "EE200", "Th", "10AM");
  insertTuple(cdhTable, "PSY101", "M", "9AM");
  insertTuple(cdhTable, "STT213", "M", "9AM");
  deleteTuple(cdhTable, "PSY101", "M", "9AM");
  deleteTuple(cdhTable, "STT213", "M", "9AM");
  printTable(cdhTable);
  printf("lookup********\n");
  lookup(cdhTable, "EE200", "Tu", "*");
}
