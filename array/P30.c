//WAP to print a pyramid pattern of stars
#include <stdio.h>

int main() {
    int i, j, k;
    int n = 4; // Number of lines

    for(i = 1; i <= n; i++) {
        
        // 1. Print spaces to push stars to the center
        for(j = 1; j <= n - i; j++) {
            printf(" ");
        }

        // 2. Print the stars (1, 3, 5, 7...)
        for(k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }

        // 3. Go to next line
        printf("\n");
    }

    return 0;
}