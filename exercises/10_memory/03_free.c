// Learning Goal: Understand the importance of freeing memory.
/*
    Context:
    When you borrow a book from the library, you have to return it so others can use it.
    The same rule applies to computer memory.
    If you keep asking for memory with `malloc` but never give it back with `free`,
    you will eventually run out of space. This is called a "Memory Leak".
    Be a responsible programmer: always clean up after yourself!
*/
//
// Every time you use 'malloc', you should have a corresponding 'free'.
// If you don't free memory, it stays occupied until your program ends (Memory Leak).
// In long-running programs, this can use up all available RAM!

#include <stdio.h>
#include <stdlib.h>

// I AM NOT DONE

int main() {
    // Allocating memory for 100 integers
    int *data = (int *)malloc(100 * sizeof(int));

    if (data == NULL) {
        return 1;
    }

    // Work with data...
    data[0] = 100;
    printf("Data allocated and used.\n");

    // TODO: Prevent a memory leak.


    return 0;
}
