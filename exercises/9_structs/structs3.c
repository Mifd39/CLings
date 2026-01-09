// Learning Goal: Use pointers to structs and the arrow operator.
#include <stdio.h>

// I AM NOT DONE

struct Point {
    int x;
    int y;
};

int main() {
    struct Point p1 = {10, 20};
    struct Point *ptr = &p1;

    // TODO: Use the arrow operator (->) to print the x and y values via the pointer 'ptr'
    printf("Point coordinates: (%d, %d)\n", );

    return 0;
}
