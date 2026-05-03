// Implement AVL Tree insertion with rotations. Perform LL, RR, LR, RL rotations.
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
    int height;
};

// function to get height of a node
int getHeight(struct node* n) {
    if (n == NULL) return 0;
    return n->height;
}

// helper for max of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// create a new node
struct node* newNode(int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;
    temp->height = 1; // new node is initially added at leaf
    return temp;
}

// Right Rotate (used for LL case)
struct node* rightRotate(struct node* y) {
    struct node* x = y->left;
    struct node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Left Rotate (used for RR case)
struct node* leftRotate(struct node* x) {
    struct node* y = x->right;
    struct node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// get balance factor
int getBalance(struct node* n) {
    if (n == NULL) return 0;
    return getHeight(n->left) - getHeight(n->right);
}

// AVL Insertion
struct node* insert(struct node* node, int data) {
    // 1. Normal BST insertion
    if (node == NULL) return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node; // equal keys not allowed

    // 2. Update height of this ancestor node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // 3. Get balance factor to check if it became unbalanced
    int balance = getBalance(node);

    // LL Case
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // RR Case
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // LR Case
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL Case
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    struct node* root = NULL;

    /* Constructing tree to test rotations */
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30); // RR rotation happens here
    root = insert(root, 40);
    root = insert(root, 50); // RR rotation happens again
    root = insert(root, 25); // RL rotation happens here

    printf("Preorder traversal of balanced AVL tree: \n");
    preorder(root);
    printf("\n");

    return 0;
}
