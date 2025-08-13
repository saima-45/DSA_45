#include <stdio.h>
#include <stdlib.h>

// Define the Node structure for Singly Linked List
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int main() {
    struct Node* head = NULL; // Empty list initially
    // Your code here for operations like Insert, Delete, etc.

    return 0;
}

// Function Prototypes for Singly Linked List Operations
struct Node* createNode(int value);
struct Node* insertAtBeginning(struct Node* head, int value);
struct Node* insertAtEnd(struct Node* head, int value);
struct Node* insertAtPosition(struct Node* head, int value, int pos);
struct Node* deleteFromBeginning(struct Node* head);
struct Node* deleteFromEnd(struct Node* head);
struct Node* deleteNode(struct Node* head, int key);
int search(struct Node* head, int key);
void displayList(struct Node* head);

//Q3

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
    return head;
}
