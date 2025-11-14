#include <stdio.h>                // Include standard I/O library

// To heapify a sub-tree rooted with node i
void heapify(int arr[], int n, int i) {
    int largest = i;             // Initialize largest as root
    int left = 2 * i + 1;        // Left child index = 2 * i + 1
    int right = 2 * i + 2;       // Right child index = 2 * i + 2

    if(left < n && arr[left] > arr[largest])  // If left child is larger than root
        largest = left;

    if(right < n && arr[right] > arr[largest]) // If right child is larger than root
        largest = right;

    if(largest != i) {           // If largest is not the root
        int temp = arr[i];       // Swap root with largest child
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest); // Recursively heapify the affected sub-tree
    }
}

// Main function to be called heap sort
void heapSort(int arr[], int n) {
    for(int i = n / 2 - 1; i >= 0; i--)   // Build max heap (rearrange vector)
        heapify(arr, n, i);

    for(int i = n - 1; i > 0; i--) {      // Extract elements from heap one by one
        int temp = arr[0];                // Move top (max) to end
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);               // Heapify reduced heap
    }
}

int main() {
    int arr[] = {9, 4, 3, 8, 10, 2, 5};   // Input array
    int n = 7;                            // Array size

    heapSort(arr, n);                     // Call heap sort

    for(int i = 0; i < n; i++)            // Print sorted array
        printf("%d ", arr[i]);

    return 0;                             // Exit the program
}
