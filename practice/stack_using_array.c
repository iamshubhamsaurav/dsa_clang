#include<stdio.h>
#include<stdlib.h>


int maxSize = 3;
int top = -1;

int arr[3];

int isFull() {
    return top == (maxSize - 1);
}

int isEmpty() {
    return top == -1;
}

void push(int data) {
    if(isFull()) {
        printf("\nStack is full. Cannot push new values");
        return;
    }
    top++;
    arr[top] = data;
}

int pop() {
    if(isEmpty()) {
        printf("\nStack is already empty");
        return -1;
    }
    int data = arr[top];
    arr[top] = 0;
    top--;
    return data;
}

int peek() {
    if(isEmpty()) {
        printf("\nStack is already empty");
        return -1;
    }
    return arr[top];
}


int main() {
    printf("\nIs Stack Empty? %d", isEmpty());
    push(1);
    push(2);
    push(3);
    printf("\nTop of the stack: %d", peek());
    printf("\nIs Stack Full? %d", isFull());
    printf("\nTop of the stack poped: %d", pop());
    printf("\nTop of the stack: %d", peek());
    printf("\nIs Stack Full? %d", isFull());
 
    return 0;
}