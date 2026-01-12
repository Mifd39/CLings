// Learning Goal: Write and read raw binary data using fwrite and fread.
/*
    Context:
    fprintf writes text (human readable). fwrite writes raw bytes (machine readable).
    This is more efficient for saving numbers or structs directly because it skips formatting.
*/
//
// Write a 'Point' struct to a file, then read it back.
//

#include <stdio.h>

// I AM NOT DONE

typedef struct {
    int x;
    int y;
} Point;

int main() {
    Point p1 = {10, 20};
    Point p2 = {0, 0};

    // TODO: Open "/tmp/point.bin" in write binary mode ("wb").
    FILE *f_write = NULL;

    if (!f_write) return 1;

    // TODO: Use fwrite to write 'p1' to the file.
    // Syntax: fwrite(&data, sizeof(Type), count, file_pointer);


    fclose(f_write);

    // TODO: Open "/tmp/point.bin" in read binary mode ("rb").
    FILE *f_read = NULL;

    if (!f_read) return 1;

    // TODO: Use fread to read into 'p2'.


    fclose(f_read);

    printf("Read Point: x=%d, y=%d\n", p2.x, p2.y);
    return 0;
}
