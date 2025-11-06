#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* newNode(int item) {
    struct node* newN = (struct node*)malloc(sizeof(struct node));
    newN -> data = item;
    newN -> next = NULL;
    return newN;
}

struct node* insert(struct node* head, int item) {
    struct node* new_node = newNode(item);

    if(head == NULL) {
        head = new_node;
        return head;
    }
    new_node -> next = head;
    head = new_node;
    return head;
}


// Delete a node from the end
struct node* delFromEnd(struct node* head) {
    // Check if list is empty
    if(head == NULL) {
        printf("List is empty\n");
        return head;
    }

    struct node* curr = head;
    // Traverse to the last second node.
    while(curr -> next -> next != NULL) {
        curr = curr -> next;
    }

    struct node* temp = curr -> next;
    curr -> next = NULL;

    free(temp);
    return head;
}

void displayList(struct node* head) {
    struct node* curr = head;

    while(curr != NULL) {
        printf("%d ", curr -> data);
        curr = curr -> next;
    }
}

int main() {
    struct node* head = NULL;
    head = insert(head, 5);
    head = insert(head, 7);
    head = insert(head, 8);
    head = insert(head, 9);

    displayList(head);
    printf("\n");

    head = delFromEnd(head);
    displayList(head);

    return 0;
}