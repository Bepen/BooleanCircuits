#ifndef _Tuple_h_gf
#define _Tuple_h_gf
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//typedef struct TUPLE* TUPLELIST;
struct TUPLE {
  int studentID;
  char* course;
  char* grade;
  char* name;
  char* address;
  char* phone;
  char* prerequisite;
  char* day;
  char* hour;
  char* room;
  TUPLELIST next;
}
typedef TUPLELIST HASHTABLE[1009];

extern struct
