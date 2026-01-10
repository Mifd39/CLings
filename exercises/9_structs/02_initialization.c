// Learning Goal: Access struct members.
/*
    Context:
    Once you've created a struct variable, it's just a container.
    To put things inside or look at them, you need to open the specific compartment you're interested in.
    In C, we use the "dot operator" (.) to access individual members of a struct.
    It's like saying "I want the 'name' FROM 'person'".
*/
//
// You can access members of a struct using the dot (.) operator.
// example.member = value;

#include <stdio.h>
#include <string.h>

// I AM NOT DONE

struct Person {
    char name[50];
    int age;
};

int main() {
    struct Person p;

    // TODO: Initialize the person's name to "Bob" and age to 25.


    printf("Name: %s, Age: %d\n", p.name, p.age);
    return 0;
}
