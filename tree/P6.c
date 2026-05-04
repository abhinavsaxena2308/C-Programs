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
    int n, val, a, b;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("Enter range a and b: ");
    scanf("%d %d", &a, &b);
    printf("Original Inorder: ");
    inorder(root);
    printf("\n");
    root = trimBST(root, a, b);
    printf("Trimmed Inorder (range %d to %d): ", a, b);
    inorder(root);
    printf("\n");
    return 0;
}
