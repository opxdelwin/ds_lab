#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

struct node *createNode(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node *insert(struct node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else {
        if (data < root->data) {
            root->left = insert(root->left, data);
        } else if (data > root->data) {
            root->right = insert(root->right, data);
        }
    }
    return root;
}

struct node *search(struct node *root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int findLargest(struct node *root) {
    if (root == NULL) {
        return -1;
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

int findSmallest(struct node *root) {
    if (root == NULL) {
        return -1;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

struct node *deleteNode(struct node *root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        } else {
            int temp = findSmallest(root->right);
            root->data = temp;
            root->right = deleteNode(root->right, temp);
        }
    }
    return root;
}

int main() {
    int choice, data, searchData;

    while (1) {
        printf("Menu:\n");
        printf("1. Insert a node\n");
        printf("2. Search a node\n");
        printf("3. Display (preorder)\n");
        printf("4. Display (inorder)\n");
        printf("5. Display (postorder)\n");
        printf("6. Find largest element\n");
        printf("7. Find smallest element\n");
        printf("8. Delete a node\n");
        printf("9. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        struct node *result;

        switch (choice) {
            case 1:
                printf("Enter the number to be inserted: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter the number to be searched: ");
                scanf("%d", &searchData);
                result = search(root, searchData);
                if (result != NULL) {
                    printf("Number found: %d\n", result->data);
                } else {
                    printf("Number not found\n");
                }
                break;
            case 3:
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 6:
                printf("Largest element: %d\n", findLargest(root));
                break;
            case 7:
                printf("Smallest element: %d\n", findSmallest(root));
                break;
            case 8:
                printf("Enter the number to be deleted: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
       }
    }

    return 0;
}