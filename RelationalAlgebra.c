#include "RelationalAlgebra.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct RA* newRA(char* course, int studentID, char* grade,char* name, char* address, char* phone,char* preReq, char* day, char* hour,char* room){
  struct RA *ra = malloc(sizeof(struct RA));
  ra->course = (char*)malloc(sizeof(char) * (6));
  ra->grade = (char*)malloc(sizeof(char) * (3));
  ra->name = (char*)malloc(sizeof(char) * (15));
  ra->address = (char*)malloc(sizeof(char) * (20));
  ra->phone = (char*)malloc(sizeof(char) * (20));
  ra->preReq = (char*)malloc(sizeof(char) * (3));
  ra->day = (char*)malloc(sizeof(char) * (2));
  ra->hour = (char*)malloc(sizeof(char) * (4));
  ra->room = (char*)malloc(sizeof(char) * (20));
  strcpy(ra->course, course);
  strcpy(ra->grade, grade);
  strcpy(ra->name, name);
  strcpy(ra->address, address);
  strcpy(ra->phone, phone);
  strcpy(ra->preReq, preReq);
  strcpy(ra->day, day);
  strcpy(ra->hour, hour);
  strcpy(ra->room, room);
  ra->studentID = studentID;
  ra->next = NULL;
  return ra;
}

int getRAKey(struct RA* ra) {
  return ra->studentID % 1009;
}

struct RA** createRATable() {
  struct RA** raTab = malloc(1009*sizeof(struct RA));
  return raTab;
}

void insertRATuple(struct RA** raTable, char* course, int studentID, char* grade, char* name, char* address, char* phone, char* preReq, char* day, char* hour, char* room) {
  struct RA* raTemp = newRA(course, studentID, grade, name, address, phone, preReq, day, hour, room);
  int key = getRAKey(raTemp);
  if (raTable[key] == NULL) {
    raTable[key] = raTemp;
  } else {
    while (raTable[key]->next != NULL) {
      if (strcmp(raTable[key]->course, course) == 0 && strcmp(raTable[key]->grade, grade) == 0 && strcmp(raTable[key]->name, name) == 0 && strcmp(raTable[key]->address, address) == 0 && strcmp(raTable[key]->phone, phone) == 0 && strcmp(raTable[key]->preReq, preReq) == 0 && strcmp(raTable[key]->day, day) == 0 && strcmp(raTable[key]->hour, hour) == 0 && strcmp(raTable[key]->room, room) == 0 && raTable[key]->studentID == studentID) {
        break;
      }
      raTable[key] = raTable[key]->next;
    }
    if (!(strcmp(raTable[key]->course, course) == 0 && strcmp(raTable[key]->grade, grade) == 0 && strcmp(raTable[key]->name, name) == 0 && strcmp(raTable[key]->address, address) == 0 && strcmp(raTable[key]->phone, phone) == 0 && strcmp(raTable[key]->preReq, preReq) == 0 && strcmp(raTable[key]->day, day) == 0 && strcmp(raTable[key]->hour, hour) == 0 && strcmp(raTable[key]->room, room) == 0 && raTable[key]->studentID == studentID)) {
      raTable[key]->next = raTemp;
    }
  }
}

<<<<<<< HEAD
=======
struct RA** select(struct RA** raTable, char* query, char* )

>>>>>>> c1e2bad35f268626e9f7f7fd5811cab8f88a4c45
struct RA** project(struct RA** raTable, char* query) {
  struct RA** raTemp = createRATable();
  for (int i = 0; i < 1009; i++) {
    while (raTable[i] != NULL) {
      if (strcmp(query, "course") == 0) {
        insertRATuple(raTemp, raTable[i]->course, 0, "", "", "", "", "", "", "", "");
      } else if (strcmp(query, "studentID") == 0) {
        insertRATuple(raTemp, "", raTable[i]->studentID, "", "", "", "", "", "", "", "");
      } else if (strcmp(query, "grade") == 0) {
        insertRATuple(raTemp, "", 0, raTable[i]->grade, "", "", "", "", "", "", "");
      } else if (strcmp(query, "name") == 0) {
        insertRATuple(raTemp, "", 0, "", raTable[i]->name, "", "", "", "", "", "");
      } else if (strcmp(query, "address") == 0) {
        insertRATuple(raTemp, "", 0, "", "", raTable[i]->address, "", "", "", "", "");
      } else if (strcmp(query, "phone") == 0) {
        insertRATuple(raTemp, "", 0, "", "", "", raTable[i]->phone, "", "", "", "");
      } else if (strcmp(query, "preReq") == 0) {
        insertRATuple(raTemp, "", 0, "", "", "", "", raTable[i]->preReq, "", "", "");
      } else if (strcmp(query, "day") == 0) {
        insertRATuple(raTemp, "", 0, "", "", "", "", "", raTable[i]->day, "", "");
      } else if (strcmp(query, "hour") == 0) {
        insertRATuple(raTemp, "", 0, "", "", "", "", "", "", raTable[i]->hour, "");
      } else if (strcmp(query, "room") == 0) {
        insertRATuple(raTemp, "", 0, "", "", "", "", "", "", "", raTable[i]->room);
      }
      raTable[i] = raTable[i]->next;
      if (raTable[i] == NULL) {
        break;
      }
    }
  }
  return raTemp;
}

struct


void printRATable(struct RA** raTable) {
  for (int i = 0; i < 1009; i++) {
    while (raTable[i] != NULL) {
      printf("Course: %s. ID: %d. Grade: %s. Name: %s. Address: %s. Phone: %s. Prerequisite: %s. Day: %s. Hour: %s. Room: %s.\n", raTable[i]->course, raTable[i]->studentID, raTable[i]->grade, raTable[i]->name, raTable[i]->address, raTable[i]->phone, raTable[i]->preReq, raTable[i]->day, raTable[i]->hour, raTable[i]->room);
      raTable[i] = raTable[i]->next;
      if (raTable[i] == NULL) {
        break;
      }
    }
  }
}


int main(int argc, char* argv[]) {
  struct RA** raTable = createRATable();
  insertRATuple(raTable, "CS101", 12345, "A", "C. Brown", "34 Apple St.", "555-1234", "CS100", "M", "9AM", "Turing Aud.");
  insertRATuple(raTable, "EE200", 55555, "B", "P. Patty", "45 Pear St.", "555-5678", "CS101", "T", "10AM", "25 Ohm Hall");
  //printRATable(raTable);
  printRATable(project(raTable, "studentID"));
}
