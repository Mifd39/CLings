// Learning Goal: Understand String Concatenation.
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
