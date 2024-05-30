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


// This is an easy to understand solution.
// I will use the slow and fast pointer approach but that would be tricky to understand. So use this instead

int middleOddTerm(struct Node** head) {
    if(*head == NULL) return -1;

    int totalOddTerm = 0;

    struct Node* curr = *head;
    while(curr->next != NULL) {
        if(curr->data % 2 != 0) {
            totalOddTerm++;
        }
        curr = curr->next;
        
    }

    int middleOddNumIndex = (totalOddTerm / 2 ) + 1;
    curr = *head;
    int index = 0;
    while(index < middleOddNumIndex) {
        if(curr->data % 2 != 0) {
            index++;
        }
        if(index == middleOddNumIndex) {
            return curr->data;
        }
        curr = curr->next;
        
    }

    return -1;
}

// same as middleOddTerm - only the variable names and two operators have changed (!= changed to ==)
int middleEvenTerm(struct Node** head) {
    if(*head == NULL) return -1;

    int totalEvenTerm = 0;

    struct Node* curr = *head;
    while(curr->next != NULL) {
        if(curr->data % 2 == 0) {
            totalEvenTerm++;
        }
        curr = curr->next;
        
    }

    int middleEvenNumIndex = (totalEvenTerm / 2 ) + 1;
    curr = *head;
    int index = 0;
    while(index < middleEvenNumIndex) {
        if(curr->data % 2 == 0) {
            index++;
        }
        if(index == middleEvenNumIndex) {
            return curr->data;
        }
        curr = curr->next;
        
    }

    return -1;
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
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 9);
    insertAtEnd(&head, 19);
    insertAtEnd(&head, 129);
    insertAtEnd(&head, 8);
 
    display(head);
 
    printf("\nMiddle odd term: %d", middleOddTerm(&head));
    printf("\nMiddle even term: %d", middleEvenTerm(&head));
    return 0;
}