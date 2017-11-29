#include "StudentCourse.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct SNAPSC* newSNAPSC(int studentID, char* name, char* address, char* phone) {
  struct SNAPSC *snap = malloc(sizeof(struct SNAPSC));
  snap->name = (char*)malloc(sizeof(char) * (15));
  snap->address = (char*)malloc(sizeof(char) * (20));
  snap->phone = (char*)malloc(sizeof(char) * (20));
  strcpy(snap->name, name);
  strcpy(snap->address, address);
  strcpy(snap->phone, phone);
  snap->studentID = studentID;
  snap->next = NULL;
  return snap;
}

struct SNAPSC** createSNAPSCTable() {
  struct SNAPSC** snapTab = malloc(1009*sizeof(struct SNAPSC));
  return snapTab;
}

int getSNAPSCHashKey(struct SNAPSC* snap) {
  return snap->studentID % 1009;
}

void insertSNAPSCTuple(struct SNAPSC** snapTable, int studentID, char* name, char* address, char* phone) {
  struct SNAPSC* snapTemp = newSNAPSC(studentID, name, address, phone);
  int key = getSNAPSCHashKey(snapTemp);
  if(snapTable[key] == NULL) {
    //printf("Inserted\n");
    snapTable[key] = snapTemp;
  } else {
    while (snapTable[key]->next != NULL) {
      if (snapTable[key]->studentID == studentID && strcmp(snapTable[key]->name, name) == 0 && strcmp(snapTable[key]->address, address) == 0 && strcmp(snapTable[key]->phone, phone) == 0) {
        break;
      }
      snapTable[key] = snapTable[key]->next;
    }
  }

  if (snapTable[key]->studentID != studentID || strcmp(snapTable[key]->name, name) != 0 || strcmp(snapTable[key]->address, address) != 0 || strcmp(snapTable[key]->phone, phone) != 0) {
    snapTable[key]->next = snapTemp;
  }
}

void deleteSNAPSCTuple(struct SNAPSC** snapTable, int studentID, char* name, char* address, char* phone) {
  struct SNAPSC* snapTemp = newSNAPSC(studentID, name, address, phone);
  struct SNAPSC* snapFiller = newSNAPSC(0, "", "", "");
  if (studentID != 0 && strcmp(name, "*") != 0 && strcmp(address, "*") != 0 && strcmp(phone, "*") != 0) {
    int key = getSNAPSCHashKey(snapTemp);
    if (strcmp(snapTable[key]->name, name) == 0 && strcmp(snapTable[key]->address, address) == 0 && snapTable[key]->studentID == studentID && strcmp(snapTable[key]->phone, phone) == 0) {
      //printf("Reaches Here");
      snapTable[key] = snapFiller;
    }
    while(snapTable[key]->next != NULL) {
      if (strcmp(snapTable[key]->name, name) == 0 && strcmp(snapTable[key]->address, address) == 0 && snapTable[key]->studentID == studentID && strcmp(snapTable[key]->phone, phone) == 0) {
        //printf("Reaches Here");
        snapTable[key] = snapFiller;
        break;
      } else {
        //printf("Reaches Here");
        snapTable[key] = snapTable[key]->next;
      }
    }
    if (strcmp(snapTable[key]->name, name) == 0 && strcmp(snapTable[key]->address, address) == 0 && snapTable[key]->studentID == studentID && strcmp(snapTable[key]->phone, phone) == 0) {
      //printf("Reaches Here");
      snapTable[key] = snapFiller;
    }
  }
}


void printSNAPSCTable(struct SNAPSC** snapTable) {
  for (int i = 0; i < 1009; i++) {
    if (snapTable[i] != NULL) {
      while(snapTable[i] != NULL){
        //printf("Index: %d\n", i);
        if (snapTable[i]->studentID == 0) {
          //printf("Reaches Filler\n");
          snapTable[i] = snapTable[i]->next;
        }
        else {
          //printf("Else Statement\n");
          printf("Student ID: %d. Name: %s. Address: %s. Phone: %s. Key %d\n", snapTable[i]->studentID, snapTable[i]->name, snapTable[i]->address, snapTable[i]->phone, getSNAPSCHashKey(snapTable[i]));
          snapTable[i] = snapTable[i]->next;
        }
        if (snapTable[i] == NULL) {
          //printf("NULL Reached");
          break;
        }
      }
    }
  }
}

