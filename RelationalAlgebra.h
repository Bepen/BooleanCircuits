#ifndef _RelationalAlgebra_h_gf
#define _RelationalAlgebra_h_gf
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#endif

struct RelationalAlgebra {
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
  struct RelationalAlgebra* next;
};

struct RelationalAlgebra* newRA(char* course, int studentID,
                                char* grade,char* name, char* address,
                                char* phone,char* preReq,
                                char* day, char* hour,char* room);

struct RelationalAlgebra** createRATable();
int main(int argc, char* argv[]);
