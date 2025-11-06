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

struct node* insertAtPos(struct node* head, int item, int pos) {
    struct node* new_node = newNode(item);
    if(pos == 1) {
        new_node->next = head;
        head = new_node;
        return head;
    }

    struct node* temp = head;
    for(int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL) {
        printf("Invalid position!\n");
        return head;
    }

    new_node->next = temp->next;
    temp->next = new_node;
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
    head = insertAtPos(head, 10, 1);
    head = insertAtPos(head, 20, 2);
    head = insertAtPos(head, 15, 2);

    printf("Linked List after insertion at specific position:\n");
    display(head);
    return 0;
}
