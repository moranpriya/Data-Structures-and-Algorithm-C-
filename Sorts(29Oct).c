#include <stdio.h>

void swap(int *first, int *second) {
    int temp = *first;
   *first = *second;
   *second = temp;
}

void bubbleSort(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void insertionSort(int arr[], int size) {
    int i, j, key;
    for(i = 0; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int size) {
    int i, j, minIndex, temp;
    for(i = 0; i < size - 1; i++) {
        minIndex = i;
        for(j = i + 1; j < size; j++) {
            if(arr[j] < arr[minIndex])
            minIndex = j;
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void display(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {8, 4, 9, 1, 13, 15, 7};
    int size = 7;

    printf("Original array : \n");
    display(arr, size);

    bubbleSort(arr, size);
    printf("\nAfter BubbleSort : \n");
    display(arr, size);

    insertionSort(arr, size);
    printf("\nAfter InsertionSort : \n");
    display(arr, size);

    selectionSort(arr, size);
    printf("\nAfter SelectionSort : \n");
    display(arr, size);

    return 0;
}