#ifndef _CP_h_gf
#define _CP_h_gf
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct CP {
  char* course;
  char* preReq;
  struct CP* next;
};

#endif
