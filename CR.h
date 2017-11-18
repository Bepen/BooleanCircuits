#ifndef _CR_h_gf
#define _CR_h_gf
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct CR {
  char* course;
  char* room;
  struct CR* next;
};

#endif
