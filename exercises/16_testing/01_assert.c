// Learning Goal: Use assert to verify assumptions during debugging.
/*
    Context:
    When writing code, you often assume certain conditions are true (e.g., "age cannot be negative").
    The 'assert' macro (from <assert.h>) lets you verify these assumptions.
    If the condition is false, the program crashes with a helpful error message.
    This is critical for catching bugs early!
*/
//
// Include <assert.h> and verify that the 'calculate_area' function works correctly.
//

#include <stdio.h>
#include <assert.h>

// I AM NOT DONE

int calculate_area(int width, int height) {
    if (width < 0 || height < 0) {
        return -1; // Error code
    }
    return width * height;
}

int main() {
    // TODO: Assert that calculating area of 5 and 10 equals 50.


    // TODO: Assert that calculating area of -1 and 10 equals -1 (error case).


    printf("All tests passed!\n");
    return 0;
}
