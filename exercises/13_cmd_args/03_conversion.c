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

    // TODO: Convert argv[1] and argv[2] to integers using atoi().
    int num1 =
    int num2 =

    int sum = num1 + num2;
    printf("Sum: %d\n", sum);

    return 0;
}
