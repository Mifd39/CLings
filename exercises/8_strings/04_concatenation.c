// Learning Goal: Understand String Concatenation.
/*
    Context:
    Sometimes you have two separate pieces of text that belong together, like "First Name" and "Last Name".
    Joining them into a single string is called "concatenation".
    In C, you have to be careful: the destination string must have enough empty space (memory) to hold the new addition.
    If you try to stuff too many characters into a small array, you'll overflow the buffer!
*/
//
// The 'strcat' function appends one string to another.
// Make sure the destination buffer is large enough!
//
// #include <string.h> is required.

#include <stdio.h>
#include <string.h>

// I AM NOT DONE

int main() {
    char greeting[50] = "Hello, ";
    char name[] = "World!";

    // TODO: Use 'strcat' to append 'name' to 'greeting'.


    printf("Result: %s\n", greeting);

    if (strcmp(greeting, "Hello, World!") == 0) {
        printf("String concatenation correct!\n");
    } else {
        printf("Expected 'Hello, World!', got '%s'\n", greeting);
        return 1;
    }

    return 0;
}
