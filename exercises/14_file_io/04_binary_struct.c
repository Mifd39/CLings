// Learning Goal: Write and read raw binary data using fwrite and fread.
/*
    Context:
    fprintf writes text (human readable). fwrite writes raw bytes (machine readable).
    This is more efficient for saving numbers or structs directly because it skips formatting.
*/

#include <stdio.h>

// I AM NOT DONE

typedef struct {
    int x;
    int y;
} Point;

int main() {
    Point p1 = {10, 20};
    Point p2 = {0, 0};

    // TODO: Write 'p1' to "/tmp/point.bin" in binary mode.
    FILE *f_write = NULL;


    // TODO: Read the struct back from "/tmp/point.bin" into 'p2'.
    FILE *f_read = NULL;


    printf("Read Point: x=%d, y=%d\n", p2.x, p2.y);
    return 0;
}
