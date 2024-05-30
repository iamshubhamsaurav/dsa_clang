
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
    } else {
        root->left = insert(root->left, data);
    }

    return root;
}

// return 1 if the element exists in the tree
// return 0 if the element does not exist in the tree
int search(struct Node* root, int key) {
    if(root == NULL) {
        return 0; // if the root if null then it means that the key does not exist in the subtree, so return 0
    } else if(root->data == key) {
        return 1; // if the data of root matches with the key(i.e the element exists in the tree) then return 1 
    } else if(root->data < key) { // if key is greater then data of root then it means the key is in the right subtree. so recursively go though the right subtree
        return search(root->right, key);
    } else { // this else part will run when key is less than root's data - so we will go though the left subtree using recursion
        return search(root->left, key);
    }
}

int main() {
    
    struct Node *root = NULL;
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 5);
    inOrderTraversal(root);

    int does5Exist = search(root, 5);
    printf("\nDoes 5 exist in BST? %d", does5Exist);

    int does27Exist = search(root, 27);
    printf("\nDoes 27 exist in BST? %d", does27Exist);

    return 0;
}