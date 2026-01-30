// Learning Goal: Understand how to define and use Enums.
/*
    Context:
    Using magic numbers like 0, 1, or 2 in your code is confusing.
    Does '1' mean "Monday"? Does it mean "True"? Or "Error"?
    Enums (Enumerations) let you replace these mysterious numbers with meaningful words.
    This makes your code much easier to read and understand.
*/
//
// An 'enum' (enumeration) is a user-defined type that consists of a set of named integer constants.
// By default, the first constant is 0, the next is 1, and so on.
//
// Syntax:
// enum Color { RED, GREEN, BLUE };

#include <stdio.h>

// I AM NOT DONE

// TODO: Define an enum 'Day' (MONDAY=1, TUESDAY, etc.).


int main() {
    // TODO: Create a variable 'today' of type 'enum Day' and set it to WEDNESDAY.


    if (today == WEDNESDAY) {
        printf("It is Wednesday, my dudes.\n");
    } else {
        printf("It is not Wednesday.\n");
        return 1;
    }

    return 0;
}
