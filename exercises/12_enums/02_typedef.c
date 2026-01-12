// Learning Goal: Use typedef with Enum to simplify types.
/*
    Context:
    Programmers are lazy (in a good way!). Typing `enum Status` or `struct Person` everywhere gets tiring.
    C provides `typedef` (Type Definition) to create a shortcut or alias for a data type.
    So instead of writing `enum Status myStatus`, you can just write `Status myStatus`. Clean and simple.
*/
//
// 'typedef' allows you to give a new name to an existing type.
// Often used with enums and structs to avoid typing 'enum' or 'struct' every time.
//
// Syntax:
// typedef enum { ERROR, WARNING, INFO } LogLevel;

#include <stdio.h>

// I AM NOT DONE

// TODO: Define a typedef'd enum 'Status' (PENDING, APPROVED, REJECTED).


void print_status(Status s) {
    if (s == PENDING) printf("Status: Pending\n");
    else if (s == APPROVED) printf("Status: Approved\n");
    else if (s == REJECTED) printf("Status: Rejected\n");
}

int main() {
    // TODO: Set 'my_status' to APPROVED.


    print_status(my_status);

    if (my_status == APPROVED) {
        printf("Status approved correctly.\n");
    } else {
        printf("Expected status to be APPROVED.\n");
        return 1;
    }

    return 0;
}
