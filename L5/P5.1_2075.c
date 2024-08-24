#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
};

typedef struct Node NODE;

void prin(NODE *head)
{
    NODE *temp = head;
    while (temp != NULL)
    {
        printf("--> %d^%d", temp->coeff, temp->exp);
        temp = temp->next;
    }
}

int main()
{
    NODE *head = NULL;
    int len = 0;
    printf("Enter highest exponent: ");
    scanf("%d", &len);

    NODE *temp = head;
    printf("Enter coefficients of polynomial %d:\n", 1);
    for (int j = 0; j < len; j++)
    {
        if (temp == NULL)
        {
            head = (NODE *)malloc(sizeof(NODE));
            temp = head;
        }
        else
        {
            NODE *newNode = (NODE *)malloc(sizeof(NODE));
            temp->next = newNode;
            temp = temp->next;
        }
        int val;
        printf("Enter %d th: ", j + 1);
        scanf("%d", &val);
        temp->exp = len - j;
        temp->coeff = val;
        temp->next = NULL;
    }
    temp = head;
    printf("\nEnter coefficients of polynomial %d:\n", 2);
    for (int j = 0; j < len; j++)
    {

        int val;
        printf("Enter %d th: ", j + 1);
        scanf("%d", &val);
        temp->exp = len - j;
        temp->coeff += val;
        temp = temp->next;
    }

    prin(head);
    return 0;
}