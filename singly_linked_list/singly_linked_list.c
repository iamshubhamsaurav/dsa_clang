#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertAtBeginning(struct Node **head, int data)
{
    // For some reason, the statement written below is not working.
    // struct Node* newNode = NULL;

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    // Save the data in newNode
    newNode->data = data;

    // point the next to head
    newNode->next = *head;

    // Update the head with the new head value
    *head = newNode;
}

void printList(struct Node *node)
{
    printf("\n");
    while (node != NULL)
    {
        printf("%d \n", node->data);
        node = node->next;
    }
}

void insertAtPosition(int position, struct Node **head, int data)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    struct Node *curr = *head;
    int i = 1;
    //|| curr->next != NULL
    while (i < (position - 1))
    {
        curr = curr->next;
        i++;
    }

    newNode->next = curr->next;
    curr->next = newNode;
}

void insertAtEnd(struct Node **head, int data)
{

    // (struct Node*) is the type casting
    // malloc(sizeof(struct Node)) will allocate memory of size Node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    // Save the data in the newNode
    newNode->data = data;
    newNode->next = NULL;

    struct Node *curr = *head;

    // go through the list until the next node is found to be NULL
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    // when the next node is NULL. Make the newNode as the next node.
    curr->next = newNode;
}

void removeFromBeginning(struct Node **head)
{
    // check if head is null, if null display error and return
    if (*head == NULL)
    {
        printf("\n List is already empty");
        return;
    }
    // make head.next the next head
    struct Node *newHead = (struct Node *)malloc(sizeof(struct Node));
    newHead = (*head)->next;
    *head = newHead;
}

// remove node from the end
void removeFromEnd(struct Node **head)
{
    // check if head is null
    if (*head == NULL)
    {
        printf("\nList is already empty");
        return;
    }
    struct Node *curr = (struct Node *)malloc(sizeof(struct Node));
    curr = *head;
    while (curr->next->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = NULL;
}

void removeFromPosition(struct Node **head, int position)
{
    if (*head == NULL)
    {
        printf("\nList is already empty.");
        return;
    }

    if (position < 1)
    {
        printf("\nInvalid position");
        return;
    }

    if (position == 1)
    {
        *head = (*head)->next;
        return;
    }

    struct Node *curr = *head;
    int i = 1;

    while ((i < (position - 1)) && (curr->next != NULL))
    {
        curr = curr->next;
        i++;
    }

    curr->next = curr->next->next;
}

int main()
{
    struct Node *head = NULL;
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    insertAtEnd(&head, 10);
    printList(head);
    printf("\n");

    insertAtPosition(3, &head, 7);

    printList(head);
    printf("\n");
    printf("***");
    removeFromBeginning(&head);
    printf("*removeFromBeginning**");
    printList(head);
    insertAtBeginning(&head, 3);
    insertAtEnd(&head, 4);
    printList(head);
    removeFromEnd(&head);
    removeFromPosition(&head, 2);
    printf("**end*");
    printList(head);
    return 0;
}
