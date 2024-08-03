#include <stdio.h>

/*
Enter the value of nXn matrix:  3 3
Enter the elements of the matrix:
1 2 3 4 5 1 2 3 4
The no of non zero elements are: 9
Row 1, Sum= 6, Average= 2.000000
Row 2, Sum= 12, Average= 4.000000
Row 3, Sum= 6, Average= 2.000000
Column 1, Sum= 7, Average= 2.333333
Column 2, Sum= 7, Average= 2.333333
Column 3, Sum= 10, Average= 3.333333

Enter the value of nXn matrix: 2 2
Enter the elements of the matrix:
2 3 1 0
The no of non zero elements are: 4
Row 1, Sum= 4, Average= 2.000000
Row 2, Sum= 4, Average= 2.000000
Column 1, Sum= 5, Average= 2.500000
Column 2, Sum= 3, Average= 1.500000
*/

int sumRow(int *arr, int r, int n);
float AvgRow(int *arr, int r, int n);
int nonZero(int *arr, int n);
int sumCol(int *arr, int c, int n);
float AvgCol(int *arr, int c, int n);

int main()
{
    int n;

    printf("Enter the value of nXn matrix: ");
    scanf("%d", &n);

    int arr[n][n];

    printf("Enter the elements of the matrix: \n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("The no of non zero elements are: %d\n", nonZero((int *)arr, n));

    for (int i = 0; i < n; i++)
    {
        printf("Row %d, Sum= %d, Average= %f\n", i + 1, sumRow((int *)arr, i, n), AvgRow((int *)arr, i, n));
    }

    for (int i = 0; i < n; i++)
    {
        printf("Column %d, Sum= %d, Average= %f\n", i + 1, sumCol((int *)arr, i, n), AvgCol((int *)arr, i, n));
    }

    return 0;
}

int sumRow(int *arr, int r, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += *((arr + r * n) + i);
    }
    return sum;
};

int sumCol(int *arr, int c, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += *((arr + i * n) + c);
    }
    return sum;
};

float AvgRow(int *arr, int r, int n)
{
    return (float)sumRow(arr, r, n) / n;
};

float AvgCol(int *arr, int c, int n)
{
    return (float)sumCol(arr, c, n) / n;
};

int nonZero(int *arr, int n)
{
    int count = 0;
    for (int i = 0; i < n * n; i++)
    {
        if (*(arr + i) != 0)
            count++;
    }
    return count;
};