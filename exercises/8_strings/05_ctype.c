// Learning Goal: Understand character handling functions in <ctype.h>.
/*
    Context:
    Often you need to check if a character is a letter, a number, or convert it to uppercase.
    Instead of writing complex 'if' statements like (c >= 'A' && c <= 'Z'),
    C provides standard functions in <ctype.h> to do this for you.
*/

#include <stdio.h>
#include <string.h>
// I AM NOT DONE

// TODO: Include the correct header file for character handling.

// TODO: Implement the function to convert the string to uppercase using the standard library.
void convert_to_upper(char *str) {


}

int main() {
    char text[] = "Hello World!";
    convert_to_upper(text);
    printf("%s\n", text);
    return 0;
}
