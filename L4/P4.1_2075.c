#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
};

int showMenu()
{
    int choice;
    printf("\nLinked List Operations Menu:\n");
    printf("1. Create a list (Node Creation)\n");
    printf("2. Display the list\n");
    printf("3. Insert a node at the beginning\n");
    printf("4. Insert a node at the end\n");
    printf("5. Insert a node at any position\n");
    printf("6. Delete a node from the beginning\n");
    printf("7. Delete a node from the end\n");
    printf("8. Delete a node from any position\n");
    printf("9. Count the total number of nodes\n");
    printf("10. Search for an element in the linked list\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}

struct Node *createNode(struct Node *head)
{
    int len;
    struct Node *node = NULL;
    struct Node *copy = NULL;

    printf("Enter length of list: ");
    scanf("%d", &len);
    printf("Enter Node Values: ");
    int i = 0;
    do
    {
        if (node == NULL)
        {
            node = (struct Node *)malloc(sizeof(struct Node));
            copy = node;
            int value;
            scanf("%d", &value);
            node->value = value;
            node->next = NULL;
            i++;
            continue;
        }
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        int value;
        scanf("%d", &value);
        newNode->value = value;
        newNode->next = NULL;
        copy->next = newNode;
        copy = newNode;
        i++;
    } while (i < len);
    return node;
}

void displayList(struct Node *head)
{
    struct Node *copy = head;

    while (copy != NULL)
    {
        printf("%d ", copy->value);
        copy = copy->next;
    }

    printf("\n");
    return;
}
int getIntInput()
{
    int val;
    printf("Enter a value: ");
    scanf("%d", &val);
    printf("\n");

    return val;
}
int getIntPos()
{
    int val;
    printf("Enter position index: ");
    scanf("%d", &val);
    printf("\n");

    return val;
}

struct Node *insertBeginning(struct Node *head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = head;
    return newNode;
}

void insertEnd(struct Node *head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *copy = head;

    newNode->value = value;
    newNode->next = NULL;

    while (copy->next != NULL)
    {
        copy = copy->next;
    }

    copy->next = newNode;
}

void insertAt(struct Node *head, int value, int pos)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *copy = head;

    newNode->value = value;
    newNode->next = NULL;

    for (int i = 0; i < pos - 1; i++)
    {
        copy = copy->next;
    }
    struct Node *kNext = copy->next;
    copy->next = newNode;
    newNode->next = kNext;
}

struct Node *delBeginning(struct Node *head)
{
    struct Node *copy = head;

    if (head == NULL || head->next == NULL)
    {
        free(copy);
        return NULL;
    }

    struct Node *kNext = head->next;
    free(copy);
    return kNext;
}

void delEnd(struct Node *head)
{
    struct Node *copy = head;

    if (head == NULL || head->next == NULL)
    {
        free(copy);
        head = NULL;
        return;
    }

    while (copy->next->next != NULL)
    {
        copy = copy->next;
    }

    struct Node *kNext = copy->next;
    free(kNext);
    copy->next = NULL;
    return;
}

void delAt(struct Node *head, int pos)
{
    struct Node *copy = head;

    for (int i = 0; i < pos - 1; i++)
    {
        copy = copy->next;
    }
    struct Node *kNext = copy->next->next;
    struct Node *del = copy->next;
    copy->next = kNext;
    free(del);
}

void countLen(struct Node *head)
{
    int i = 0;
    struct Node *copy = head;

    while (copy != NULL)
    {
        i++;
        copy = copy->next;
    }

    printf("Length of list is %d", i);
    return;
}

void searchVal(struct Node *head, int val)
{
    struct Node *copy = head;

    while (copy != NULL)
    {
        if (copy->value == val)
        {
            printf("Element found: %d ", copy->value);
            return;
        }
        copy = copy->next;
    }

    printf("Element not found!\n");
    return;
}

int main()
{
    int choice;
    struct Node *head = NULL;

    do
    {
        choice = showMenu();
        switch (choice)
        {
        case 1:
            head = createNode(head);
            break;
        case 2:
            displayList(head);
            break;
        case 3:

            int insertVal = getIntInput();
            head = insertBeginning(head, insertVal);
            break;
        case 4:
            int insertEndValue = getIntInput();
            insertEnd(head, insertEndValue);
            break;
        case 5:
            int insertAtVal = getIntInput();
            int insertAtPos = getIntPos();
            insertAt(head, insertAtVal, insertAtPos);
            break;
        case 6:
            head = delBeginning(head);
            break;
        case 7:
            delEnd(head);
            break;
        case 8:
            int delAtPos = getIntPos();
            delAt(head, delAtPos);
            break;
        case 9:
            countLen(head);
            break;
        case 10:
            int searchValue = getIntInput();
            searchVal(head, searchValue);
            break;
        case 0:
            return 0;

        default:
            break;
        }
    } while (choice != 0);

    return 0;
}