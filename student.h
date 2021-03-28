#include <time.h>

/**
 * A structure modeling a UNL student with
 * first name, last name, nuid and a birth date
 * (as a tm, "time" structure)
 */
typedef struct {
  char *firstName;
  char *lastName;
  int nuid;
  struct tm birthDate;
} Student;

/**
 * Creates an "empty" Student struct with default values
 */
Student *createEmptyStudent();

/**
 * Creates a Student struct with the given values
 */
Student *createStudent(const char *firstName, const char *lastName, int nuid,
                       const char *birthDate_str);

/**
 * Initializes the given Student sturcture with the
 * given values
 */
void initStudent(Student *student,
                 const char *firstName, const char *lastName, int nuid,
                 const char *birthDate_str);

/**
 * Prints the given Student struct to the standard output
 */
void printStudent(const Student *student);

/**
 * Returns a string representation of the given student
 */
char *studentToString(const Student *student);


