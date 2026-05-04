// recursive function to find gcd

#include <stdio.h>
int findGCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    // Euclidean algorithm using recursion
    return findGCD(b, a % b);
}

int main() {
    int n1, n2;

    printf("Enter two numbers to find GCD: ");
    scanf("%d %d", &n1, &n2);

    // calling the function
    printf("GCD of %d and %d is %d\n", n1, n2, findGCD(n1, n2));

    return 0;
}

