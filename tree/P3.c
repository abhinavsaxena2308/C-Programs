// Give an algorithm for finding the number of half nodes (nodes with only one child) in the binary tree without using recursion.
#include <stdio.h>
#include <stdlib.h>

// node structure
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// function to create a node
struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Iterative function to count half nodes using a queue (Level Order Traversal)
int countHalfNodes(struct node* root) {
    if (root == NULL) return 0;

    struct node* queue[100];
    int front = 0, rear = 0;
    int count = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct node* temp = queue[front++];

        // check if node has ONLY one child
        if ((temp->left != NULL && temp->right == NULL) || 
            (temp->left == NULL && temp->right != NULL)) {
            count++;
        }

        // enqueue children
        if (temp->left != NULL) {
            queue[rear++] = temp->left;
        }
        if (temp->right != NULL) {
            queue[rear++] = temp->right;
        }
    }
    return count;
}

int main() {
    // creating a sample tree
    /*
            1
           / \
          2   3
         /
        4
    */
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);

    printf("Number of half nodes: %d\n", countHalfNodes(root));

    return 0;
}
