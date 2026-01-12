// Learning Goal: Use string functions from <string.h>.
/*
    Context:
    When processing text, one of the most common questions is "How long is this string?".
    Maybe you need to check if a password is long enough, or fit text into a specific display area.
    The C standard library (`string.h`) gives you a ready-made tool for this called `strlen` (String Length).
*/
//
// The standard library <string.h> provides many useful functions for working with strings.
// 'strlen(s)' returns the length of the string 's' (excluding the null terminator).

#include <stdio.h>
#include <string.h>

// I AM NOT DONE

int main() {
    char message[] = "Hello C Programming";
    size_t length = 0;

    // TODO: Determine the length of 'message' and store it in 'length'.


    // Note: %zu is the correct format specifier for size_t.
    printf("The length of the message is %zu\n", length);
    return 0;
}
