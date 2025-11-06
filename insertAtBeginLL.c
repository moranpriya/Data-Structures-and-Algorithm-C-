#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* newNode(int item) {
    struct node* newN = (struct node*)malloc(sizeof(struct node));
    newN->data = item;
    newN->next = NULL;
    return newN;
}

struct node* insertAtBegin(struct node* head, int item) {
    struct node* new_node = newNode(item);
    new_node->next = head;
    head = new_node;
    return head;
}

void display(struct node* head) {
    struct node* curr = head;
    while(curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    head = insertAtBegin(head, 10);
    head = insertAtBegin(head, 20);
    head = insertAtBegin(head, 30);

    printf("Linked List after insertion at beginning:\n");
    display(head);
    return 0;
}
