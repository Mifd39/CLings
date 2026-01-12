// Learning Goal: Convert command line string arguments to numbers.
/*
    Context:
    Command line arguments are always strings (char arrays).
    If you pass "123", it's the string "123", not the number 123.
    To do math, you must convert them using functions like:
    - atoi(str): Converts string to int (simple, but less safe).
    - strtol(str, &end, 10): Converts string to long int (safer, handles errors).
*/
//
// Include <stdlib.h> to use atoi().
//

#include <stdio.h>
#include <stdlib.h>

// I AM NOT DONE

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Please provide two numbers.\n");
        return 1;
    }

    // TODO: Convert arguments to integers and calculate their sum.
    int sum = 0;


    printf("Sum: %d\n", sum);

    return 0;
}
