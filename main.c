#include <stdio.h>
#include <string.h>

void foo(int *bar);

int main()
{
    // sizeof(char) = 1 byte =  4 bits
    // sizeof(int)  = 4 byte = 16 bits
    // a pointer is an int that holds a memory address

    int count = 0;
    foo(&count);
    printf("%d\n", count);

    return 0;
}

void foo(int *bar)
{
    (*bar)++;
}