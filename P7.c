//WAP to convert a Octal number into Decimal number
#include <stdio.h>
int main() {
    long octal, decimal = 0, base = 1, rem;
    int temp;

    printf("Enter an octal number: ");
    scanf("%ld", &octal);
    temp = octal;

    while (temp > 0) {
        rem = temp % 10; // Get the last digit
        decimal += rem * base; // Add to decimal result
        base *= 8; // Update base for next iteration
        temp /= 10; // Remove the last digit
    }

    printf("Decimal equivalent of %ld is: %ld\n", octal, decimal);

    return 0;
}