#include <stdio.h>
#include <cstdlib>

int main()
{
    int n;
    int choice = 0;

    // Input the value of n
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Declare an array of size n
    int *arr = (int *)malloc(n * sizeof(int));

    // Input the elements
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }

    while (choice != 5)
    {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Traverse\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Merge\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        // Get user's choice
        scanf("%d", &choice);
        if (choice == 1)
        {
            // Print the array (optional, for verification)
            printf("The entered elements are: ");
            for (int i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
        else if (choice == 2)
        {
            int elem;
            int index;
            printf("Enter Element to insert: ");
            scanf("%d", &elem);

            printf("\nEnter index: ");
            scanf("%d", &index);
            if (index > n)
            {
                printf("Index out of bounds.\n");
                continue;
            }

            arr = (int *)realloc(arr, (n + 1) * sizeof(int));
            n++;
            for (int i = n - 1; i > index; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[index] = elem;
        }
        else if (choice == 3)
        {
            int deletionIndex;
            printf("Enter index to delete: ");
            scanf("%d", &deletionIndex);

            for (int i = deletionIndex; i < n; i++)
            {
                arr[i] = arr[i + 1];
            }
            arr[n] = -1;
        }
        else if (choice == 4)
        {
            int newN;
            printf("Enter number of elements in new array: ");
            scanf("%d", &newN);

            // Input the elements
            printf("Enter the elements: ");
            arr = (int *)realloc(arr, (n + newN) * sizeof(int));
            for (int i = n; i < n + newN; i++)
            {
                scanf("%d", arr + i);
            }
            n = n + newN;
        }
        else if (choice == 5)
        {
            break;
        }
    }

    return 0;
}