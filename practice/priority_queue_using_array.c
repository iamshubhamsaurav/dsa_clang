#include<stdio.h>
#include<stdlib.h>

int rear = -1;
int capacity = 3;
int arr[3];


int isFull() {
    return rear == capacity - 1;
}

int isEmpty() {
    return rear == -1;
}

void enqueue(int value) {
    if(isFull()) {
        printf("\nQueue is full");
        return;
    }
    rear++;
    arr[rear] = value;
    
    int index = rear;
    while (index != 0 && arr[index] < arr[index -1]) {
        int temp = arr[index];
        arr[index] = arr[index - 1];
        arr[index - 1] = temp;
        index--;
    }
}

int dequeue() {
    if(isEmpty()) {
        printf("\nQueue is empty");
        return -1;
    }

    int data = arr[0];
    for(int i = 1; i <= rear; i++) {
        arr[i-1] = arr[i];
    }

    rear--;

    return data;
}

void display() {
    for (int i = 0; i <= rear; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main() {
    enqueue(2);
    enqueue(3);
    enqueue(1);
    display();
    return 0;
}
