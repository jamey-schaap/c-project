#include <stdio.h>
#include <stdlib.h>

typedef int (*cmp_t)(const void *, const void *);

int compare(const void *left, const void *right)
{
    printf("%p\n", (int*)left);
    return (*(int *)right - *(int *)left);
}

int main()
{
    // int (*cmp)(const void *, const void *);
    cmp_t cmp;
    cmp = &compare;

    int arr[] = {0, 1, 2, 3, 4};

    qsort(arr, sizeof(arr) / sizeof(*arr), sizeof(*arr), cmp);

    int c = 0;
    while (c < sizeof(arr) / sizeof(*arr))
    {
        printf("%d \t", arr[c]);
        c++;
    }

    return 0;
}