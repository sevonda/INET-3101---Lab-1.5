#include <stdio.h>
#include "mathheader.h"  // Own header included

//both objects of header created
int addTwoInts(int a, int b) {
    return a + b;
}

int subtractTwoInts(int a, int b) {
    return a - b;
}

int main() {

    // variables that will be computed defined and operated with header math
    int a = 4, b = 5;

    int sum = addTwoInts(a, b);
    int Subtraction= subtractTwoInts(a, b);


    //results printed accordingly
    printf("Sum  %d and %d: %d\n", a, b, sum);
    printf("Subtraction of %d and %d: %d\n", a, b, Subtraction);

    return 0;
}
