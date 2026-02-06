//wap to separate out +ve and -ve numbers and zero from an array and store them in different arrays
#include <stdio.h>
int main() {
    int arr[100], pos[100], neg[100], zero[100];
    int n, i, p = 0, ne = 0, z = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > 0) {
            pos[p++] = arr[i];
        } else if (arr[i] < 0) {
            neg[ne++] = arr[i];
        } else {
            zero[z++] = arr[i];
        }
    }

    printf("Positive numbers:\n");
    for (i = 0; i < p; i++) {
        printf("%d ", pos[i]);
    }
    printf("\n");

    printf("Negative numbers:\n");
    for (i = 0; i < ne; i++) {
        printf("%d ", neg[i]);
    }
    printf("\n");

    printf("Zeroes:\n");
    for (i = 0; i < z; i++) {
        printf("%d ", zero[i]);
    }
    printf("\n");

    return 0;
}