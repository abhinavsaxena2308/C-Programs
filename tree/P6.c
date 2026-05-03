// Given root of a Binary Search tree, trim the tree, so that all elements returned in the new tree are between the inputs A and B.
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// function to create a new node
struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// function to insert in BST
struct node* insert(struct node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);
    return node;
}

// Function to trim the BST
struct node* trimBST(struct node* root, int a, int b) {
    if (root == NULL) return NULL;

    // if root's value is smaller than a, it and its left subtree are gone
    if (root->data < a) {
        return trimBST(root->right, a, b);
    }

    // if root's value is larger than b, it and its right subtree are gone
    if (root->data > b) {
        return trimBST(root->left, a, b);
    }

    // if root is in range, trim its children
    root->left = trimBST(root->left, a, b);
    root->right = trimBST(root->right, a, b);

    return root;
}

// function to print inorder
void inorder(struct node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct node* root = NULL;
    int a = 1, b = 3;

    /*
          3
         / \
        0   4
         \
          2
         /
        1
    */
    root = insert(root, 3);
    root = insert(root, 0);
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 1);

    printf("Original Inorder: ");
    inorder(root);
    printf("\n");

    root = trimBST(root, a, b);

    printf("Trimmed Inorder (range %d to %d): ", a, b);
    inorder(root);
    printf("\n");

    return 0;
}
