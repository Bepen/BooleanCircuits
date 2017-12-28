/*
CSC 173 Project 4
Created By Bepen Neupane and Sailesh Kaveti
NetID: bneupane skaveti

*/
#include "RelationalAlgebra.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//Creates a new Tuple
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

//Gets the key for an RA tuple
int getRAKey(struct RA* ra) {
  return ra->studentID % 1009;
}

//Creates an RA table
struct RA** createRATable() {
  struct RA** raTab = malloc(1009*sizeof(struct RA));
  return raTab;
}

//Inserts a tuple if it already isn't in it
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

//Selects tuples based on a certain condition
struct RA** selectRA(struct RA** raTable, char* query, char* value, int studentID) {
  struct RA** raTemp = createRATable();
  for (int i = 0; i < 1009; i++) {
    while (raTable[i] != NULL) {
      if (strcmp(query, "course") == 0 && strcmp(raTable[i]->course, value) == 0) {
        insertRATuple(raTemp, raTable[i]->course, raTable[i]->studentID, raTable[i]->grade, raTable[i]->name, raTable[i]->address, raTable[i]->phone, raTable[i]->preReq, raTable[i]->day, raTable[i]->hour, raTable[i]->room);
      } else if (strcmp(query, "studentID") == 0 && raTable[i]->studentID == studentID) {
        insertRATuple(raTemp, raTable[i]->course, raTable[i]->studentID, raTable[i]->grade, raTable[i]->name, raTable[i]->address, raTable[i]->phone, raTable[i]->preReq, raTable[i]->day, raTable[i]->hour, raTable[i]->room);
      } else if (strcmp(query, "grade") == 0 && strcmp(raTable[i]->grade, value) == 0) {
        insertRATuple(raTemp, raTable[i]->course, raTable[i]->studentID, raTable[i]->grade, raTable[i]->name, raTable[i]->address, raTable[i]->phone, raTable[i]->preReq, raTable[i]->day, raTable[i]->hour, raTable[i]->room);
      } else if (strcmp(query, "name") == 0 && strcmp(raTable[i]->name, value) == 0) {
        insertRATuple(raTemp, raTable[i]->course, raTable[i]->studentID, raTable[i]->grade, raTable[i]->name, raTable[i]->address, raTable[i]->phone, raTable[i]->preReq, raTable[i]->day, raTable[i]->hour, raTable[i]->room);
      } else if (strcmp(query, "address") == 0 && strcmp(raTable[i]->address, value) == 0) {
        insertRATuple(raTemp, raTable[i]->course, raTable[i]->studentID, raTable[i]->grade, raTable[i]->name, raTable[i]->address, raTable[i]->phone, raTable[i]->preReq, raTable[i]->day, raTable[i]->hour, raTable[i]->room);
      } else if (strcmp(query, "phone") == 0 && strcmp(raTable[i]->phone, value) == 0) {
        insertRATuple(raTemp, raTable[i]->course, raTable[i]->studentID, raTable[i]->grade, raTable[i]->name, raTable[i]->address, raTable[i]->phone, raTable[i]->preReq, raTable[i]->day, raTable[i]->hour, raTable[i]->room);
      } else if (strcmp(query, "preReq") == 0 && strcmp(raTable[i]->preReq, value) == 0) {
        insertRATuple(raTemp, raTable[i]->course, raTable[i]->studentID, raTable[i]->grade, raTable[i]->name, raTable[i]->address, raTable[i]->phone, raTable[i]->preReq, raTable[i]->day, raTable[i]->hour, raTable[i]->room);
      } else if (strcmp(query, "day") == 0 && strcmp(raTable[i]->day, value) == 0) {
        insertRATuple(raTemp, raTable[i]->course, raTable[i]->studentID, raTable[i]->grade, raTable[i]->name, raTable[i]->address, raTable[i]->phone, raTable[i]->preReq, raTable[i]->day, raTable[i]->hour, raTable[i]->room);
      } else if (strcmp(query, "hour") == 0 && strcmp(raTable[i]->hour, value) == 0) {
        insertRATuple(raTemp, raTable[i]->course, raTable[i]->studentID, raTable[i]->grade, raTable[i]->name, raTable[i]->address, raTable[i]->phone, raTable[i]->preReq, raTable[i]->day, raTable[i]->hour, raTable[i]->room);
      } else if (strcmp(query, "room") == 0 && strcmp(raTable[i]->room, value) == 0) {
        insertRATuple(raTemp, raTable[i]->course, raTable[i]->studentID, raTable[i]->grade, raTable[i]->name, raTable[i]->address, raTable[i]->phone, raTable[i]->preReq, raTable[i]->day, raTable[i]->hour, raTable[i]->room);
      }
      raTable[i] = raTable[i]->next;
      if (raTable[i] == NULL) {
        break;
      }
    }
  }
  return raTemp;
}

//Projection
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


//Prints the Table
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


//Method to be called in the main method
void problem3() {
  //Inserting the tuples for example 8.12
  printf("Doing example 8.12 from book: \n");
  struct RA** raTable = createRATable();
  insertRATuple(raTable, "CS101", 12345, "A", "", "", "", "", "", "", "");
  insertRATuple(raTable, "CS101", 67890, "B", "", "", "", "", "", "", "");
  insertRATuple(raTable, "EE200", 55555, "B", "", "", "", "", "", "", "");
  insertRATuple(raTable, "EE200", 22222, "B+", "", "", "", "", "", "", "");
  insertRATuple(raTable, "CS101", 33333, "A-", "", "", "", "", "", "", "");
  insertRATuple(raTable, "PH100", 67890, "C+", "", "", "", "", "", "", "");
  printRATable(selectRA(raTable, "course", "CS101", 0));

  //Inserting tuples and doing example 8.13 from the book
  printf("\nDoing example 8.13 from book: \n");
  struct RA** raTable1 = createRATable();
  insertRATuple(raTable1, "CS101", 12345, "A", "", "", "", "", "", "", "");
  insertRATuple(raTable1, "CS101", 67890, "B", "", "", "", "", "", "", "");
  insertRATuple(raTable1, "EE200", 55555, "B", "", "", "", "", "", "", "");
  insertRATuple(raTable1, "EE200", 22222, "B+", "", "", "", "", "", "", "");
  insertRATuple(raTable1, "CS101", 33333, "A-", "", "", "", "", "", "", "");
  insertRATuple(raTable1, "PH100", 67890, "C+", "", "", "", "", "", "", "");
  printRATable(project(selectRA(raTable1, "course", "CS101", 0), "studentID"));
}
