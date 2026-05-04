// recursive function to find sum of digits

#include <stdio.h>
int sumOfDigits(int n) {
    if (n == 0) {
        return 0;
    }
    // adding last digit and calling function again
    return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    // calling function and printing result
    printf("Sum of digits of %d is %d\n", num, sumOfDigits(num));

    return 0;
}



