#include "NameTimeDay.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct SNAP* newSNAP(int studentID, char* name, char* address, char* phone) {
  struct SNAP *snap = malloc(sizeof(struct SNAP));
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

struct SNAP** createSNAPTable() {
  struct SNAP** snapTab = malloc(1009*sizeof(struct SNAP));
  return snapTab;
}

int getSNAPHashKey(struct SNAP* snap) {
  return snap->studentID % 1009;
}

void insertSNAPTuple(struct SNAP** snapTable, int studentID, char* name, char* address, char* phone) {
  struct SNAP* snapTemp = newSNAP(studentID, name, address, phone);
  int key = getSNAPHashKey(snapTemp);
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

void deleteSNAPTuple(struct SNAP** snapTable, int studentID, char* name, char* address, char* phone) {
  struct SNAP* snapTemp = newSNAP(studentID, name, address, phone);
  struct SNAP* snapFiller = newSNAP(0, "", "", "");
  if (studentID != 0 && strcmp(name, "*") != 0 && strcmp(address, "*") != 0 && strcmp(phone, "*") != 0) {
    int key = getSNAPHashKey(snapTemp);
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

void printSNAPTable(struct SNAP** snapTable) {
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
          printf("Student ID: %d. Name: %s. Address: %s. Phone: %s. Key %d\n", snapTable[i]->studentID, snapTable[i]->name, snapTable[i]->address, snapTable[i]->phone, getSNAPHashKey(snapTable[i]));
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

struct SNAP** lookupSNAP(struct SNAP** snapTable, int studentID, char* name, char* address, char* phone) {
  struct SNAP* snapTemp = newSNAP(studentID, name, address, phone);
  struct SNAP** snapTableTemp = createSNAPTable();
  //Only Name is defined
  if (studentID == 0 && strcmp(address, "*") == 0 && strcmp(phone, "*") == 0) {
    //printf("Enters\n");
    for (int i = 0; i < 1009; i++) {
      if (snapTable[i] != NULL) {
        //printf("Enters at %d:\n", i);
        while(snapTable[i] != NULL) {
          if (strcmp(snapTable[i]->name, name) == 0) {
            insertSNAPTuple(snapTableTemp, snapTable[i]->studentID, snapTable[i]->name, snapTable[i]->address, snapTable[i]->phone);
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
  //printSNAPTable(snapTable);
}

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

struct CSG** createCSGTable() {
  struct CSG** csgTab = malloc(1009*sizeof(struct CSG));
  return csgTab;
}

int getCSGHashKey(struct CSG* csg) {
  return csg->studentID % 1009;
}

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

void printCSGTable(struct CSG** csgTable) {
  for (int i = 0; i < 1009; i++) {
    if (csgTable[i] != NULL) {
      if (strcmp(csgTable[i]->course, "") != 0) {
        printf("Course: %s. Student ID: %d. Grade: %s. Key %d\n", csgTable[i]->course, csgTable[i]->studentID, csgTable[i]->grade, getCSGHashKey(csgTable[i]));
      }
      while(csgTable[i]->next != NULL){
        if (strcmp(csgTable[i]->course, "") == 0) {
          csgTable[i] = csgTable[i]->next;
        } else {
          csgTable[i] = csgTable[i]->next;
          printf("Course: %s. Student ID: %d. Grade: %s, Key: %d\n", csgTable[i]->course, csgTable[i]->studentID, csgTable[i]->grade, getCSGHashKey(csgTable[i]));
        }

        if (csgTable[i]->next == NULL) {
          break;
        }
      }
    }
  }
}

struct CSG** lookupCSG(struct CSG** csgTable, char* course, int studentID, char* grade) {
  struct CSG* csgTemp = newCSG(course, studentID, grade);
  struct CSG** csgTableTemp = createCSGTable();
  int broke = 0;
  int key = getCSGHashKey(csgTemp);
  if (strcmp(course, "*") == 0 && strcmp(grade, "*") == 0) {
    while(csgTable[key] != NULL) {
      if (csgTable[key]->studentID == studentID) {
        //printf("Reaches Here");
        insertCSGTuple(csgTableTemp, csgTable[key]->course, csgTable[key]->studentID, csgTable[key]->grade);
        broke = 1;
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
        broke = 1;
      } else {
        //printf("Reaches Here");
        csgTable[key] = csgTable[key]->next;
      }
    }
  }
  return csgTableTemp;
  //printCSGTable(csgTableTemp);
}

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

struct CDH** createCDHTable() {
  struct CDH** cdhTab = malloc(1009*sizeof(struct CDH));
  return cdhTab;
}

int getCDHHashKey(struct CDH* cdh) {
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

void deleteCDHTuple(struct CDH** cdhTable, char* course, char* day, char* hour){
  struct CDH* cdhTemp = newCDH(course, day, hour);
  struct CDH* cdhFiller = newCDH("", "", "");
  if (strcmp(course, "*") != 0 && strcmp(day, "*") != 0 && strcmp(hour, "*") != 0) {
    int key = getCDHHashKey(cdhTemp);
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

void printCDHTable(struct CDH** cdhTable) {
  for (int i = 0; i < 1009; i++) {
    if (cdhTable[i] != NULL) {
      //cdhTable[i] = cdhTable[i]->next;
      if (cdhTable[i]->next == NULL) {
        if (strcmp(cdhTable[i]->course, "") != 0) {
          printf("Course: %s. Day: %s. Hour: %s. Key %d\n", cdhTable[i]->course, cdhTable[i]->day, cdhTable[i]->hour, getCDHHashKey(cdhTable[i]));
          continue;
        }
      }
      while(cdhTable[i]->next!= NULL){
        if (strcmp(cdhTable[i]->course, "") == 0) {
          cdhTable[i] = cdhTable[i]->next;
        } else {
          printf("Course: %s. Day: %s. Hour: %s. Key %d\n", cdhTable[i]->course, cdhTable[i]->day, cdhTable[i]->hour, getCDHHashKey(cdhTable[i]));
          cdhTable[i] = cdhTable[i]->next;
        }
        if (cdhTable[i]->next == NULL) {
          break;
        }
      }
    }
  }
}

void insertCDHTuple(struct CDH** cdhTable, char* course, char* day, char* hour) {
  struct CDH* cdhTemp = newCDH(course, day, hour);
  int key = getCDHHashKey(cdhTemp);
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

struct CDH** lookupCDH(struct CDH** cdhTable, char* course, char* day, char* hour) {
  struct CDH* cdhTemp = newCDH(course, day, hour);
  struct CDH** cdhTableTemp = createCDHTable();
  int broke = 0;
  int key = getCDHHashKey(cdhTemp);
  while(cdhTable[key] != NULL) {
    //printf("Key: %d\n", key);
    //printf("Course: %s. Day: %s. Hour: %s. Key %d\n", cdhTable[key]->course, cdhTable[key]->day, cdhTable[key]->hour, getCDHHashKey(cdhTable[key]));
    //printf("%s \n", cdhTable[key]->hour);
    if (strcmp(cdhTable[key]->course, course) == 0 && strcmp(cdhTable[key]->day, day) == 0) {
      insertCDHTuple(cdhTableTemp, cdhTable[key]->course, cdhTable[key]->day, cdhTable[key]->hour);
      break;
      broke = 1;
    } else {
      //printf("Reaches Here");
      cdhTable[key] = cdhTable[key]->next;
    }
    //cdhTable[key] = cdhTable[key]->next;
  }
  return cdhTableTemp;
}

struct CR* newCR(char* course, char* room){
  struct CR *cr = malloc(sizeof(struct CR));
  cr->course = (char*)malloc(sizeof(char) * (6));
  cr->room = (char*)malloc(sizeof(char) * (50));
  strcpy(cr->course, course);
  strcpy(cr->room, room);
  cr->next = NULL;
  return cr;
}

struct CR** createCRTable() {
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

void insertCRTuple(struct CR** crTable, char* course, char* room) {
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

void deleteCRTuple(struct CR** crTable, char* course, char* room) {
  struct CR* crFiller = newCR("", "");
  struct CR* crTemp = newCR(course, room);
  if (strcmp(room, "*") == 0) {
    for (int i = 0; i < 1009; i++) {
      if (crTable[i] == NULL) {
        //printf("%d\n", i);
        continue;
      }
      if (strcmp(crTable[i]->course, course) == 0) {
        crTable[i] = crFiller;
      }
      while(crTable[i]->next != NULL) {
        if (strcmp(crTable[i]->course, course) == 0) {
          crTable[i] = crFiller;
        } else {
          crTable[i] = crTable[i]->next;
        }
      }
      if (strcmp(crTable[i]->course, course) == 0) {
        crTable[i] = crFiller;
      }
    }
  } else {
    int key = getCRKey(crTemp);
    if (crTable[key] == NULL) {
      return;
    }
    while (crTable[key]->next != NULL) {
      if (strcmp(crTable[key]->course, course) == 0 && strcmp(crTable[key]->room, room) == 0) {
        crTable[key] = crFiller;
      } else {
        crTable[key] = crTable[key]->next;
      }
    }
    if (strcmp(crTable[key]->course, course) == 0 && strcmp(crTable[key]->room, room) == 0) {
      crTable[key] = crFiller;
    }
  }
}

void printCRTable(struct CR** crTable) {
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

struct CR** lookupCR(struct CR** crTable, char* course, char* room) {
  struct CR* crTemp = newCR(course, room);
  struct CR** crTempTable = createCRTable();
  int key = getCRKey(crTemp);
  if (crTable[key] == NULL) {
    //printf("NULL\n");
    return NULL;
  }
  while (crTable[key]->next != NULL) {
    if (strcmp(crTable[key]->course, course) == 0 && strcmp(crTable[key]->room, room) == 0) {
      insertCRTuple(crTempTable, course, room);
      break;
    } else {
      crTable[key] = crTable[key]->next;
    }
  }
  if (strcmp(crTable[key]->course, course) == 0 && strcmp(crTable[key]->room, room) == 0) {
    insertCRTuple(crTempTable, course, room);
  }
  return crTable;
}

void printLocation(struct SNAP** snapTable, struct CSG** csgTable, struct CDH** cdhTable, struct CR** crTable, char* name, char* day, char* time) {
  struct SNAP** snapTableName = lookupSNAP(snapTable, 0, name, "*", "*");
  int studentID = 0;
  for (int i = 0; i < 1009; i++) {
    if (snapTableName[i] != NULL) {
      while(snapTableName[i] != NULL) {
        studentID = snapTableName[i]->studentID;
        break;
        snapTableName[i] = snapTableName[i]->next;
        if (snapTableName[i] == NULL) {
          break;
        }
      }
    }
  }
  char* course  = "*****";
  //printf("StudentID: %d\n", studentID);
  struct CSG** csgTableID = lookupCSG(csgTable, "*", studentID, "*");
  struct CDH** cdhTableComp;
  //printCSGTable(csgTableID);
  for (int i = 0; i < 1009; i++) {
    if (csgTableID[i] != NULL) {
      //printf("Index: %d\n", i);
      while(csgTableID[i] != NULL) {
        //printf("Course: %s\n", csgTableID[i]->course);
        cdhTableComp = lookupCDH(cdhTable, csgTableID[i]->course, day, time);
        for (int j = 0; j < 1009; j++) {
          if (cdhTableComp[j] != NULL) {
            course = cdhTableComp[j]->course;
            break;
          }
        }
        csgTableID[i] = csgTableID[i]->next;
        if (csgTableID[i] == NULL) {
          break;
        }
      }
    }
  }
  char* room = "*****";
  //printf("Final Course: %s\n", course);
  if (strcmp(course , "*****") == 0) {
    printf("%s is not taking a class at %s on %s.", name, time, day);
  } else {
    for (int i = 0; i < 1009; i++) {
      if (crTable[i] != NULL) {
        while (crTable[i] != NULL) {
          if (strcmp(crTable[i]->course, course) == 0) {
            //printf("Comparison True\n");
            room = crTable[i]->room;
          }
          crTable[i] = crTable[i]->next;
        }
      }
    }
    printf("Where is %s at %s on %s: %s\n", name, time, day, room);
  }
}

int main(int argc, char* argv[]) {
  struct SNAP** snapTable = createSNAPTable();
  printf("INSERTING VALUES... \n");
  insertSNAPTuple(snapTable, 12345, "C. Brown", "12 Apple St.", "555-1234");
  insertSNAPTuple(snapTable, 67890, "L. Van Pelt", "34 Pear Ave.", "555-5678");
  insertSNAPTuple(snapTable, 22222, "P. Patty", "56 Grape Blvd.", "555-9999");
  //printSNAPTable(snapTable);
  //printf("*****************************\n");
  struct CSG** csgTable = createCSGTable();
  insertCSGTuple(csgTable, "CS101", 12345, "A");
  insertCSGTuple(csgTable, "EE200", 12345, "C");
  insertCSGTuple(csgTable, "PH100", 81824, "C-");
  insertCSGTuple(csgTable, "EN150", 20310, "D+");
  insertCSGTuple(csgTable, "EE200", 22222, "B+");
  insertCSGTuple(csgTable, "CS101", 33333, "A-");
  insertCSGTuple(csgTable, "PH100", 67890, "C+");
  //printf("Finished insertion:\n");
  //printCSGTable(lookupCSG(csgTable, "*", 12345, "*"));
  //printCSGTable(csgTable);
  //printf("*****************************\n");
  struct CDH** cdhTable = createCDHTable();
  insertCDHTuple(cdhTable, "CS101", "M", "9AM");
  insertCDHTuple(cdhTable, "CS101", "W", "9AM");
  insertCDHTuple(cdhTable, "CS101", "F", "9AM");
  insertCDHTuple(cdhTable, "EE200", "Tu", "10AM");
  insertCDHTuple(cdhTable, "EE200", "W", "1PM");
  insertCDHTuple(cdhTable, "EE200", "Th", "10AM");
  //printCDHTable(cdhTable);
  //printf("*****************************\n");
  struct CR** crTable = createCRTable();
  insertCRTuple(crTable, "CS101", "Turing Aud");
  insertCRTuple(crTable, "EE200", "25 Ohm Hall");
  insertCRTuple(crTable, "PH100", "Newton Lab");
  //printCRTable(crTable);
  //printf("*****************************\n");
  printLocation(snapTable, csgTable, cdhTable, crTable, "C. Brown", "M", "9AM");
}
