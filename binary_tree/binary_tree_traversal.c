/*
    Binary Tree: One of the fun DS
*/

#include<stdio.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

void preOrderTraversal(struct Node* root) {
    if(root == NULL) return;
    printf(" %d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(struct Node* root) {
    if(root == NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf(" %d ", root->data);
}

void inOrderTraversal(struct Node* root) {
    if(root == NULL) return;
    inOrderTraversal(root->left);
    printf(" %d ", root->data);
    inOrderTraversal(root->right);
}


int main() {

    struct Node* root = (struct Node*) malloc(sizeof(struct Node));
    root->data = 1;
    root->left = NULL;
    root->right = NULL;

    struct Node* leftNode = (struct Node*) malloc(sizeof(struct Node));
    leftNode->data = 2;
    leftNode->left = NULL;
    leftNode->right = NULL;

    root->left = leftNode;
    
    struct Node* rightNode = (struct Node*) malloc(sizeof(struct Node));;
    rightNode->data = 3;
    rightNode->left = NULL;
    rightNode->right = NULL;

    root->right = rightNode;

    printf("\n Pre Order Traversal\n");
    preOrderTraversal(root);

    printf("\n In Order Traversal\n");
    inOrderTraversal(root);

    printf("\n Post Order Traversal\n");
    postOrderTraversal(root);


    return 0;
}

/*PARSED_BY_CDOCK-©-Shubham-Saurav*/