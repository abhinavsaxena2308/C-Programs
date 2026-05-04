// Write a program to count:
// Total nodes
// Leaf nodes
// Internal nodes
// Find height of a binary tree.
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
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

// 1. Total Nodes
int countNodes(struct node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// 2. Leaf Nodes (nodes with no children)
int countLeaf(struct node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeaf(root->left) + countLeaf(root->right);
}

// 3. Internal Nodes (nodes with at least one child)
int countInternal(struct node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) return 0;
    return 1 + countInternal(root->left) + countInternal(root->right);
}
// 4. Height of Tree
int findHeight(struct node* root) {
    if (root == NULL) return 0;
    int leftH = findHeight(root->left);
    int rightH = findHeight(root->right);
    return (leftH > rightH ? leftH : rightH) + 1;
}
int main() {
    struct node* root = NULL;
    int n, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Total Nodes: %d\n", countNodes(root));
    printf("Leaf Nodes: %d\n", countLeaf(root));
    printf("Internal Nodes: %d\n", countInternal(root));
    printf("Height of Tree: %d\n", findHeight(root));

    return 0;
}
