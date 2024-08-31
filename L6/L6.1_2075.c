#include <stdio.h>

void push(int stack[], int *top)

{
    int value;
    printf("Enter value to push: ");
    scanf("%d", &value);
    stack[++*(top)] = value;
}

void print(int stack[], int top)
{
    printf("\n");
    int i = top;
    while (i >= 0)
    {
        printf("|\t%d\t|\n", stack[i]);
        i--;
    }
    printf("------------------\n\n");
}

int pop(int stack[], int *top)
{
    printf("Popped Element: %d\n", stack[(*top)--]);
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
    int stack[255] = {};
    int top = -1;
    int choice;

    do
    {
        choice = menu();
        switch (choice)
        {
        case 1:
            print(stack, top);
            break;

        case 2:
            push(stack, &top);
            break;

        case 3:
            pop(stack, &top);
            break;

        case 4:
            break;

        default:
            break;
        }
    } while (choice != 4);

    return 0;
}