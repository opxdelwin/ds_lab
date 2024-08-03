#include <stdio.h>
#include <stdlib.h>
/*
SET-1
    Enter number of elements: 5
    Enter 1th element: -4
    Enter 2th element: 6
    Enter 3th element: 3
    Enter 4th element: 9
    Enter 5th element: 2

    Enter number to find: 9
    Found element 9 at index 3

SET-2
    Enter number of elements: 5
    Enter 1th element: 10
    Enter 2th element: 20
    Enter 3th element: 50
    Enter 4th element: 35
    Enter 5th element: 22

    Enter number to find: 50
    Found element 50 at index 2
*/
int main()
{
    int *arr;
    int n, searchElement;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("Enter %dth element: ", i + 1);
        scanf("%d", arr + i);
    }

    printf("\nEnter number to find: ");
    scanf("%d", &searchElement);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == searchElement)
        {
            printf("Found element %d at index %d", arr[i], i);
            return 0;
        }
    }

    printf("Element not found in the array.");
    free(arr);
    return 0;
}