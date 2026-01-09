// Learning Goal: Understand C strings (null-terminated char arrays).
//
// In C, a string is just an array of characters ending with a special 'null terminator' character: '\0'.
//
// You can initialize a string literal like this:
// char str[] = "Hello";
// This automatically adds the '\0' at the end.
// The array size will be 6 (5 letters + 1 null terminator).

#include <stdio.h>
#include <string.h>

// I AM NOT DONE

int main() {
    // TODO: Declare a char array named 'greeting' with the value "Hello, C!".


    printf("%s\n", greeting);

    char my_string[] = "I love C programming";

    // TODO: Change the character 'C' to 'Z' in 'my_string' by accessing the array index.
    // Count carefully to find the index of 'C'.


    printf("%s\n", my_string);

    return 0;
}
