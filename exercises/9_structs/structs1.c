// Learning Goal: Understand how to define and use structs.
//
// A 'struct' (structure) is a user-defined data type that groups related variables.
//
// Syntax:
// struct MyStruct {
//     int field1;
//     char field2;
// };
//
// To use it: struct MyStruct my_var;

#include <stdio.h>
#include <string.h>

// I AM NOT DONE

// TODO: Define a struct named 'Person' with two fields:
// - name (char array of size 50)
// - age (int)


int main() {
    // TODO: Create an instance of 'struct Person' named 'p1'.
    // Remember the 'struct' keyword is part of the type name in C.


    // TODO: Set p1.name to "Alice" and p1.age to 30.
    // Hint: Strings cannot be assigned directly with =. Use 'strcpy(destination, source)' from string.h.
    // e.g., strcpy(p1.name, "Alice");


    printf("Name: %s, Age: %d\n", p1.name, p1.age);

    return 0;
}
