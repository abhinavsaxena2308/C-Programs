//WAP to convert a Binary number into Decimal number
#include <stdio.h>
int main() {
    long binary, decimal = 0, base = 1, rem;
    int temp;

    printf("Enter a binary number: ");
    scanf("%ld", &binary);
    temp = binary;

    while (temp > 0) {
        rem = temp % 10; // Get the last digit
        decimal += rem * base; // Add to decimal result
        base *= 2; // Update base for next iteration
        temp /= 10; // Remove the last digit
    }

    printf("Decimal equivalent of %ld is: %ld\n", binary, decimal);

    return 0;
}