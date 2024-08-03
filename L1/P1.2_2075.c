#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Book
{
    char title[50];
    char author[50];
    char publication[50];
    int price;
};

struct Book *addNewBook();
void printBook(char author[50], struct Book *bookList[], int size);

int main()
{
    int actionType;
    int bookLen;

    printf("Enter number of books: ");
    scanf("%d", &bookLen);

    struct Book *books[bookLen];
    int iteration = 0;

    do
    {
        printf("Enter 1 to add a new book\n");
        printf("Enter 2 to search author\n");
        printf("Enter Action: ");
        scanf("%d", &actionType);

        if (actionType == 1)
        {
            books[iteration] = addNewBook();
        }
        else if (actionType == 2)
        {
            char authorInp[50];
            printf("Enter Author name: ");
            scanf("%s", &authorInp);

            printBook(authorInp, books, sizeof(books) / sizeof(books[0]));
        }
        iteration++;
        printf("\n");
    } while (actionType != 3);

    return 0;
}

struct Book *addNewBook()
{
    struct Book *book = (struct Book *)malloc(sizeof(struct Book));
    char title[50];
    char author[50];
    char publication[50];
    int price;

    printf("Enter book title: ");
    scanf("%s", &title);

    printf("Enter author name: ");
    scanf("%s", &author);

    printf("Enter publication name: ");
    scanf("%s", &publication);

    printf("Enter book price: ");
    scanf("%d", &price);

    strcpy(book->title, title);
    strcpy(book->publication, publication);
    strcpy(book->author, author);
    book->price = price;

    return book;
}

void printBook(char author[50], struct Book *bookList[], int size)
{

    for (int i = 0; i < size; i++)
    {
        struct Book *item = (struct Book *)bookList[i];

        if (strcmp(item->author, author) != 0)
        {
            continue;
        }

        printf("Book(author: %s, publication: %s, title: %s, price: %d)\n", item->author, item->publication, item->title, item->price);
    }
}