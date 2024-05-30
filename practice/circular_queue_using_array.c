#include<stdio.h>
#include<stdlib.h>

int front = 0;
int size = 0;
int capacity = 3;
int arr[3];


int isFull() {
    return size == capacity;
}

int isEmpty() {
    return size == 0;
}

int getFront() {
    if(isEmpty()) {
        return -1;
    }
    return front;
}


int getRear() {
    if(isEmpty()) {
        return -1;
    }
    return (front + (size - 1)) % capacity;
}


void enqueue(int value) {
    if(isFull()) {
        printf("\nQueue is already full");
        return;
    }

    int rear = getRear();
    rear = (rear + 1) % capacity;
    arr[rear] = value;
    size++;
}

int dequeue() {
    if(isEmpty()) {
        printf("\nQueue is already empty");
        return;
    }

    int front = (front + 1) % capacity;
    size--;
}

int main() {

    // testing remaining

    return 0;
}
