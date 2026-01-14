// Learning Goal: Understand how to use nested structs (a struct inside another struct).
/*
    Context:
    Real-world data is often hierarchical. A "Person" has an "Address", but an "Address" itself consists of a street, city, and zip code.
    Instead of flattening everything into one big struct (person_street, person_city...), you can put the Address struct *inside* the Person struct.
    This "nested struct" approach keeps your data organized and logical, like folders within folders.
*/

#include <stdio.h>
#include <string.h>

// I AM NOT DONE

struct Address {
    char street[50];
    char city[50];
    int zip_code;
};

struct Person {
    char name[50];
    int age;
    // TODO: Add a member 'addr' of type 'struct Address' to this struct.

};

int main() {
    struct Person p1;

    strcpy(p1.name, "Alice");
    p1.age = 30;

    // TODO: Initialize the nested address fields:
    // Set street to "123 Wonder St", city to "Wonderland", and zip_code to 12345.
    // Hint: Use dot notation twice! e.g., p1.addr.field


    printf("Person: %s, City: %s\n", p1.name, p1.addr.city);

    return 0;
}
