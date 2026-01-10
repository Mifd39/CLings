// Learning Goal: Use pointers to structs and the arrow operator.
/*
    Context:
    When you pass a struct to a function, it's often more efficient to pass a pointer (the address) rather than copying the whole thing.
    But accessing members via a pointer looks a bit clumsy: `(*ptr).x`.
    C gives us a syntactic shortcut for this very common operation: the "arrow operator" (`->`).
    It looks like an arrow pointing to the member you want!
*/
//
// When you have a pointer to a struct, you can access its members using the arrow operator (->).
//
// struct Point *ptr = &p1;
// ptr->x = 5;  // Equivalent to (*ptr).x = 5;

#include <stdio.h>

// I AM NOT DONE

struct Point {
    int x;
    int y;
};

int main() {
    struct Point p1 = {10, 20};
    struct Point *ptr = &p1;

    // TODO: Use the pointer 'ptr' to print the coordinates of the point using the arrow operator.
    printf("Point coordinates: (%d, %d)\n", );

    return 0;
}
