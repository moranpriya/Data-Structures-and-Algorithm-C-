#include <stdio.h>
#define MAXSIZE 20

struct stack {
    int arr[MAXSIZE];
    int top;
};

void push(struct stack *stk, int key) {
    //check if stack is full
    if(stk->top == MAXSIZE - 1) {
        printf("Overflow\n");
        return;
    }
    stk->top = stk->top+1;
    stk->arr[stk->top] = key;
}

int pop(struct stack *stk) {
    //check if stack empty
    int popped_item;
    if(stk->top == -1) {
        printf("Underflow\n");
        return -1;
    }
    popped_item = stk->arr[stk->top];
    stk->top = stk->top-1;
    return popped_item;
}
/*void display(struct stack stk) {
    for(int i = 1; i < MAXSIZE; i++) {
        printf("%d", stk.arr[i]);
    }
}*/

int main() {
    struct stack stk1;
    stk1.top = -1;
    int x;

    push(&stk1, 6);
    push(&stk1, 5);
    push(&stk1, 4);
    push(&stk1, 3);

    x = pop(&stk1);
    printf("%d ", x);
    x = pop(&stk1);
    printf("%d ", x);
    
    push(&stk1, 9);

    x = pop(&stk1);
    printf("%d ", x);

    return 0;
}