/*
    This file contains all the code from the basic_impl.c and plus two functions
    The two function are used to caulculate height and depth
*/

#include<stdio.h>
#include <stdlib.h>


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

int max(int n1, int n2) {
    if(n1 > n2) return n1;
    else return n2;
}

// use recursion to calc height
// find out the left subtree height and right subtree height
// check which one is max and return it + 1
// +1 is for each level
// This function will calculate the height by add all the nodes and not edges
int height(struct Node* root) {
    if(root == NULL) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}


// DO NOT WRITE MIN AND DEPTH FUNCTION - leave space, its not working
int min(int n1, int n2) {
    if(n1 < n2) return n1;
    else return n2;
}

int depth(struct Node* root, int data, int res) {
    if(root == NULL) return 0;

    if(root->data == data) return res;

    int left = depth(root, data, res + 1);
    if(left != 0) return left;
    return depth(root, data, res + 1);
    
}

int main() {

    struct Node* root = NULL;
    int nodes[] =  {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    root = buildTreePreOrder(nodes);
    preOrderTraversal(root);
    int h = height(root);
    printf("\nHeight of tree: %d", h);   
    int d = depth(root, 5, 1);
    printf("\nDepth of 5 is %d", d);
    return 0;
}