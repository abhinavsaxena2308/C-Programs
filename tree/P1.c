// Write a program to create and traverse a binary tree.
#include <stdio.h>
#include <stdlib.h>

// node structure
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// function to create a binary tree
struct node* create() {
    int x;
    struct node* newNode;
    newNode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data (-1 for no node): ");
    scanf("%d", &x);

    // base case for recursion
    if (x == -1) {
        return NULL;
    }

    newNode->data = x;

    printf("Enter left child of %d:\n", x);
    newNode->left = create();

    printf("Enter right child of %d:\n", x);
    newNode->right = create();

    return newNode;
}

// Inorder traversal (Left, Root, Right)
void inorder(struct node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Preorder traversal (Root, Left, Right)
void preorder(struct node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal (Left, Right, Root)
void postorder(struct node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    struct node* root;

    printf("Create your Binary Tree:\n");
    root = create();

    printf("\nInorder traversal: ");
    inorder(root);

    printf("\nPreorder traversal: ");
    preorder(root);

    printf("\nPostorder traversal: ");
    postorder(root);

    printf("\n");
    return 0;
}
