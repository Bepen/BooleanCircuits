#include "main.h"
#include "RelationalAlgebra.c"
#include "RelationalAlgebra.h"
#include "StudentCourse.c"
//#include "StudentCourse.h"
#include "CSG.c"
#include "SNAP.c"
#include "CDH.c"
#include "CP.c"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  runCSG();
  runSNAP();
  runCDH();
<<<<<<< HEAD
<<<<<<< HEAD
  runCP();
=======
=======
  runCP();
>>>>>>> c1e2bad35f268626e9f7f7fd5811cab8f88a4c45
  //problem2a();
  problem3();
>>>>>>> e655297cf3bc5261dcfd535963b15c87cb7bacda
  return 0;
}
