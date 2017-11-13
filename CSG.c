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
  for (int i = 0; i < 1009; i++) {
    csgTab[i] = newCSG("", 0, "");
  }
  return csgTab;
}

void printTable(CSG** csgTable) {
  for (int i = 0; i < 1009; i++) {
    printf("Course: %s. Student ID: %d. Grade: %s\n", csgTable[i]->course, csgTable[i]->studentID, csgTable[i]->grade);
  }
}

void main(int argc, char* argv[]) {
  CSG** csgTable = createTable();
  printTable(csgTable);
}
