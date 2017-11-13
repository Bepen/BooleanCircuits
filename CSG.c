#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "CSG.h"

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

struct CSG** createTable() {
  struct CSG** csgTab = malloc(1009*sizeof(struct CSG));
  return csgTab;
}

int getHashKey(struct CSG* csg) {
  return csg->studentID % 1009;
}

void insertTuple(struct CSG** csgTable, char* course, int studentID, char* grade) {
  struct CSG* csgTemp = newCSG(course, studentID, grade);
  int key = getHashKey(csgTemp);
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

void printTable(struct CSG** csgTable) {
  for (int i = 0; i < 1009; i++) {
    if (csgTable[i] != NULL) {
      printf("Course: %s. Student ID: %d. Grade: %s\n", csgTable[i]->course, csgTable[i]->studentID, csgTable[i]->grade);
      while(csgTable[i]->next != NULL){
        csgTable[i] = csgTable[i]->next;
        printf("Course: %s. Student ID: %d. Grade: %s, Key: %d\n", csgTable[i]->course, csgTable[i]->studentID, csgTable[i]->grade, getHashKey(csgTable[i]));
        if (csgTable[i]->next == NULL) {
          break;
        }
      }
    }
  }
}

int main(int argc, char* argv[]) {
  struct CSG** csgTable = createTable();
  insertTuple(csgTable, "Sailesh", 6969, "A");
  insertTuple(csgTable, "Haha", 7978, "C");
  insertTuple(csgTable, "Fetty Wap", 1738, "G");
  printTable(csgTable);
}
