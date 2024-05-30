#include<stdio.h>
#include<stdlib.h>


struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

void preorder(struct Node* root) {
    if(root == NULL) return;
    printf("%d\n", root->data);
    preorder(root->left);
    preorder(root->right);
}



void inorder(struct Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    printf("%d\n", root->data);
    inorder(root->right);
}


void postorder(struct Node* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d\n", root->data);
}

int main() {
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = 1;
    root->left = NULL;
    root->right = NULL;
    
    struct Node* leftNode = (struct Node*)malloc(sizeof(struct Node));
    leftNode->data = 2;
    leftNode->left = NULL;
    leftNode->right = NULL;

    root->left = leftNode;

    struct Node* rightNode = (struct Node*)malloc(sizeof(struct Node));
    rightNode->data = 3;
    rightNode->left = NULL;
    rightNode->right = NULL;

    root->right = rightNode;

    printf("\nPre order:\n");
    preorder(root);

    printf("\nIn order:\n");
    inorder(root);

    
    printf("\nPost order:\n");
    postorder(root);
    return 0;
}