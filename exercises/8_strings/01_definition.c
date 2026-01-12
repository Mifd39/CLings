// Learning Goal: Understand C strings (null-terminated char arrays).
/*
    Context:
    Unlike other languages, C doesn't have a "String" type.
    Instead, it treats text as an array of characters.
    But how does the computer know where the text ends?
    It uses a special invisible character called the "null terminator" ('\0') to mark the end of the string.
*/
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
    // TODO: Declare a string variable named 'greeting' containing "Hello, C!".


    printf("%s\n", greeting);

    char my_string[] = "I love C programming";

    // TODO: Change 'C' to 'Z' in 'my_string'.


    printf("%s\n", my_string);

    return 0;
}