struct SNAPSC** lookupSNAPSC(struct SNAPSC** snapTable, int studentID, char* name, char* address, char* phone) {
  //struct SNAPSC* snapTemp = newSNAPSC(studentID, name, address, phone);
  struct SNAPSC** snapTableTemp = createSNAPSCTable();
  //Only Name is defined
  if (studentID == 0 && strcmp(address, "*") == 0 && strcmp(phone, "*") == 0) {
    //printf("Enters\n");
    for (int i = 0; i < 1009; i++) {
      if (snapTable[i] != NULL) {
        //printf("Enters at %d:\n", i);
        while(snapTable[i] != NULL) {
          if (strcmp(snapTable[i]->name, name) == 0) {
            insertSNAPSCTuple(snapTableTemp, snapTable[i]->studentID, snapTable[i]->name, snapTable[i]->address, snapTable[i]->phone);
            break;
          } else {
            snapTable[i] = snapTable[i]->next;
          }
          if (snapTable[i] == NULL) {
            //printf("NULL Reached");
            break;
          }
        }
      }
    }
  }
  return snapTableTemp;
  //printSNAPSCTable(snapTable);
}

struct CSGSC* newCSGSC(char* course, int studentID, char* grade){
  struct CSGSC *csg = malloc(sizeof(struct CSGSC));
  csg->course = (char*)malloc(sizeof(char) * (6));
  csg->grade = (char*)malloc(sizeof(char) * (3));
  strcpy(csg->course, course);
  strcpy(csg->grade, grade);
  csg->studentID = studentID;
  csg->next = NULL;
  return csg;
}

struct CSGSC** createCSGSCTable() {
  struct CSGSC** csgTab = malloc(1009*sizeof(struct CSGSC));
  return csgTab;
}

int getCSGSCHashKey(struct CSGSC* csg) {
  return csg->studentID % 1009;
}

