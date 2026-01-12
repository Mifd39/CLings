// Learning Goal: Write text to a file using fopen, fprintf, and fclose.
/*
    Context:
    Files are the most common way to store data permanently.
    To write to a file:
    1. Open it with 'fopen(filename, mode)'. Use "w" for write mode.
    2. Write to it with 'fprintf(file_pointer, format, ...)', just like printf.
    3. Close it with 'fclose(file_pointer)'.
*/
//
// Open a file named "/tmp/hello.txt" and write "Hello, File!" to it.
// Note: We use /tmp because the sandbox allows writes there.
//

#include <stdio.h>

// I AM NOT DONE

int main() {
    // TODO: Open "/tmp/hello.txt" and write "Hello, File!" to it.
    FILE *file = NULL;

    if (file == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }



    printf("File written successfully.\n");
    return 0;
}
