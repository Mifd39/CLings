// Learning Goal: Access struct members.
#include <stdio.h>
#include <string.h>

// I AM NOT DONE

struct Person {
    char name[50];
    int age;
};

int main() {
    struct Person p;

    // TODO: Initialize the person's name to "Bob" (use strcpy) and age to 25

    printf("Name: %s, Age: %d\n", p.name, p.age);
    return 0;
}
