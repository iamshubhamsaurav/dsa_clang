#include<stdio.h>
#include<stdlib.h>


struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

// Fix  this function -- incorrect - seg fault result
void insertAtPosition(struct Node** head, int val, int position) {
	int i = 1;
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = val;
	
	struct Node* curr = *head;
	while(i < position) {
		curr = curr->next;
		i++;
	}
	// problem lies here
	newNode->next = curr->next;
	curr->next->prev = newNode;
	curr->next = newNode;
	newNode->prev = curr;
}


// Fix this function -- incorrect - seg fault result
void deleteFromPosition(struct Node** head, int position) {
	int i = 1;
	
	struct Node* curr = *head;
	while(i < position) {
		curr = curr->next;
		i++;
	}
	// problem probably lies here
	struct Node* nextNextNode = curr->next->next;
	curr->next = nextNextNode;
	nextNextNode->prev = curr;
}


void insertAtBegin(struct Node** head, int val) {
	// Creation of newNode
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = val;
	
	if(*head == NULL) {
		newNode->next = NULL;
		newNode->prev = NULL;
		*head = newNode;
		
		return;
	}
	
	struct Node* headNode = *head;	
	//(*head)->prev = newNode;
	//newNode->next->prev = newNode;
	headNode->prev = newNode;
	newNode->next = *head;
	newNode->prev = NULL;
	*head=newNode;
}


void printList(struct Node *head) {
	while(head != NULL) {
		printf("\n%d", head->data);
		head = head->next;
	}
	printf("\n");
}


void insertAtEnd(struct Node** head, int val) {
		// Creation of newNode
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = val;
	
	if(*head == NULL) {
		newNode->next = NULL;
		newNode->prev = NULL;
		*head = newNode;
		
		return;
	}
	
	
	struct Node* curr = *head;
	
	while(curr->next != NULL) {
		curr=curr->next;
	}
	
	newNode->prev = curr;
	newNode->next = NULL;
	curr->next = newNode;
		
}


int removeFromBegining(struct Node** head) {
	if(*head == NULL) {
		printf("\nList is already empty");
		return -1;
	}
	
	struct Node* headNode = *head;
	int data = headNode->data;
	*head = headNode->next;
	return data;
}


int removeFromEnd(struct Node** head) {
	if(*head == NULL) {
		printf("\nList is already empty");
		return -1;
	}
	
	struct Node* curr = *head;
	
	while(curr->next->next != NULL) {
		curr=curr->next;
	}
	int data = curr->data;
	curr->next = NULL;
	
	return data;
}


int main() {
	struct Node* head = NULL;
	
	insertAtBegin(&head, 12);
	insertAtBegin(&head, 16);
	
	insertAtEnd(&head, 20);
	//insertAtPosition(&head, 22, 4); 
	insertAtEnd(&head, 24);
	insertAtEnd(&head, 26);
	insertAtEnd(&head, 28);
	
	
	printList(head);
	
	
	int el1 = removeFromEnd(&head);
	printf("Element Removed From End: %d", el1);	
	printList(head);
	
	int el2 = removeFromBegining(&head);
	printf("Element Removed From Begining: %d", el2);	
	printList(head);
	
	return 0;
}

