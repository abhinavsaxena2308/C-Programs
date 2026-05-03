// Find minimum and maximum element in BST.
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// function to create a new node
struct node* newNode(int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// function to insert in BST
struct node* insert(struct node* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// Function to find minimum (leftmost node)
int findMin(struct node* root) {
    if (root == NULL) return -1;
    struct node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current->data;
}

// Function to find maximum (rightmost node)
int findMax(struct node* root) {
    if (root == NULL) return -1;
    struct node* current = root;
    while (current->right != NULL) {
        current = current->right;
    }
    return current->data;
}

int main() {
    struct node* root = NULL;
    
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Minimum element in BST: %d\n", findMin(root));
    printf("Maximum element in BST: %d\n", findMax(root));

    return 0;
}
