#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void addAtHead(struct Node** head, int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }

    // adding value and swapping it with head

    newNode->next = (*head)->next;
    (*head)->next = newNode;

    int temp = (*head)->data;
    (*head)->data = newNode->data;
    newNode->data = temp;


}

void addAtTail(struct Node** head, int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }

    // adding value and swapping it with head

    newNode->next = (*head)->next;
    (*head)->next = newNode;

    int temp = (*head)->data;
    (*head)->data = newNode->data;
    newNode->data = temp;

    *head = newNode;
}

int deleteAtHead(struct Node** head) {
    if(*head == NULL) {
        printf("\nlist is empty");
        return -1;
    }
    // saving the value of head->next in head 
    // then removing the head->next
    int data = (*head)->data;
    (*head)->data = (*head)->next->data;
    (*head)->next = (*head)->next->next;
    return data;
}

int deleteAtTail(struct Node** head) {
    if(*head == NULL) {
        printf("\nlist is empty");
        return -1;
    }

    struct Node* curr = *head;
    while(curr->next->next != *head) {
        curr = curr->next;
    }

    curr->next = curr->next->next;
}

void display(struct Node* head) {
    struct Node* curr = head;
    printf("%d ", curr->data);
    while(curr->next != head) {
        curr = curr->next;
        printf("%d ", curr->data);
    }
    printf("\n");
}


int main() {
    struct Node* head = NULL;
    addAtHead(&head, 1);
    addAtHead(&head, 2);
    addAtHead(&head, 3);
    display(head);
    addAtTail(&head, 4);
    display(head);
    // deleteAtHead(&head);
    // display(head);

    deleteAtTail(&head);
    display(head);
    return 0;
}