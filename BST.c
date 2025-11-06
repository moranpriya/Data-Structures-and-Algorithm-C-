#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int item) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = item;
    new_node -> left = NULL;
    new_node -> right = NULL;

}

void inOrder(struct node* root) {
    if(root == NULL) {
        return;
    }

    inOrder(root -> left);
    printf("%d ", root -> data);
    inOrder(root -> right);
}

struct node* insert(struct node* root, int item) {
    struct node* new_node = newNode(item);
    if(root == NULL) {
        return new_node;
    }
    if(item < root -> data) {
        root -> left = insert(root -> left, item);
    } else if(item > root -> data) {
        root -> right = insert(root -> right, item);
    }
}

int search(struct node* root, int key) {
    if(root == NULL) {
        return 0;
    } 
    if(key == root -> data) {
        return -1;
    } else if(key < root -> data) {
        return search(root -> left, key);
    }
}

int main() {
    struct node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 11);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 50);

    printf("In-Order : ");
    inOrder(root);
    printf("\n");

    if(search(root, 11)) {
        printf("Item 11 found.\n");
    }
    if(search(root, 9)) {
        printf("Item 9 found.\n");
    } else {
        printf("Item 9 not found.\n");
    }

    return 0;
}