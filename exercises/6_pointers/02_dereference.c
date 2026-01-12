// Learning Goal: Modify values using pointers (Dereferencing).
/*
    Context:
    Once you have a pointer (an address), you can "follow" it to access or change the actual value stored there.
    This is called "dereferencing".
    It's like having a key to a locker; you can open it to see what's inside or swap the contents.
*/
//
// You can use the '*' (dereference) operator to modify the value a pointer points to.
//
// Example:
// int a = 10;
// int *ptr = &a;
// *ptr = 20; // This changes the value of 'a' to 20

#include <stdio.h>

// I AM NOT DONE

int main() {
    int x = 10;
    int *p = &x;

    // TODO: Update the value of 'x' to 20 using only the pointer 'p'.


    printf("The value of x is %d\n", x);
    return 0;
}
