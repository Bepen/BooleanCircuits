#ifndef _CSG_h_gf
#define _CSG_h_gf
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct CDH {
  char* course;
  char* day;
  char* hour;
  struct CDH* next;
};

struct CDH* newCSG(char* course, char* day, char* hour);
struct CDH** createTable();

#endif
