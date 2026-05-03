// Given a BST and two numbers K1 and K2, give an algorithm for printing all the elements of BST in the range K1 and K2.
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// helper function to create a new node
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

// recursive function to print in range [k1, k2]
void printRange(struct node* root, int k1, int k2) {
    if (root == NULL) return;

    // if root->data is greater than k1, search left subtree
    if (k1 < root->data) {
        printRange(root->left, k1, k2);
    }

    // if root->data is in range, print it
    if (k1 <= root->data && k2 >= root->data) {
        printf("%d ", root->data);
    }

    // if root->data is smaller than k2, search right subtree
    if (k2 > root->data) {
        printRange(root->right, k1, k2);
    }
}

int main() {
    struct node* root = NULL;
    int k1 = 10, k2 = 25;

    /*
          20
         /  \
        8    22
       / \
      4   12
    */
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 22);
    root = insert(root, 4);
    root = insert(root, 12);

    printf("Elements in range [%d, %d]: ", k1, k2);
    printRange(root, k1, k2);
    printf("\n");

    return 0;
}
