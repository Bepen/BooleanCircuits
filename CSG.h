#ifndef _CSG_h_gf
#define _CSG_h_gf
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct CSG {
  char* course;
  int studentID;
  char* grade;
  struct CSG* next;
}

struct CSG* newCSG(char* course, int studentID, char* grade);
struct CSG** createTable();
