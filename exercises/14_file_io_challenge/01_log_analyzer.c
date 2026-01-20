// Learning Goal: Read a log file and analyze its contents.
/*
    Context:
    System administrators and DevOps engineers often write scripts to parse log files.
    They look for error messages, warnings, or specific events.
    In this challenge, you will read a "server log" and count the number of errors.
*/

#include <stdio.h>
#include <string.h>

// I AM NOT DONE

void create_log_file() {
    FILE *f = fopen("/tmp/server.log", "w");
    if (f) {
        fprintf(f, "[INFO] Server started\n");
        fprintf(f, "[ERROR] Connection failed\n");
        fprintf(f, "[INFO] User logged in\n");
        fprintf(f, "[ERROR] Database timeout\n");
        fprintf(f, "[WARN] High memory usage\n");
        fprintf(f, "[ERROR] Disk full\n");
        fprintf(f, "[INFO] Server stopping\n");
        fclose(f);
    }
}

int main() {
    create_log_file(); // Setup the test file

    // TODO: Open "/tmp/server.log" for reading.
    //       If it fails, print an error and return 1.

    // TODO: Read the file line by line.
    //       Check if the line contains "[ERROR]".
    //       (Hint: use fgets() to read a line, and strstr() to find a substring).

    int error_count = 0;

    // ... your loop here ...

    printf("Error count: %d\n", error_count);

    return 0;
}
