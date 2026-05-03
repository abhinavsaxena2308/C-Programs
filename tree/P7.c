// Implement binary tree using linked representation.
#include <stdio.h>
#include <stdlib.h>

// node structure using pointers (linked representation)
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// function to create a new node
struct node* createNode(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    // creating root node
    struct node* root = createNode(10);

    // linking child nodes
    root->left = createNode(20);
    root->right = createNode(30);

    // linking more nodes
    root->left->left = createNode(40);
    root->left->right = createNode(50);

    printf("Binary Tree Linked Representation:\n");
    printf("        %d\n", root->data);
    printf("       /  \\\n");
    printf("     %d    %d\n", root->left->data, root->right->data);
    printf("    /  \\\n");
    printf("  %d    %d\n", root->left->left->data, root->left->right->data);

    return 0;
}
