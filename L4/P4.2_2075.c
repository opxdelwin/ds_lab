#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *next;
    struct Node *prev;
    int data;
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

int main()
{
    struct Node *head = NULL;
    return 0;
}