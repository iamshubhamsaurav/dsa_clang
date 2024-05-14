
#include<stdio.h>
#include<stdlib.h>

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

void inOrderTraversal(struct Node* root) {
    if(root == NULL) return;
    inOrderTraversal(root->left);
    printf(" %d ", root->data);
    inOrderTraversal(root->right);
}

struct Node* insert(struct Node* root, int data) {
    if(root == NULL) {
        struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        root = newNode;
        return root;
    } else if (root->data < data) {
        root->right = insert(root->right, data);
    } else if (root-> data) {
        root->left = insert(root->left, data);
    }

    return root;
}

int main() {
    
    struct Node *root = NULL;
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 5);
    inOrderTraversal(root);

    return 0;
}