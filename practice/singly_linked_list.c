#include<stdio.h>
#include<stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

void insertAtBegin(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next  = NULL;

    if(*head == NULL) {
        *head = newNode;
        return;
    }

    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
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

void insertAtPosition(struct Node** head, int position, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next  = NULL;

    struct Node* curr = *head;
    int index = 1;


    while(index < (position-1) && curr->next != NULL) {
        curr = curr->next;
        index++;
    }

    newNode->next = curr->next;
    curr->next = newNode;
}

int deleteAtHead(struct Node** head) {
    if(*head == NULL) return -1;
    int data = (*head)->data;
    *head = (*head)->next;
    return data;
}

int deleteAtEnd (struct Node** head) {
    if(*head == NULL) return -1;
    struct Node* curr = *head;
    while(curr->next->next != NULL) {
        curr = curr->next;
    }

    int data = curr->next->data;
    curr->next = NULL;
    return data;
}


int deleteFromPosition(struct Node** head, int position) {
    if(*head == NULL) return -1;

    struct Node* curr = *head;
    int index = 1;
    while(index < position-1) {
        curr = curr->next;
        index++;
    }

    int data = curr->next->data;

    curr->next = curr->next->next;

    return data;
}


void display(struct Node* head) {
    struct Node* curr = head;
    while(curr != NULL) {
        printf("\n%d ", curr->data);
        curr = curr->next;
    }
}


int main() {
    struct Node* head = NULL;
    insertAtBegin(&head, 4);
    insertAtBegin(&head, 3);
    insertAtBegin(&head, 2);
    insertAtBegin(&head, 1);
    insertAtEnd(&head, 5);
 
    // insertAtPosition(&head, 3, -3);
 
    // display(head);

    // printf("\nDeletion from head: %d", deleteAtHead(&head));
    // display(head);
    // printf("\nDeletion From End: %d", deleteAtEnd(&head));
 
    display(head);
    printf("\nDelete from position 3: %d", deleteFromPosition(&head, 3));
    display(head);
    return 0;
}