//Write a recursive program to find the nth Fibonacci number
#include <stdio.h>
int fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    printf("Enter the position (n) to find the Fibonacci number: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (n < 0) {
        printf("Fibonacci sequence is not defined for negative indices.\n");
    } else {
        printf("The %d-th Fibonacci number is: %d\n", n, fib(n));
    }

    return 0;
}
