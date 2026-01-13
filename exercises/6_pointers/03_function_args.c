// Learning Goal: Pass pointers to functions (Pass by Reference).
/*
    Context:
    Normally, when you pass a variable to a function, C makes a COPY of it.
    If the function changes the copy, the original variable remains untouched.
    But what if you WANT the function to change the original?
    You pass the address (pointer) instead. This allows the function to reach back and modify the original data.
*/

#include <stdio.h>

// I AM NOT DONE

// TODO: Define a function named 'swap' that accepts two integer pointers and swaps their values.


int main() {
    int a = 5, b = 10;
    printf("Before swap: a = %d, b = %d\n", a, b);

    // TODO: Call 'swap' to exchange the values of 'a' and 'b'.


    printf("After swap: a = %d, b = %d\n", a, b);
    return 0;
}
