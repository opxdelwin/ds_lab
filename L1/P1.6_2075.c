#include <stdio.h>

/*
SET-1
    Enter two numbers: 57
    5 is smaller than 7

SET-2
    Enter two numbers: 45 5
    45 is greater than 5
*/
void compare(int *a, int *b)
{
    if (*a > *b)
    {
        printf("%d is greater than %d", *a, *b);
    }
    else
    {
        printf("%d is smaller than %d", *a, *b);
    }
}

int main()
{
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    compare(&a, &b);
    return 0;
}
