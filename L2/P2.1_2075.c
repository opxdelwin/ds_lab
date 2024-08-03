#include <stdio.h>

/*
SET-1
    Enter the number of elements: 3
    Enter 1th element: 1
    Enter 2th element: 2
    Enter 3th element: 3
    3 2 1
SET-2
    Enter the number of elements: 4
    Enter 1th element: 4
    Enter 2th element: 3
    Enter 3th element: 2
    Enter 4th element: 1
    1 2 3 4
*/

int main()
{
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter %dth element: ", i + 1);
        scanf("%d", arr + i);
    }

    int left = 0;
    int right = n - 1;

    while (right - left >= 1 && left != right)
    {
        int temp = arr[left];
        arr[left] = arr[right];

        arr[right] = temp;
        left++;
        right--;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}