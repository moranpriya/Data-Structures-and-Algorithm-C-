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

void postOrder(struct node* root) {
    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

int main() {
    struct node* root = newTreeNode(10);
    root->left = newTreeNode(7);
    root->right = newTreeNode(15);

    printf("Postorder Traversal: ");
    postOrder(root);

    return 0;
}