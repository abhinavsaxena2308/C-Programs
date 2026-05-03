/* 
    QUESTION:
    Can 1,2,3,4,5,6 be permuted into:
    1. 325641? 
    2. 154623?

    ANSWER:
    1. 325641 -> YES. 
       Sequence: SSSXXSSXSXXX
       (Push 1, Push 2, Push 3, Pop 3, Pop 2, Push 4, Push 5, Pop 5, Push 6, Pop 6, Pop 4, Pop 1)

    2. 154623 -> NO.
       Let's trace:
       - To get '1' first: Push 1, Pop 1 (SX).
       - To get '5' next: Push 2, Push 3, Push 4, Push 5, then Pop 5 (SSSSX). 
         Stack now has [2, 3, 4] (top is 4).
       - To get '4' next: Pop 4 (X). Stack has [2, 3] (top is 3).
       - To get '6' next: Push 6, then Pop 6 (SX). Stack still has [2, 3] (top is 3).
       - Next we need '2', but the top of stack is '3'. 
         We MUST pop 3 before 2. So 154623 is impossible.
*/

#include <stdio.h>

// Simple program to verify the sequence for 325641
int main() {
    int stack[10];
    int top = -1;
    int next_push = 1;
    char ops[] = "SSSXXSSXSXXX";
    
    printf("Sequence for 325641: ");
    for(int i=0; ops[i] != '\0'; i++) {
        if(ops[i] == 'S') {
            stack[++top] = next_push++;
        } else {
            printf("%d ", stack[top--]);
        }
    }
    printf("\n\nFor 154623, we hit a block because we need to pop 2 before 3, which is impossible in a stack!\n");
    
    return 0;
}
