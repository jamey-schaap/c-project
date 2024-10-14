#include <stdio.h>
#include <string.h>

void foo(int *bar);

int main()
{
    // sizeof(char) = 1 byte =  8 bits
    // sizeof(int)  = 4 byte = 32 bits
    // a pointer is an int that holds a memory address

    int count = 0;
    foo(&count);
    printf("%d\n", count);

    int arr[] = {1, 2, 3};
    printf("%lu\n", sizeof(arr) / sizeof(int));

    return 0;
}

void foo(int *bar)
{
    (*bar)++;
}