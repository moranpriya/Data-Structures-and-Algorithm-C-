#include <stdio.h>

int binarySearchFirst(int arr[], int n, int x) {
    int low = 0, high = n - 1, result = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x) {
            result = mid;
            high = mid - 1;  // Continue searching in left half for first occurrence
        }
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return result;
}

int main() {
    int arr[] = {2, 4, 4, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 4;

    int result = binarySearchFirst(arr, n, x);

    if (result == -1)
        printf("Element not found in the array.\n");
    else
        printf("First occurrence of %d found at index %d.\n", x, result);

    return 0;
}