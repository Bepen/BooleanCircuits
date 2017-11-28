#include "RelationalAlgebra.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct RelationalAlgebra* newRA(char* course, int studentID, char* grade,char* name, char* address, char* phone,char* preReq, char* day, char* hour,char* room){
  struct RelationalAlgebra *ra = malloc(sizeof(struct RelationalAlgebra));
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

struct RelationalAlgebra** createRATable() {
  struct RelationalAlgebra** raTab = malloc(1009*sizeof(struct RelationalAlgebra));
  return raTab;
}

void insertRATuple(struct RA** raTable, char* course, int studentID, char* grade,char* name, char* address, char* phone,char* preReq, char* day, char* hour,char* room) {
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

int main(int argc, char* argv[]) {
  return 0;
}
