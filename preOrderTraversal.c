#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newTreeNode(int item) {
    struct node* newN = (struct node*)malloc(sizeof(struct node));
    newN->data = item;
    newN->left = NULL;
    newN->right = NULL;
    return newN;
}

void preOrder(struct node* root) {
    if(root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    struct node* root = newTreeNode(10);
    root->left = newTreeNode(7);
    root->right = newTreeNode(15);

    printf("Preorder Traversal: ");
    preOrder(root);

    return 0;
}
