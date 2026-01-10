// Learning Goal: Use string functions from <string.h>.
//
// The standard library <string.h> provides many useful functions for working with strings.
// 'strlen(s)' returns the length of the string 's' (excluding the null terminator).

#include <stdio.h>
#include <string.h>

// I AM NOT DONE

int main() {
    char message[] = "Hello C Programming";

    // TODO: Use strlen() to get the length of the string 'message'.
    size_t length = 0;


    // Note: %zu is the correct format specifier for size_t.
    printf("The length of the message is %zu\n", length);
    return 0;
}
