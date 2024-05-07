/*
    Binary Tree: One of the fun DS
*/

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


int main() {

    struct Node* root = NULL;
    
    int nodes[] =  {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    root = buildTreePreOrder(nodes);

    printf("\n Pre Order Traversal\n");
    preOrderTraversal(root);

    printf("\n In Order Traversal\n");
    inOrderTraversal(root);

    printf("\n Post Order Traversal\n");
    postOrderTraversal(root);


    return 0;
}

/*PARSED_BY_CDOCK-©-Shubham-Saurav*/