// WAP to search for a number in an array
#include <stdio.h>

int main() {
    int arr[100], n, i, search, found = 0;

    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter a number to search: ");
    scanf("%d", &search);

    // Linear Search logic
    for (i = 0; i < n; i++) {
        if (arr[i] == search) {
            printf("%d is present at location %d.\n", search, i + 1);
            found = 1;
            break; // exit loop as soon as we find it
        }
    }

    if (!found) {
        printf("%d is not present in the array.\n", search);
    }

    return 0;
}
