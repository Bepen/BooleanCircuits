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

struct CR** createTable() {
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

void insertTuple(struct CR** crTable, char* course, char* room) {
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

void printTable(struct CR** crTable) {
  for (int i = 0; i < 1009; i++) {
    if (crTable[i] != NULL) {
      if (strcmp(crTable[i]->course, "") != 0) {
        printf("Course: %s. room: %s. Key %d\n", crTable[i]->course, crTable[i]->room, getCRKey(crTable[i]));
      }
      while(crTable[i]->next != NULL){
        if (strcmp(crTable[i]->course, "") == 0) {
          crTable[i] = crTable[i]->next;
        } else {
          crTable[i] = crTable[i]->next;
          printf("Course: %s. room: %s. Key %d\n", crTable[i]->course, crTable[i]->room, getCRKey(crTable[i]));
        }
        if (crTable[i]->next == NULL) {
          break;
        }
      }
    }
  }
}




int main(int argc, char* argv[]) {
  struct CR** crTable = createTable();
  insertTuple(crTable, "CS101", "Turing Aud.");
  insertTuple(crTable, "EE200", "25 Ohm Hall");
  insertTuple(crTable, "PH100", "Newton Lab.");
  printTable(crTable);
}
