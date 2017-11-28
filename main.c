#include "main.h"
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
  runCP();
  return 0;
}
