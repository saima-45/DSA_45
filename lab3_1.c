//1. Write Algorithm/Pseudocode for following operations on a Singly Linked Lists

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* insertAtBeginning(struct Node* head, int data);
struct Node* insertAtEnd(struct Node* head, int data);
struct Node* insertAfter(struct Node* head, int key, int data);
struct Node* insertBefore(struct Node* head, int key, int data);
struct Node* deleteFromBeginning(struct Node* head);
struct Node* deleteFromEnd(struct Node* head);
struct Node* deleteAfter(struct Node* head, int key);
void displayList(struct Node* head);
int searchElement(struct Node* head, int key);
int countNodes(struct Node* head);
struct Node* reverseList(struct Node* head);

// Main function
int main() {
    struct Node* head = NULL;

    // Insertions
    head = insertAtBeginning(head, 30);
    head = insertAtBeginning(head, 20);
    head = insertAtEnd(head, 40);
    head = insertAfter(head, 30, 35);
    head = insertBefore(head, 30, 25);

    printf("Linked List after insertions: \n");
    displayList(head);

    // Search
    int key = 35;
    printf("Searching for %d: %s\n", key, searchElement(head, key) ? "Found" : "Not Found");

    // Count
    printf("Total nodes in list: %d\n", countNodes(head));

    // Deletions
    head = deleteFromBeginning(head);
    head = deleteFromEnd(head);
    head = deleteAfter(head, 25);

    printf("\nLinked List after deletions: \n");
    displayList(head);

    // Reverse list
    head = reverseList(head);
    printf("\nReversed Linked List: \n");
    displayList(head);

    return 0;
}

// Insert at beginning
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

// Insert at end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

// Insert after a given node
struct Node* insertAfter(struct Node* head, int key, int data) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Key %d not found\n", key);
        return head;
    }

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Insert before a given node
struct Node* insertBefore(struct Node* head, int key, int data) {
    if (head == NULL) return NULL;

    if (head->data == key)
        return insertAtBeginning(head, data);

    struct Node *prev = NULL, *curr = head;
    while (curr != NULL && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Key %d not found\n", key);
        return head;
    }

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = curr;
    prev->next = newNode;
    return head;
}

// Delete from beginning
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Delete from end
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) return NULL;

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node *prev = NULL, *curr = head;
    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = NULL;
    free(curr);
    return head;
}

// Delete node after a given node
struct Node* deleteAfter(struct Node* head, int key) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Cannot delete after %d\n", key);
        return head;
    }

    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
    return head;
}

// Display the list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Search for an element
int searchElement(struct Node* head, int key) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key)
            return 1;
        temp = temp->next;
    }
    return 0;
}

// Count number of nodes
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Reverse the list
struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}





