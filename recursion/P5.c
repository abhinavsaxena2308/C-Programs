// recursive function to count digits

#include <stdio.h>
int countDigits(int n) {
    if (n < 10 && n > -10) {            //if number is single digit
        return 1;
    }
    return 1 + countDigits(n / 10);         // recursive step
}

int main() {
    int num;
    printf("Enter any number: ");
    scanf("%d", &num);
    int total = countDigits(num);       // calling the function
    printf("Total number of digits is: %d\n", total);
    return 0;
}
