#include <stdio.h>
#define MAXSIZE 20

struct queue {
    int arr[MAXSIZE];
    int front;
    int rear;
};

void enqueue(struct queue *q, int key) {
    // check if queue is full
    if(q->rear == MAXSIZE - 1) {
        printf("Overflow\n");
        return;
    }
    if(q->front == -1)   // first element being inserted
        q->front = 0;
    q->rear = q->rear + 1;
    q->arr[q->rear] = key;
}

int dequeue(struct queue *q) {
    // check if queue is empty
    if(q->front == -1 || q->front > q->rear) {
        printf("Underflow\n");
        return -1;
    }
    int deleted_item = q->arr[q->front];
    q->front = q->front + 1;
    return deleted_item;
}

void display(struct queue q) {
    if(q.front == -1 || q.front > q.rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for(int i = q.front; i <= q.rear; i++) {
        printf("%d ", q.arr[i]);
    }
    printf("\n");
}

int main() {
    struct queue q1;
    q1.front = -1;
    q1.rear = -1;

    enqueue(&q1, 10);
    enqueue(&q1, 20);
    enqueue(&q1, 30);

    display(q1);

    printf("Dequeued: %d\n", dequeue(&q1));
    printf("Dequeued: %d\n", dequeue(&q1));

    display(q1);

    enqueue(&q1, 40);
    enqueue(&q1, 50);

    display(q1);

    return 0;
}