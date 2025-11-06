#include <stdio.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j< high; j++) {
        if(arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void QuickSort(int arr[], int low, int high) {
    if(low < high) {
        int p_idx = partition(arr, low, high);
        QuickSort(arr, low, p_idx-1);
        QuickSort(arr, p_idx+1, high);
    }
}

int main() {
    int arr[] = {8, 1, 3, 9, 4, 5};
    int size = 6;
    QuickSort(arr, 0, size-1);

    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}