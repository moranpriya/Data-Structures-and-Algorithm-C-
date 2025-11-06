#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newTreeNode(int item) {
    struct node* newN = (struct node*)malloc(sizeof(struct node));
    newN -> data = item;
    newN -> left = NULL;
    newN -> right = NULL;
    return newN;
}

void inOrder(struct node* root) {
    if(root == NULL) {
        return;
    }

    inOrder(root -> left);
    printf("%d ", root -> data);
    inOrder(root -> right);
}

void preOrder(struct node* root) {
    if(root == NULL) {
        return;
    }

    printf("%d ", root -> data);
    preOrder(root -> left);
    preOrder(root -> right);
}

void postOrder(struct node* root) {
    if(root == NULL) {
        return;
    }

    postOrder(root -> left);
    postOrder(root -> right);
    printf("%d ", root -> data);
}

int getHeight(struct node* root) {
    if(root == NULL) {
        return -1;
    }

    int leftHeight = getHeight(root -> left);
    int rightHeight = getHeight(root -> right);

    if(leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}

int main() {
    struct node* root = newTreeNode(9);
    root -> left = newTreeNode(7);
    root -> left -> left = newTreeNode(8);
    root -> left -> left -> left = newTreeNode(5);
    root -> right = newTreeNode(11);
    root -> right -> left = newTreeNode(10);
    root -> right -> left -> left = newTreeNode(2);
    root -> right -> right = newTreeNode(3);

    printf("In-Order : ");
    inOrder(root);

    printf("\nPre-Order : ");
    preOrder(root);

    printf("\nPost-Order : ");
    preOrder(root);

    printf("\nHeight of the tree is : %d", getHeight(root));

    return 0;
}