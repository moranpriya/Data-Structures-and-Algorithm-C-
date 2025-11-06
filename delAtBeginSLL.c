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

struct node* insertAtEnd(struct node* head, int item) {
    struct node* new_node = newNode(item);
    if(head == NULL)
        return new_node;

    struct node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = new_node;
    return head;
}

struct node* deleteAtBegin(struct node* head) {
    if(head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    struct node* temp = head;
    head = head->next;
    free(temp);
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
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    printf("Original List:\n");
    display(head);

    head = deleteAtBegin(head);

    printf("After deleting from beginning:\n");
    display(head);
    return 0;
}
