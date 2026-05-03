#include <stdio.h>

// recursive function to count digits
int countDigits(int n) {
    // base case: if number is single digit
    if (n < 10 && n > -10) {
        return 1;
    }
    // recursive step
    return 1 + countDigits(n / 10);
}

int main() {
    int num;

    printf("Enter any number: ");
    scanf("%d", &num);

    // calling the function
    int total = countDigits(num);

    printf("Total number of digits is: %d\n", total);

    return 0;
}
