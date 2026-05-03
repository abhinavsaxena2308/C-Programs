// Write a program to evaluate an expression tree. Input: (5+3)*(8-2).
#include <stdio.h>
#include <stdlib.h>

// node structure for expression tree
struct node {
    char data;
    struct node *left, *right;
};

// function to create a new node
struct node* newNode(char val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Recursive function to evaluate the expression tree
int evaluate(struct node* root) {
    // base case: if leaf node (it's a number)
    if (root->left == NULL && root->right == NULL) {
        return root->data - '0'; // convert char to int
    }

    // evaluate left and right subtrees
    int leftVal = evaluate(root->left);
    int rightVal = evaluate(root->right);

    // apply the operator at the root
    if (root->data == '+') return leftVal + rightVal;
    if (root->data == '-') return leftVal - rightVal;
    if (root->data == '*') return leftVal * rightVal;
    if (root->data == '/') return leftVal / rightVal;

    return 0;
}

int main() {
    /* 
       Let's manually build the tree for (5+3)*(8-2)
              *
           /    \
          +      -
         / \    / \
        5   3  8   2
    */

    struct node* root = newNode('*');
    
    root->left = newNode('+');
    root->left->left = newNode('5');
    root->left->right = newNode('3');

    root->right = newNode('-');
    root->right->left = newNode('8');
    root->right->right = newNode('2');

    printf("Expression: (5+3)*(8-2)\n");
    printf("Result of Expression Tree: %d\n", evaluate(root));

    return 0;
}
