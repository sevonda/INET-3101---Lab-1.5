// In this example, when the user runs the program they have to specify how big they want the allocation to be.
// The allocation is going to store integers
// So you'd run it like this:
//   ./program-name 5
// Thusly it allocates space for 5 integers: 32-bits/4-bytes each.

#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <number_of_elements>\n", argv[0]);
        return 1;
    }

    int num_elements = atoi(argv[1]);
    int capacity = num_elements; 
    int *array = (int *)malloc(capacity * sizeof(int));

    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int count = 0; //Maintains count of while loop iteration
    int number;  //number from user
    printf("If you want to enter more numbers, you can do so now.\n");
    printf("Enter a letter if you wish to stop :\n");

    while (1) {
        printf("Enter a new number: ");

        // Check if input is a number
        if (scanf("%d", &number) != 1) {
            printf("You have opted for exiting.\n");
            break; // 
        }

        // if capacity is more than the count, then capacity increases by one
        if (count >= capacity) {
            capacity += 1;
            int *temp = (int *)realloc(array, capacity * sizeof(int));

            if (temp == NULL) {
                printf("Memory reallocation failed.\n");
                free(array);
                return 1;
            }

            array = temp; // array alteration is not being changed to the array
        }

        array[count] = number; //Array is given the value of the input
        count++;
    }

    printf("Numbers in the array:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array); // Disallocating heap pre saved values
    return 0;
}

/* 

WHAT TO DO:

MODIFY THIS CODE

Continue to prompt the user for the number of elements.  This will be the "starting size" of the allocated memory

Replace the FOR loop for entering numbers into the array with a never ending WHILE loop.

Continuously prompt the user to enter more numbers. 

Continuously check to see how big the array is getting.

For example, the user specified to start with 5 items in the allocated memory.

They've now entered 5 items and want to add a 6th.

We now need to resize and move the array.   

What do we need to do?

Research and come up with a solution.

Use the guide and examples at W3SCHOOLS. It has a good example of using reallocate.

Another good example is in file 7-managing-allocation-with-struct.case

You don't need to write code like that example, but look at how they do it in the "addToList" function.

Indeed you can see what CoPilot says (I would prefer you use CoPilot) to.

But you must understand why the solution works. Don't copy/paste.

Write a short paragraph about your approach and why is solves the problem.

Modify the code with your approach/code and make it work.

*/