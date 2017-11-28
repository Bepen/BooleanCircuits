#ifndef _RelationalAlgebra_h_gf
#define _RelationalAlgebra_h_gf
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#endif

struct RA {
  char* course;
  int studentID;
  char* grade;
  char* name;
  char* address;
  char* phone;
  char* preReq;
  char* day;
  char* hour;
  char* room;
  struct RA* next;
};

struct RA* newRA(char* course, int studentID,
                                char* grade,char* name, char* address,
                                char* phone,char* preReq,
                                char* day, char* hour,char* room);

struct RA** createRATable();
int main(int argc, char* argv[]);
