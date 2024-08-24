#include <stdio.h>

int main()
{
    int row, col, maxValue;
    printf("Enter row,column,maxValue: ");
    scanf("%d %d %d", &row, &col, &maxValue);

    int matrix[row + 1][col];
    matrix[0][0] = row;
    matrix[0][1] = col;
    matrix[0][2] = maxValue;

    for (int i = 1; i < row + 1; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", matrix + (i * sizeof(int)) + j);
        }
    }

    printf("Matrix:\n\n");

    for (int i = 0; i < row + 1; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", matrix[i][j]);
        }
    }

    return 0;
}