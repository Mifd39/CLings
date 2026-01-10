// Learning Goal: Understand how to define and use structs.
/*
    Context:
    Sometimes data doesn't fit neatly into a single variable.
    For example, a "Person" has a name (string) AND an age (integer).
    You could create separate arrays for names and ages, but that gets messy.
    C lets you create your own custom data type called a "struct" (structure) to package these related items together into a single object.
*/
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

// TODO: Define a struct named 'Person' that holds a name (string of size 50) and an age (integer).


int main() {
    // TODO: Create an instance of 'struct Person' named 'p1'.


    // TODO: Set p1.name to "Alice" and p1.age to 30.


    printf("Name: %s, Age: %d\n", p1.name, p1.age);

    return 0;
}
