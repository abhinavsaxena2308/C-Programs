// WAP to convert a Binary number into Hexadecimal number
#include <stdio.h>
#include <math.h>

int main() {
    long long binary;
    int decimal = 0, i = 0, rem;
    char hex[20];

    printf("Enter a binary number: ");
    scanf("%lld", &binary);

    // Step 1: Convert Binary to Decimal
    while (binary != 0) {
        rem = binary % 10;
        decimal += rem * pow(2, i);
        binary /= 10;
        i++;
    }

    // Step 2: Convert Decimal to Hexadecimal
    int j = 0;
    while (decimal != 0) {
        int temp = decimal % 16;

        // check if temp < 10 for digits 0-9
        if (temp < 10) {
            hex[j] = temp + 48; // ASCII for '0' is 48
        } else {
            hex[j] = temp + 55; // ASCII for 'A' is 65 (10+55)
        }
        
        decimal = decimal / 16;
        j++;
    }

    printf("Hexadecimal number: ");
    for (int k = j - 1; k >= 0; k--) {
        printf("%c", hex[k]);
    }
    printf("\n");

    return 0;
}
