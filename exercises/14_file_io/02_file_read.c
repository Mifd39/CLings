// Learning Goal: Read text from a file using fscanf or fgets.
/*
    Context:
    Reading from a file is similar to writing.
    1. Open it with 'fopen(filename, "r")' (read mode).
    2. Read content using 'fscanf(fp, ...)' or 'fgets(buffer, size, fp)'.
    3. Close it.
*/
//
// First, we'll write a file so we have something to read.
// Then, you will open it and read the number inside.
//

#include <stdio.h>

// I AM NOT DONE

void create_test_file() {
    FILE *f = fopen("/tmp/number.txt", "w");
    if (f) {
        fprintf(f, "42");
        fclose(f);
    }
}

int main() {
    create_test_file(); // Setup the file

    // TODO: Open "/tmp/number.txt" in read mode ("r").
    FILE *file =

    if (file == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    int number;
    // TODO: Read an integer from the file into the variable 'number' using fscanf.


    fclose(file);
    printf("Read number: %d\n", number);
    return 0;
}
