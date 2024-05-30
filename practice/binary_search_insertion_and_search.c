#include<stdio.h>
#include<stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* insert(struct Node* root, int data) {
    if(root == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        root = newNode;
        return root;
    } else if (root->data < data) {
        root->right = insert(root->right, data);
        return root;
    } else {
        root->left = insert(root->left, data);
        return root;
    }
    return root;
}

// -1 means not found - 1 means found
int search(struct Node* root, int data) {
    if(root == NULL) {
        return -1;
    }
    if(root->data == data) {
        printf("\nValue found in tree\n");
        return 1;
    } else if (root->data > data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }

    return -1;
}

void inorder(struct Node* root) {
    if(root == NULL) return;
    
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}


int main() {
    struct Node* root = NULL;
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 5);
    root = insert(root, 7);
    inorder(root);

    search(root, 1);
    search(root, 7);
    search(root, -2);
    search(root, 90);
    return 0;
}
