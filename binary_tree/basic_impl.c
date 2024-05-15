#include<stdio.h>
#include<stdlib.h>


struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

int INDEX = -1;
struct Node* buildTreePreOrder(int nodes[]) {
    INDEX++;
    if (nodes[INDEX] == -1) {
        return NULL;
    }
    
    struct Node *root = (struct Node*) malloc(sizeof(struct Node));
    root->data = nodes[INDEX];

    root->left = buildTreePreOrder(nodes);
    root->right = buildTreePreOrder(nodes);

    return root; 
}

void preOrderTraversal(struct Node* root) {
    if(root == NULL) return;
    printf(" %d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int search(struct Node* root, int key) {
    if (root == NULL) {
        return 0;
    }

    if (root->data == key) {
        return 1; // 1 means the element was found
    }
    int leftTreeResult = search(root->left, key);
    if(leftTreeResult == 1) {
        return leftTreeResult;
    }


    int rightTreeResult = search(root->right, key);
    if(rightTreeResult == 1) {
        return rightTreeResult;
    }

    return 0;
}

struct Node* insert(struct Node* root, int data) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    if(root == NULL) {
        root = newNode;
        return root;
    } else if(root->left == NULL) {
        root->left = newNode;
        return root;
    } else if (root->right == NULL) {
        root->right = newNode;
        return root;
    } else {
        if(root->left != NULL) {
            root->left = insert(root->left, data);
            return root;
        } else {
            root->right = insert(root->right, data);
            return root;
        }
         
    }
    return root;
}

int main() {

    struct Node* root = NULL;
    int nodes[] =  {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    root = buildTreePreOrder(nodes);
    preOrderTraversal(root);
    
    int does10Exist = search(root, 10);
    printf("\nDoes 10 exist in tree? %d", does10Exist);

    int does5Exist = search(root, 5);
    printf("\nDoes 5 exist in the tree? %d", does5Exist);

    // inserting elements pre order
    printf("\nNew Tree\n");
    struct Node* newRoot = NULL;
    newRoot = insert(newRoot, 9);
    newRoot = insert(newRoot, 1);
    newRoot = insert(newRoot, 2);
    newRoot = insert(newRoot, 6);
    preOrderTraversal(newRoot);

    return 0;
}