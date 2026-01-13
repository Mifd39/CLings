// Learning Goal: Append data to an existing file without overwriting it.
/*
    Context:
    "w" mode wipes the file clean. "a" (append) mode adds to the end.
    This is useful for logs or growing datasets.
*/

#include <stdio.h>

// I AM NOT DONE

void setup_file() {
    FILE *f = fopen("/tmp/log.txt", "w");
    if (f) {
        fprintf(f, "Log entry 1\n");
        fclose(f);
    }
}

int main() {
    setup_file();

    // TODO: Append "Log entry 2\n" to "/tmp/log.txt".
    FILE *file = NULL;

    if (!file) {
        printf("Failed to open file for appending.\n");
        return 1;
    }



    fclose(file);

    // Verify content (for your info)
    FILE *check = fopen("/tmp/log.txt", "r");
    char buffer[100];
    while(fgets(buffer, sizeof(buffer), check)) {
        printf("%s", buffer);
    }
    fclose(check);

    return 0;
}
