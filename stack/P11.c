/* 
    To implement two stacks in one array so that we only get an exception (overflow) 
    when the entire array is full, we grow the stacks from opposite ends:
    - Stack 1 starts from index 0 and grows upwards (0, 1, 2...).
    - Stack 2 starts from index MAX-1 and grows downwards (MAX-1, MAX-2...).

    The overflow condition is: top1 + 1 == top2.
*/

#include <stdio.h>

#define MAX 10

int arr[MAX];
int top1 = -1;
int top2 = MAX;

// push in stack 1
void push1(int val) {
    if (top1 < top2 - 1) {
        arr[++top1] = val;
        printf("Pushed %d to Stack 1\n", val);
    } else {
        printf("Stack Overflow: Array is completely full!\n");
    }
}

// push in stack 2
void push2(int val) {
    if (top1 < top2 - 1) {
        arr[--top2] = val;
        printf("Pushed %d to Stack 2\n", val);
    } else {
        printf("Stack Overflow: Array is completely full!\n");
    }
}

int main() {
    // filling the array using both stacks
    push1(1);
    push1(2);
    push2(10);
    push2(9);
    push1(3);
    push2(8);
    push1(4);
    push2(7);
    push1(5);
    push2(6);

    // this should result in overflow since MAX is 10
    push1(100); 

    return 0;
}
