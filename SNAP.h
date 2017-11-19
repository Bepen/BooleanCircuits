#ifndef _SNAP_h_gf
#define _SNAP_h_gf
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct SNAP {
  char* name;
  int studentID;
  char* address;
  char* phone;
  struct SNAP* next;
};

struct SNAP* newSNAP(int studentID, char* name, char* address, char* grade);
struct SNAP** createTable();

#endif
