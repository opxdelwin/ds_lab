#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void print(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("<--- %d  ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node *push(struct Node *head)
{
    struct Node *temp = head;
    int value;
    while (temp != NULL && temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("\nEnter value: ");
    scanf("%d", &value);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->next = NULL;
    newNode->data = value;
    if (temp == NULL)
    {
        return newNode;
    }
    else
    {
        temp->next = newNode;
        return head;
    }
}

void pop(struct Node *head)
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("NULL");
        return;
    }

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    printf("Popping Element: %d", temp->next->data);
    free(temp->next);
    temp->next = NULL;
    printf("\n");
}

int menu()
{
    int resp;
    printf("1. Display\n");
    printf("2. Push\n");
    printf("3. Pop\n");
    printf("4. Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &resp);
    return resp;
}

int main()
{
    struct Node *head = NULL;
    int choice;
    do
    {
        choice = menu();
        switch (choice)
        {
        case 1:
            print(head);
            break;

        case 2:
            head = push(head);
            break;

        case 3:
            pop(head);
            break;

        case 4:
            break;

        default:
            break;
        }
    } while (choice != 4);

    return 0;
}