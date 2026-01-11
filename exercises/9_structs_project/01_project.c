// Learning Goal: Build a complete Contact Management System using structs, arrays, and loops.
/*
    Context:
    This is your first major project! You will build a "Classroom Manager".
    You need to manage a collection of Students. Each student has a name and a grade.

    The system should accept commands from the user to:
    1. ADD a new student.
    2. UPDATE a student's grade.
    3. PRINT all students.
    4. CALCULATE the average grade.
    5. EXIT the program.

    Input Format:
    Commands are single words followed by arguments.
    - ADD <Name> <Grade>
    - UPDATE <Name> <NewGrade>
    - PRINT
    - AVERAGE
    - EXIT

    Example Input:
    ADD Alice 85
    ADD Bob 90
    UPDATE Alice 88
    PRINT
    AVERAGE
    EXIT
*/

#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define NAME_LENGTH 50

// I AM NOT DONE

// TODO: Define the Student struct
// typedef struct {
//     char name[NAME_LENGTH];
//     int grade;
// } Student;


// Global array of students
// Student class_roster[MAX_STUDENTS];
// int student_count = 0;


// Function Prototypes (Hints)
// void add_student(char* name, int grade);
// void update_student(char* name, int grade);
// void print_students();
// void print_average();

int main() {
    char command[20];
    char name[NAME_LENGTH];
    int grade;

    // Hints:
    // Use a while(1) loop to continuously read commands.
    // Use scanf("%s", command) to read the command.
    // Use strcmp(command, "ADD") == 0 to check the command.
    // Use scanf to read arguments based on the command.

    // Example loop structure:
    /*
    while (1) {
        scanf("%s", command);
        if (strcmp(command, "EXIT") == 0) {
            break;
        } else if (strcmp(command, "ADD") == 0) {
            scanf("%s %d", name, &grade);
            add_student(name, grade);
        }
        // ... other commands
    }
    */

    return 0;
}
