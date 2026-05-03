//WAP to convert a Decimal number into Hexadecimal number
#include <stdio.h>
int main() {
    int decimal, remainder, quotient;
    char hexadecimal[100];
    int i = 0, j;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    quotient = decimal;

    // Storing remainders until number is equal to zero
    while (quotient != 0) {
        remainder = quotient % 16;
        if (remainder < 10) {
            hexadecimal[i++] = remainder + '0'; // Convert to character
        } else {
            hexadecimal[i++] = remainder - 10 + 'A'; // Convert to character
        }
        quotient = quotient / 16;
    }

    // Display the hexadecimal number in reverse order
    printf("Hexadecimal equivalent: ");
    for (j = i - 1; j >= 0; j--)
        printf("%c", hexadecimal[j]);
    
    printf("\n");

    return 0;
}