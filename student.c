#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "student.h"

Student *createEmptyStudent() { 
  return createStudent("", "", 0, ""); 
}

Student *createStudent(const char *firstName, const char *lastName, int nuid,
                       const char *birthDate_str) {
  Student *student = (Student *)malloc(sizeof(Student) * 1);

  student->firstName = (char *)malloc(sizeof(char) * (strlen(firstName) + 1));
  strcpy(student->firstName, firstName);

  student->lastName = (char *)malloc(sizeof(char) * (strlen(lastName) + 1));
  strcpy(student->lastName, lastName);

  student->nuid = nuid;

  strptime(birthDate_str, "%m/%d/%Y", &(student->birthDate));

  return student;
}

void initStudent(Student *student,
                 const char *firstName, const char *lastName, int nuid,
                 const char *birthDate_str) {
  student->firstName = (char *)malloc(sizeof(char) * (strlen(firstName) + 1));
  strcpy(student->firstName, firstName);

  student->lastName = (char *)malloc(sizeof(char) * (strlen(lastName) + 1));
  strcpy(student->lastName, lastName);

  student->nuid = nuid;

  strptime(birthDate_str, "%m/%d/%Y", &(student->birthDate));
  
  return;
}


char *studentToString(const Student *student) {
  if (student == NULL) {
    char *result = (char *)malloc(sizeof(char) * 7);
    strcpy(result, "(null)");
    return result;
  }

  // compute the number of characters we'll need:
  int n = strlen(student->lastName) + strlen(student->firstName) + 8 + 10 +
          (2 + 2 + 2 + 1) + 1;

  // create a result string
  char *str = (char *)malloc(sizeof(char) * n);

  // format the student into the temporary string
  sprintf(str, "%s, %s (%08d, %4d-%02d-%02d)", student->lastName,
          student->firstName, student->nuid,
          (student->birthDate.tm_year + 1900), (student->birthDate.tm_mon + 1),
          student->birthDate.tm_mday);

  // return the result
  return str;
}

void printStudent(const Student *student) {
  char *str = studentToString(student);
  printf("%s\n", str);
  free(str);
  return;
}

