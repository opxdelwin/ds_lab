#include <stdio.h>
#include <stdlib.h>

/*
Enter the number of elements: 5
Enter the array elements: 1 3 2 3 3
Array with distinct elements: 1 3 2

Enter the number of elements: 7
Enter the array elements: 1 3 4 3 2 6 6
Array with distinct elements: 1 3 4 2 6
*/

void removeDuplicates(int *arr, int *size)
{
    int i, j, k;
    for (i = 0; i < *size; i++)
    {
        for (j = i + 1; j < *size;)
        {
            if (arr[j] == arr[i])
            {
                for (k = j; k < *size; k++)
                {
                    arr[k] = arr[k + 1];
                }
                (*size)--;
            }
            else
            {
                j++;
            }
        }
    }
}

int main()
{
    int *arr, size, i;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    arr = (int *)malloc(size * sizeof(int));

    printf("Enter the array elements: ");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    removeDuplicates(arr, &size);

    printf("Array with distinct elements: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}