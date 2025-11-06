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

struct node* insert(struct node* head, int item) {
    struct node* new_node = newNode(item);
    if (head == NULL) {
        head = new_node;
        return head;
    }
    new_node->next = head;
    head = new_node;
    return head;
}

struct node* delFromBegin(struct node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    struct node* temp = head;
    head = head->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
    return head;
}

void display(struct node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;
    int choice, item;

    while (1) {
        printf("\n---- Singly Linked List Menu ----\n");
        printf("1. Insert at beginning\n");
        printf("2. Delete from beginning\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter data to insert: ");
            scanf("%d", &item);
            head = insert(head, item);
        } 
        else if (choice == 2) {
            head = delFromBegin(head);
        } 
        else if (choice == 3) {
            display(head);
        } 
        else if (choice == 4) {
            printf("Exiting...\n");
            break;
        } 
        else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
