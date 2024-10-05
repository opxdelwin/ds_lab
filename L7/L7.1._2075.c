#include <stdio.h>
#include<stdlib.h>
#define MAX 100

struct Queue
{
    int front, rear;
    int items[MAX];
};

int showMenu()
{
    printf("Choose a option\n");
    printf("1 Insert into queue\n");
    printf("2 Delete from queue\n");
    printf("3 Traverse queue\n");
    printf("4 Exit\n");
    printf("\n");
    int choice;
    scanf("%d", &choice);
    return choice;
}

int isFull(struct Queue* queue)
{
    return queue->rear == MAX - 1;
}

int isEmpty(struct Queue *queue)
{
    return queue->rear == queue->front && queue->front == -1;
}

void insert(struct Queue* queue)
{
    if (isFull(queue))
    {
        printf("Overflow");
        return;
    }
    int item;
    printf("Enter item to be inserted: ");
    scanf("%d", &item);
    queue->rear++;
    queue->items[queue->rear] = item;
    return;
}

void deleteItem(struct Queue* queue)
{
    if (isEmpty(queue))
    {
        printf("Underflow");
        return;
    }
    int el = queue->items[queue->front];
    queue->front++;
    printf("Deleting %d", el);
    return;
}

void traverse(struct Queue* queue) {
    printf("rear: %d", queue->rear );
    printf("front: %d", queue->front );
    for(int i = queue->front; i <= queue->rear; i++) {
        printf(" %d", queue->items[i]);
    }
    printf("\n");
}

int main()
{
    struct Queue queue;
    queue.front = -1;
    queue.rear = -1;

    int choice;
    do
    {
        choice = showMenu();
        switch (choice)
        {
        case 1:
            insert(&queue);
            break;
        case 2:
            deleteItem(&queue);
            break;
        case 3:
            traverse(&queue);
            break;
        default:
            break;
        }
    } while (choice != 4);
    return 0;
}