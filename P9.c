//WAP to convert a Binary number into Octal number
#include <stdio.h>
int main() {
    long binary, decimal = 0, octal = 0, base = 1, rem;
    int temp, i = 1, j;

    printf("Enter a binary number: ");
    scanf("%ld", &binary);
    temp = binary;

    // Convert binary to decimal
    while (temp > 0) {
        rem = temp % 10; // Get the last digit
        decimal += rem * base; // Add to decimal result
        base *= 2; // Update base for next iteration
        temp /= 10; // Remove the last digit
    }

    // Convert decimal to octal
    base = 1;
    while (decimal > 0) {
        rem = decimal % 8;
        octal += rem * base;
        decimal /= 8;
        base *= 10;
    }

    printf("Octal equivalent of %ld is: %ld\n", binary, octal);

    return 0;
}