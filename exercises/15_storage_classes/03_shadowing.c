// Learning Goal: Understand variable shadowing.
/*
    Context:
    If you declare a local variable with the same name as a global variable,
    the local one "shadows" (hides) the global one within that function.
    This can be confusing, so be careful!
*/
//
// 1. A global 'value' exists.
// 2. Create a local 'value' in main and print it.
// 3. Observe that the global one is unchanged.
//

#include <stdio.h>

// I AM NOT DONE

int value = 100; // Global variable

void print_global() {
    printf("Global value: %d\n", value);
}

int main() {
    // TODO: Shadow the global 'value' with a local variable set to 5.


    printf("Local value: %d\n", value);

    // This function should still see the global value (100)
    print_global();

    return 0;
}
