#include <stdio.h>
int main() {
    int data[] = {5, 4, 3, 1, 2, 9, 3, 3};
    int item = 3;
    int size = 8;
    int count = 0;
    for(int i =0; i < size; i++) {
        if(item == data[i]) {
            printf("Item found at location %d\n", i);
            count = count + i ;
        }
    }
    if(count == 0) {
        printf("Item not found.");
    }
    return 0;
}