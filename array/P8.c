//WAP to convert a Hexadecimal number into Decimal number
#include <stdio.h>
int main() {
    char hexadecimal[100];
    int decimal = 0, base = 1, len, i;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hexadecimal);

    // Calculate the length of the hexadecimal string
    for (len = 0; hexadecimal[len] != '\0'; len++);

    // Convert hexadecimal to decimal
    for (i = len - 1; i >= 0; i--) {
        if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9') {
            decimal += (hexadecimal[i] - '0') * base;
        } else if (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F') {
            decimal += (hexadecimal[i] - 'A' + 10) * base;
        } else if (hexadecimal[i] >= 'a' && hexadecimal[i] <= 'f') {
            decimal += (hexadecimal[i] - 'a' + 10) * base;
        }
        base *= 16;
    }

    printf("Decimal equivalent of %s is: %d\n", hexadecimal, decimal);

    return 0;
}