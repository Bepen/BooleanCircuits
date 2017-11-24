#include "StudentCourse.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "SNAP.h"
#include "CDH.h"
#include "CR.h"
#include "CP.h"
#include "CSG.h"


int main(int argc, char* argv[]) {
  struct CSG** csgTable = createTable();
  printf("Inserted 8 different tuples: \n");
  insertTuple(csgTable, "CS101", 12345, "A");
  insertTuple(csgTable, "EE200", 12345, "C");
  insertTuple(csgTable, "EE200", 49192, "D");
  insertTuple(csgTable, "PH100", 81824, "C-");
  insertTuple(csgTable, "EN150", 20310, "D+");
  insertTuple(csgTable, "EE200", 22222, "B+");
  insertTuple(csgTable, "CS101", 33333, "A-");
  insertTuple(csgTable, "PH100", 67890, "C+");
  printf("Looking up the grade for student in CSC101 with an ID of 12345:\n");
  lookup(csgTable, "CSC101", 12345, "*");
  printf("Deleting the student 20310 in EN150 with a D+: \n");
  deleteTuple(csgTable, "EN150", 20310, "D+");
  printf("Deleting the student 12345: \n");
  deleteTuple(csgTable, "*", 12345, "*");
  printf("Deleting all of the students in PH100\n");
  deleteTuple(csgTable, "PH100", 0, "*");
  printTable(csgTable);

  struct CDH** cdhTable = createTable();
  insertTuple(cdhTable, "CS101", "M", "9AM");
  insertTuple(cdhTable, "CS101", "M", "9AM");
  insertTuple(cdhTable, "CS101", "W", "9AM");
  insertTuple(cdhTable, "CS101", "F", "9AM");
  insertTuple(cdhTable, "EE200", "Tu", "10AM");
  insertTuple(cdhTable, "EE200", "Tu", "11AM");
  insertTuple(cdhTable, "EE200", "W", "1PM");
  insertTuple(cdhTable, "EE200", "Th", "10AM");
  insertTuple(cdhTable, "PSY101", "M", "9AM");
  insertTuple(cdhTable, "STT213", "M", "9AM");
  deleteTuple(cdhTable, "PSY101", "M", "9AM");
  deleteTuple(cdhTable, "STT213", "M", "9AM");
  printTable(cdhTable);
  printf("lookup********\n");
  lookup(cdhTable, "EE200", "Tu", "*");

  struct CP** cpTable = createTable();
  printf("Filling Table\n");
  insertTuple(cpTable, "CS101", "CS100");
  insertTuple(cpTable, "EE200", "EE005");
  insertTuple(cpTable, "EE200", "CS100");
  insertTuple(cpTable, "CS120", "CS101");
  insertTuple(cpTable, "CS121", "CS120");
  insertTuple(cpTable, "CS205", "CS101");
  insertTuple(cpTable, "CS205", "CS120");
  insertTuple(cpTable, "CS206", "CS121");
  insertTuple(cpTable, "CS206", "CS205");
  insertTuple(cpTable, "CS120", "CS101");
  deleteTuple(cpTable, "CS120", "*");
  deleteTuple(cpTable, "EE200", "CS100");
  printf("Looking for course CS101 with preReq of CS100:\n");
  lookup(cpTable, "CS101", "CS100");
  printf("Looking for course CS100 with preReq of EN150:\n");
  lookup(cpTable, "CS100", "EN150");
  printf("\n");
  printTable(cpTable);

  struct SNAP** snapTable = createTable();
  insertTuple(snapTable, 12345, "C. Brown", "12 Apple St.", "555-1234");
  insertTuple(snapTable, 67890, "L. Van Pelt", "34 Pear Ave.", "555-5678");
  insertTuple(snapTable, 22222, "P. Patty", "56 Grape Blvd.", "555-9999");
  deleteTuple(snapTable, 22222, "P. Patty", "56 Grape Blvd.", "555-9999");
  printTable(snapTable);

  struct CR** crTable = createTable();
  insertTuple(crTable, "CS101", "Turing Aud");
  insertTuple(crTable, "EE200", "25 Ohm Hall");
  insertTuple(crTable, "PH100", "Newton Lab");
  printTable(crTable);
  printf("Delete Tuple with EE200 in 25 Ohm Hall\n");
  deleteTuple(crTable, "EE200", "25 Ohm Hall");
  printTable(crTable);
  printf("Lookup Tuple with CSC101 in Turing Aud.\n");
  lookup(crTable, "CS101", "Turing Aud");
}
