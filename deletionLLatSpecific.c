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


// Delete node from the specific position.
struct node* delFromPos(struct node* head, int pos) {
    // Case 1: If the list is empty
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    struct node* temp = head;

    // Case 2: If deleting the first node
    if (pos == 1) {
        head = head->next;
        free(temp);
        return head;
    }

    // Case 3: Traverse to the node just before the position
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    // Case 4: If position is invalid (beyond list length)
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position\n");
        return head;
    }

    // Case 5: Delete the target node and reconnect links
    struct node* delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);

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

    head = delFromPos(head, 1);
    displayList(head);

    return 0;
}

// 15 Oct