void insertCSGSCTuple(struct CSGSC** csgTable, char* course, int studentID, char* grade) {
  struct CSGSC* csgTemp = newCSGSC(course, studentID, grade);
  int key = getCSGSCHashKey(csgTemp);
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

void deleteCSGSCTuple(struct CSGSC** csgTable, char* course, int studentID, char* grade) {
  struct CSGSC* csgTemp = newCSGSC(course, studentID, grade);
  struct CSGSC* csgFiller = newCSGSC("", 0, "");
  char string[50];
  sprintf(string, "%d", studentID);
  char* idString = string;
  //all three defined
  if (strcmp(course, "*") != 0 && strcmp(idString, "*") != 0 && strcmp(grade, "*") != 0) {
    //printf("Gets here");
    int key = getCSGSCHashKey(csgTemp);
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
    int key = getCSGSCHashKey(csgTemp);
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

void printCSGSCTable(struct CSGSC** csgTable) {
  for (int i = 0; i < 1009; i++) {
    if (csgTable[i] != NULL) {
      if (strcmp(csgTable[i]->course, "") != 0) {
        printf("Course: %s. Student ID: %d. Grade: %s. Key %d\n", csgTable[i]->course, csgTable[i]->studentID, csgTable[i]->grade, getCSGSCHashKey(csgTable[i]));
      }
      while(csgTable[i]->next != NULL){
        if (strcmp(csgTable[i]->course, "") == 0) {
          csgTable[i] = csgTable[i]->next;
        } else {
          csgTable[i] = csgTable[i]->next;
          printf("Course: %s. Student ID: %d. Grade: %s, Key: %d\n", csgTable[i]->course, csgTable[i]->studentID, csgTable[i]->grade, getCSGSCHashKey(csgTable[i]));
        }

        if (csgTable[i]->next == NULL) {
          break;
        }
      }
    }
  }
}

struct CSGSC** lookupCSGSC(struct CSGSC** csgTable, char* course, int studentID, char* grade) {
  struct CSGSC* csgTemp = newCSGSC(course, studentID, grade);
  struct CSGSC** csgTableTemp = createCSGSCTable();
  int broke = 0;
  int key = getCSGSCHashKey(csgTemp);
  while(csgTable[key]->next != NULL) {
    if (csgTable[key]->studentID == studentID && strcmp(csgTable[key]->course, course)) {
      //printf("Reaches Here");
      insertCSGSCTuple(csgTableTemp, csgTable[key]->course, csgTable[key]->studentID, csgTable[key]->grade);
      break;
      broke = 1;
    } else {
      //printf("Reaches Here");
      csgTable[key] = csgTable[key]->next;
    }
  }
  return csgTableTemp;
  //printCSGSCTable(csgTableTemp);
}



void printGrades(struct CSGSC** csgTableTemp, struct SNAPSC** snapTable, char* name, char* course) {
  struct SNAPSC** snapTableName = createSNAPSCTable();
  struct SNAPSC** snapTableTemp = createSNAPSCTable();
  //struct CSGSC** csgTableID = createCSGSCTable();
  snapTableName = lookupSNAPSC(snapTable, 0, name, "*", "*");
  snapTableTemp = snapTableName;
  //printSNAPSCTable(snapTableName);
  for (int i = 0; i < 1009; i++) {
    snapTableName = snapTableTemp;
    if (snapTableName[i] != NULL) {
      while(snapTableName[i] != NULL) {
        int tempID = snapTableName[i]->studentID;
        //printf("TempID: %d\n", tempID);
        for (int i = 0; i < 1009; i++) {
          if (csgTableTemp[i] != NULL) {
            //printf("Key: %d\n", i);
            while(csgTableTemp[i] != NULL) {
              //printf("Key: %d\n", i);
              //printf("StudentID: %d\n", csgTableTemp[i]->studentID);
              //printf("Course: %s\n", csgTableTemp[i]->course);
              if (csgTableTemp[i]->studentID == tempID && strcmp(csgTableTemp[i]->course, course) == 0) {
                printf("Grade for %s in %s: %s\n", name, course, csgTableTemp[i]->grade);
              }
              csgTableTemp[i] = csgTableTemp[i]->next;
              if (csgTableTemp[i] == NULL) {
                break;
              }
            }
          }
        }
        snapTableName[i] = snapTableName[i]->next;
        if (snapTableName[i] == NULL) {
          break;
        }
      }
    }
  }
}

void problem2a() {
  printf("Problem 2a:\n");
  struct SNAPSC** snapTable = createSNAPSCTable();
  insertSNAPSCTuple(snapTable, 12345, "C. Brown", "12 Apple St.", "555-1234");
  insertSNAPSCTuple(snapTable, 49192, "C. Brown", "31 Banana St.", "123-5432");
  insertSNAPSCTuple(snapTable, 67890, "L. Van Pelt", "34 Pear Ave.", "555-5678");
  insertSNAPSCTuple(snapTable, 22222, "P. Patty", "56 Grape Blvd.", "555-9999");
  struct CSGSC** csgTable = createCSGSCTable();
  insertCSGSCTuple(csgTable, "CS101", 12345, "A");
  insertCSGSCTuple(csgTable, "EE200", 12345, "C");
  insertCSGSCTuple(csgTable, "PH100", 81824, "C-");
  insertCSGSCTuple(csgTable, "EN150", 20310, "D+");
  insertCSGSCTuple(csgTable, "EE200", 22222, "B+");
  insertCSGSCTuple(csgTable, "CS101", 33333, "A-");
  insertCSGSCTuple(csgTable, "PH100", 67890, "C+");
  printf("Looking for C. Brown's grade in EE200: \n");
  printGrades(csgTable, snapTable, "C. Brown", "EE200");
  printf("\n");
}
