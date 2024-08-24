#include <stdio.h>

int main()
{
    int row, column, maxValues;
    printf("Enter Sparce Matrix 1:");
    scanf("%d %d %d", &row, &column, &maxValues);

    int matrix1[row][column];
    matrix1[0][0] = row;
    matrix1[0][1] = column;
    matrix1[0][2] = maxValues;

    printf("Enter Matrix Values:\n");
    for (int i = 1; i < row + 1; i++)
    {
        for (int j = 0; j < column; j++)
        {
            scanf("%d", (matrix1 + (i * j) + j));
        }
    }

    int row2, column2, maxValues2;
    printf("Enter Sparce Matrix 2:");
    scanf("%d %d %d", &row2, &column2, &maxValues2);

    int matrix2[row2][column2];
    matrix2[0][0] = row2;
    matrix2[0][1] = column2;
    matrix2[0][2] = maxValues2;

    printf("Enter Matrix Values:\n");
    for (int i = 1; i < row2 + 1; i++)
    {
        for (int j = 0; j < column2; j++)
        {
            scanf("%d", (matrix2 + (i * j) + j));
        }
    }

    return 0;
}