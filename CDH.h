#ifndef _CDH_h_gf
#define _CDH_h_gf
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct CDH {
  char* course;
  char* day;
  char* hour;
  struct CDH* next;
};

struct CDH* newCDH(char* course, char* day, char* hour);
struct CDH** createTable();

#endif
