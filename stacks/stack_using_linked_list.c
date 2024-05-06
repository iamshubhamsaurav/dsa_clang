#include <stdio.h>
#include <stdlib.h>

/*
    Stack Using Linked List
    TODO: Push and Pop should run in constant time otherwise quit coding
*/

struct Node
{
    int data;
    struct Node *prev;
};


void push(struct Node** top, int data) {
    struct Node *newTop = (struct Node *)malloc(sizeof(struct Node));
    newTop->data = data;
    newTop->prev = NULL;

    // if stack is null then create the new node and update the top and return
    if(*top == NULL) {
        *top = newTop;
        return;
    }

    // set the prev of newNode to the current top and then update the top
    newTop->prev = (*top);
    *top = newTop;
    return;
}

int pop(struct Node** top) {
//     // if stack is null - print and return
    if(*top == NULL) {
        printf("\nStack is empty");
        return -1;
    }

    // if stack has only 1 element then set the top to null and return
    if((*top)->prev == NULL) {
        *top = NULL;
        int data = (*top)->data;
        return data;
    }
    int data = (*top)->data;
    *top = (*top)->prev;
    return data;
}

int main() {
    struct Node *top = NULL;
    push(&top, 1);
    push(&top, 2);
    push(&top, 3);
    
    printf("\nTop = %d", top->data);
    int el = pop(&top);
    printf("\nPopped item: %d", el);
    printf("\nTop = %d", top->data);
    return 0;
}