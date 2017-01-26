/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

/* Creates a local array and sets all values to 42,
returns created array */
int *foo() {
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
	array[i] = 42;
    }
    return array;
}

/* Creates a local array and sets each value equal to its index.
It returns nothing */
void bar() {
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
	array[i] = i;
    }
}

/* Runs foo and stores the returned array, then runs bar, then prints out
each element of array. Expected to return [42,42,42,42,42]. */

/* When compiled, returns 
"warning: function returns address of local variable [-Wreturn-local-addr]",
which indicates that foo returns a local array which can cause problems. */

/* When ran, it segfaults. However, I think the point of this code is that
it should print out [0,1,2,3,4], which is the array from bar */

/* After uncommenting the print statements in foo and bar, it is clear that 
the two pointers point to the same memory address. This is because each
function allocates the arrays in precisely the same memory location.
Because of the order of the calls, foo and bar occupy the same location in 
the stack sequentially. This means that when the array in the stack is 
dereferenced when foo returns, the pointer still points to this memory. 
When bar then create the array in the same memory, the pointer still points
to the new array. If the data in that memory is not cleared by the time
the print loop in main runs, it can print out data that is not allocated to
either array. */

int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
	printf("%d\n", array[i]);
    }

    return 0;
}
