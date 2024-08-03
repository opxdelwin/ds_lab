#include <stdio.h>
/*

SET-1
    Enter number of elements: 5
    Enter 1th element: -3223
    Enter 2th element: 43
    Enter 3th element: 5
    Enter 4th element: 32
    Enter 5th element: 2
    Smallest -3223, and Largest: 43

SET-2
    Enter number of elements: 7
    Enter 1th element: 10
    Enter 2th element: 20
    Enter 3th element: 15
    Enter 4th element: 25
    Enter 5th element: 90
    Enter 6th element: 45
    Enter 7th element: 80
    Smallest 10, and Largest: 90

*/
int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int list[n];
    int smallest = NULL;
    int largest = NULL;

    for (int i = 0; i < n; i++)
    {
        int data;
        printf("Enter %dth element: ", i + 1);
        scanf("%d", &data);
        if (data < smallest || smallest == NULL)
        {
            smallest = data;
        }
        else if (data > largest || smallest == NULL)
        {
            largest = data;
        }

        list[i] = data;
    }

    printf("Smallest %d, and Largest: %d", smallest, largest);

    return 0;
}