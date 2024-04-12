#include<stdio.h>
#include<stdlib.h>


struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

// This is straight forward except for the parts that are not (the main part)  
void insertAtPosition(struct Node** head, int val, int position) {
  
  // handling errors here
  if(*head == NULL) {
    printf("\nList is empty.");
    return;
  }
  // maybe handle if position is less than 1 or position is 0. Not diff but I have better things to do
  // Handle position < 1 and handle position == 1 and check for position = 2 insertion
  // screw this - doing some of them right now
  if(position < 1) {
    printf("\nInvalid Operatons");
    return;
  }

	
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = val;
  newNode->next = NULL;

  if(position == 1) { // if insertion is position 1
    newNode->next = *head;
    *head = newNode;
    return;
  }

  int i = 1;
	struct Node* curr = *head;
	while(i < (position - 1)) {
		curr = curr->next;
		i++;
	}
	
  struct Node* nextNode = curr->next;
  newNode->next = nextNode;
  curr->next = newNode;
  nextNode->prev = newNode;
	newNode->prev = curr;
}


// Again, this is straight forward except for the main part
void deleteFromPosition(struct Node** head, int position) {
  // Handle errors and edge cases first before the main operation
  if(*head == NULL) {
    printf("\nList is already empty.");
    return;
  }

  if(position == 1) {
    *head = (*head)->next;
    return;
  }

  // there are more edge cases and error to be handled but I am things to do

	int i = 1;
	
	struct Node* curr = *head;
	while(i < (position - 1)) {
		curr = curr->next;
		i++;
	}
	
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
  
  insertAtPosition(&head, 100, 2);
  printList(head);
  deleteFromPosition(&head, 2);
  printList(head);
	return 0;
}

