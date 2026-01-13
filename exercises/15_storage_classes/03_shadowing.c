// Learning Goal: Understand variable shadowing.
/*
    Context:
    If you declare a local variable with the same name as a global variable,
    the local one "shadows" (hides) the global one within that function.
    This can be confusing, so be careful!
*/

#include <stdio.h>

// I AM NOT DONE

int value = 100; // Global variable

void print_global() {
    printf("Global value: %d\n", value);
}

int main() {
    // TODO: Create a local variable named 'value' with the value 5 to shadow the global one.


    printf("Local value: %d\n", value);

    // This function should still see the global value (100)
    print_global();

    return 0;
}
