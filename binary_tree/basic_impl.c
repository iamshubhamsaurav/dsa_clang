#include<stdio.h>


struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};





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




    return 0;
}