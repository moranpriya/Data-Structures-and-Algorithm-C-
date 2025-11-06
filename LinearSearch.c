#include <stdio.h>
int main() {
    int data[] = {5, 4, 3, 1, 2, 9, 8, 7};
    int n = 8;
    int x = 19;

    for (int i = 0; i < n; i++) {
        if (x == data[i]) {
            printf("Item found at location %d\n", i);
            return 0;
        }
    }
    printf("Item not found. ");
    
    return 0;
}