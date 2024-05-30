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


/*
Depth of a node
The basic idea of depth is to find the distance between a node and the root node
Algorithm:
    if root is empty then return null
    if node is found then return 0
    else
        go through left and right subtree recursively- don't worry about anything -> recursion will go the magic
    return the distance + 1 (+ 1 beacause if we want to include the root in distance as well)
*/

int depth(struct Node* root, int data) {

    // if root is null the return -1 -> because the tree does not exist
    if (root == NULL) return -1;


    if(root->data == data) { // node found
        return 0;
    }

    // node not found - go through the left and right sub tree recursively
    int leftDistance = depth(root->left, data);
    int rightDistance = depth(root->right, data);

    if (leftDistance != -1) {
      return leftDistance + 1;
    } else if (rightDistance != -1) {
      return rightDistance + 1;
    } else {
      return -1;
    }

}


struct Node* invertTree(struct Node* root) {
    if(root == NULL) {
        return NULL;
    }

    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertTree(root->left);
    invertTree(root->right);
    return root;
}


int main() {

    struct Node* root = NULL;
    int nodes[] =  {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    root = buildTreePreOrder(nodes);
    preOrderTraversal(root);
    int h = height(root);
    printf("\nHeight of tree: %d", h);   
    int d = depth(root, 5);
    printf("\nDepth of 5 is %d", d);
    
    // Invert the tree - recursively swapping the left and right till the end
    root = invertTree(root);
    printf("\n");
    preOrderTraversal(root);
 
    return 0;
}