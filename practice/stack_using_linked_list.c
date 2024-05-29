#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* prev;
};

void push(struct Node** top, int data) {
    //create the node first
    struct Node *newTopNode = (struct Node*)malloc(sizeof(struct Node));
    newTopNode->data = data;
    newTopNode->prev = NULL;  
    
    //if top of the stack is null then assign newTopNode to top, making it(newTopNode) the new top
    if(*top == NULL) {
        *top = newTopNode;
        return;
    }

    newTopNode->prev = *top;
    *top = newTopNode;
    return;
}

// just for checking if the code is working fine or not.
void displayTopToBottom(struct Node* top) {
    
    if(top == NULL) {
        printf("\nStack is empty");
        return;
    }

    struct Node* curr = (struct Node*)malloc(sizeof(struct Node));
    curr = top;

    while(curr != NULL) {
        printf("\n %d", curr->data);
        curr = curr->prev;
    }
}

int pop(struct Node** top) {
    if(*top == NULL) {
        printf("\nStack is empty");
        return -1;
    }
    int data = (*top)->data;
    (*top) = (*top)->prev;
    return data;
}


int main() {
    struct Node* top = NULL;
    push(&top, 1);
    push(&top, 2);
    push(&top, 3);
    displayTopToBottom(top);
    pop(&top);
    displayTopToBottom(top);
    return 0;
}
