#include "main.h"
#include "RelationalAlgebra.c"
#include "RelationalAlgebra.h"
#include "StudentCourse.c"
//#include "StudentCourse.h"
#include "CSG.c"
#include "SNAP.c"
#include "CDH.c"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  runCSG();
  runSNAP();
  runCDH();
  runCP();
  //problem2a();
  problem3();
  return 0;
}
