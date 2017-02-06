/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int global;

int print_local()
{
    int to_print = 10;
    printf ("Address of to_print is %p\n", &to_print);
}

int main ()
{
    void *chunk1 = malloc(13);

    int local = 5;
    void *new_malloc = malloc(128);
    void *p = malloc(128);

    printf ("Address of main is %p\n", main);
    printf ("Address of global is %p\n", &global);
    printf ("Address of local is %p\n", &local);
    printf ("Address of p is %p\n", p);
    printf ("Address of new_malloc is %p\n", new_malloc);
    print_local();

    void *chunk2 = malloc(13);    
    printf ("Address of chunk1 is %p\n", chunk1);
    printf ("Address of chunk2 is %p\n", chunk2);
    
    return 0;
}
