#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 2, 4, 5, 1, 6, 3};
    int n = 9 ;

    printf("Duplicate elements: ");
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                printf("%d ", arr[i]);
                break;
            }
        }
    }
    return 0;
}