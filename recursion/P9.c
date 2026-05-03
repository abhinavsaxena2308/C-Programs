#include <stdio.h>

// recursive function for binary search
int binarySearch(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = (low + high) / 2;

        // if key is at mid
        if (arr[mid] == key) {
            return mid;
        }

        // if key is smaller, search in left half
        if (arr[mid] > key) {
            return binarySearch(arr, low, mid - 1, key);
        }

        // else search in right half
        return binarySearch(arr, mid + 1, high, key);
    }
    // if not found
    return -1;
}

int main() {
    int n, i, key, arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d sorted elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    // calling the function
    int result = binarySearch(arr, 0, n - 1, key);

    if (result == -1) {
        printf("Element not found in the array.\n");
    } else {
        printf("Element found at index: %d\n", result);
    }

    return 0;
}
