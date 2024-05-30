#include<stdio.h>
#include<stdlib.h>

int maxSize = 3;
int rear = -1;

int arr[3];// whatever maxSize value is

int isFull() {
    return rear == (maxSize - 1);
}

int isEmpty() {
    return rear == -1;
}

void enqueue(int data) {
    if(isFull()) {
        printf("\nQueue is full");
        return;
    }

    rear++;
    arr[rear] = data;
}

int size() {
    return rear + 1;
}


int dequeue() {
    if(isEmpty()) {
        printf("\nQueue is already empty");
        return -1;
    }

    int data = arr[0];

    // Shifting the data
    for (int i = 1; i <= rear; i++)
    {
        arr[i-1] = arr[i];
    }
    rear--;
    
    return data;
}

int peek() {
    if(isEmpty()) {
        printf("\nQueue is empty");
        return -1;
    }
    return arr[0];
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    printf("\nPeek: %d", peek());
    printf("\nDequeue: %d", dequeue());
    printf("\nPeek: %d", peek());
    printf("\nSize: %d", size());

    return 0;
}