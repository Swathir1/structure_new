#include <stdlib.h>

#include "student.h"

/**
 * Student structure demonstration program
 */
int main(int argc, char **argv) {
  Student *me = createStudent("Joe", "Smith", 140602, "07/30/1980");
  printStudent(me);
}

