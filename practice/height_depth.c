#include<stdio.h>
#include<stdlib.h>


struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

void inorder(struct Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    printf("%d\n", root->data);
    inorder(root->right);
}


int max(int n1, int n2) {
    if(n1 > n2) return n1;
    else return n2;
}


int height(struct Node* root) {
    if(root == NULL) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}


int depth(struct Node* root, int data) {
    if(root == NULL) {
        return -1;
    }

    if(root->data == data) {
        return 0;
    }

    int leftDistance = depth(root->left, data);
    int rightDistance = depth(root->right, data);

    if(leftDistance != -1) return leftDistance + 1;
    else if (rightDistance != -1) return rightDistance + 1;
    else return -1;  
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

    struct Node* rightLeftNode = (struct Node*)malloc(sizeof(struct Node));
    rightLeftNode->data = 4;
    rightLeftNode->left = NULL;
    rightLeftNode->right = NULL;

    root->right->left = rightLeftNode;


    printf("\nHeight of tree: %d", height(root));
    printf("\nDepth of %d is %d", 4, depth(root, 4));


    // printf("\nIn order:\n");
    // inorder(root);

    
    return 0;
}