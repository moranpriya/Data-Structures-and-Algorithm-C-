#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = value;
    newNode -> left = NULL;
    newNode -> right = NULL;

    return newNode;
}

void inOrder(struct node* root) {
    if(root == NULL) {
        return;
    }

    inOrder(root -> left);
    printf("%d ", root -> data);
    inOrder(root -> right);
}

int main() {
    struct node* root = createNode(10);
    root -> left = createNode(7);
    root -> right = createNode(15);

    printf("In-Order Traversal : ");
    inOrder(root);

    return 0;
}