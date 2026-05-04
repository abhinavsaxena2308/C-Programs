// Implement menu driven program: Preorder traversal, Inorder traversal, and Postorder traversal
#include <stdio.h>
#include <stdlib.h>
// node structure
struct node {
    int data;
    struct node* left;
    struct node* right;
};
// function to create the tree
struct node* create() {
    int x;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &x);
    if (x == -1) return NULL;
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    printf("Enter left child of %d:\n", x);
    newNode->left = create();
    printf("Enter right child of %d:\n", x);
    newNode->right = create();
    return newNode;
}
// Preorder: Root -> Left -> Right
void preorder(struct node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Inorder: Left -> Root -> Right
void inorder(struct node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Postorder: Left -> Right -> Root
void postorder(struct node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    struct node* root = NULL;
    int choice;

    printf("First, let's create the tree:\n");
    root = create();

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Preorder Traversal\n");
        printf("2. Inorder Traversal\n");
        printf("3. Postorder Traversal\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nPreorder: ");
                preorder(root);
                printf("\n");
                break;
            case 2:
                printf("\nInorder: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("\nPostorder: ");
                postorder(root);
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("\nWrong Choice!\n");
        }
    }

    return 0;
}
