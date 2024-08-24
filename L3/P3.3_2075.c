#include <stdio.h>

int main()
{
    int degree = 0;
    printf("Enter largest degree of x: ");
    scanf("%d", &degree);

    int coeff[degree + 1];

    printf("Enter Polynomial-1 from lowest degree to highest degree : 4 2 3 (Hint: 4+2x+3x^2)\n");
    printf("Enter polynomial co-efficients: ");

    for (int i = 0; i < degree + 1; i++)
    {
        scanf("%d", coeff + i);
    }

    printf("Enter polynomial co-efficients to be added: ");
    for (int i = 0; i < degree + 1; i++)
    {
        int num;
        scanf("%d", &num);
        coeff[i] += num;
    }

    printf("Resultant Polynomial: ");
    for (int i = 0; i < degree + 1; i++)
    {
        if (i == 0)
        {
            printf("%d", coeff[i]);
        }
        else if (i == 1)
        {
            printf(" + %dx", coeff[i]);
        }
        else
        {
            printf(" + %dx^%d", coeff[i], i);
        }
    }

    return 0;
}