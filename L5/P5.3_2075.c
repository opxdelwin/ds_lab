#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
    struct Node *prev;
};

typedef struct Node NODE;
void print(NODE *head)
{

    NODE *temp = head;
    do
    {
        printf(" <--> %d", temp->value);
        temp = temp->next;
    } while (temp != head);
}

NODE *createList(NODE *head, int len)
{
    NODE *copy = head;
    NODE *output = copy;

    for (int i = 0; i < len; i++)
    {
        if (copy == NULL)
        {
            copy = (NODE *)malloc(sizeof(NODE));
            copy->prev = NULL;
            output = copy;
        }
        else
        {
            NODE *copyNext = (NODE *)malloc(sizeof(NODE));
            copyNext->prev = copy;
            copy->next = copyNext;
            copy = copyNext;
        }
        printf("Enter value of node %d: ", i + 1);
        int val;
        scanf("%d", &val);
        copy->value = val;
        copy->next = output;
    }
    output->prev = copy;
    return output;
}

int main()
{
    int len;
    printf("Enter length of linked list: ");
    scanf("%d", &len);

    NODE *head = NULL;
    head = createList(head, len);
    print(head);
    return 0;
}