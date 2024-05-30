#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void enqueue(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next  = NULL;

    if(*head == NULL) {
        *head = newNode;
        return;
    }

    
    struct Node* curr = *head;
    while(curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = newNode;
}

int dequeue(struct Node** head) {
    if(*head == NULL) {
        printf("\nQueue is empty\n");
        return -1;
    }

    int data = (*head)->data;
    *head = (*head)->next;
    return data;
}

void display(struct Node* head) {
    if(head == NULL) return;
    struct Node *curr = head;
    while(curr != NULL) {
        printf("\n%d", curr->data);
        curr=curr->next;
    }
}

int main() {

    struct Node* queue = NULL;
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);
    display(queue);    
    printf("\nDequeued val: %d", dequeue(&queue));
    printf("\ndequeued val: %d", dequeue(&queue));

    display(queue);

    return 0;
}
