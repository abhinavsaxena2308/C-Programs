//WAP to print all prime numbers in an array
#include <stdio.h>

int main() {
    int a[100], n, i, j, isPrime;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d numbers: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Prime numbers in the array are: ");
    for(i = 0; i < n; i++) {
        isPrime = 1; 
        if (a[i] < 2) {
            isPrime = 0;
        } else {
            for(j = 2; j < a[i]; j++) {
                if(a[i] % j == 0) {
                    isPrime = 0; 
                    break;
                }
            }
        }
        if(isPrime == 1) {
            printf("%d ", a[i]);
        }
    }
    return 0;
}