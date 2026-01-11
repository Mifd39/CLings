// Learning Goal: Understand character handling functions in <ctype.h>.
/*
    Context:
    Often you need to check if a character is a letter, a number, or convert it to uppercase.
    Instead of writing complex 'if' statements like (c >= 'A' && c <= 'Z'),
    C provides standard functions in <ctype.h> to do this for you.
*/
//
// <ctype.h> provides functions like:
// - isalpha(c): checks if c is a letter
// - isdigit(c): checks if c is a number
// - toupper(c): converts c to uppercase
// - tolower(c): converts c to lowercase
//

#include <stdio.h>
#include <string.h>
// I AM NOT DONE

void convert_to_upper(char *str) {
    // TODO: Loop through the string and convert each character to uppercase using toupper().
    // Hint: You can modify the string in place.
    for (int i = 0; str[i] != '\0'; i++) {

    }
}

int main() {
    char text[] = "Hello World!";
    convert_to_upper(text);
    printf("%s\n", text);
    return 0;
}
