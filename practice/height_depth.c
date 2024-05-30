#include<stdio.h>
#include<stdlib.h>


struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

void inorder(struct Node* root) {
    if(root == NULL) return;
    preorder(root->left);
    printf("%d\n", root->data);
    preorder(root->right);
}


int max(int n1, int n2) {
    if(n1 > n2) return n1;
    else n2;
}


int height(struct Node* root) {
    if(root == NULL) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}


int depth(struct Node* root) {
    
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





    printf("\nIn order:\n");
    inorder(root);

    
    return 0;
}