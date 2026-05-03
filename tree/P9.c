#include <stdio.h>
#include <stdlib.h>

//Implement Binary Search Tree insertion. 
// Implement search operation in BST. 
// Implement deletion in BST.

struct node {
    int data;
    struct node *left, *right;
};

// create a new node
struct node* newNode(int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// 1. Insertion in BST
struct node* insert(struct node* root, int val) {
    if (root == NULL) return newNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// 2. Search operation
struct node* search(struct node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    
    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

// helper function to find the minimum value node (for deletion)
struct node* minValueNode(struct node* node) {
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// 3. Deletion in BST
struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: get inorder successor
        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
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

    printf("Inorder traversal: ");
    inorder(root);

    printf("\n\nSearching for 40: ");
    if (search(root, 40)) printf("Found\n"); else printf("Not Found\n");

    printf("\nDeleting 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal: ");
    inorder(root);

    printf("\n\nDeleting 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal: ");
    inorder(root);

    printf("\n\nDeleting 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal: ");
    inorder(root);

    printf("\n");
    return 0;
}
