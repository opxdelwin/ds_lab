#include <stdio.h>
/*
Input: Hello, World
Output: Length of string: 12

Input: Orange
Output: Length of string: 6
 */
int main()
{
    char string[] = "Orange";
    char *ptr = string;
    int len = 0;

    while (*ptr != NULL)
    {
        len++;
        ptr++;
    }

    printf("Length of string: %d", len);

    return 0;
}
