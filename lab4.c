#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation error\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    if (!newNode) return head;
    newNode->next = head;
    head = newNode;
    return head;
}

// Insert at end
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    if (!newNode) return head;

    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Insert at specific position (0-based index)
struct Node* insertAtPosition(struct Node* head, int value, int pos) {
    if (pos == 0) {
        return insertAtBeginning(head, value);
    }
    struct Node* newNode = createNode(value);
    if (!newNode) return head;

    struct Node* temp = head;
    int i; 
    for (i = 0; i < pos - 1; i++) {
        if (temp == NULL) {
            printf("Invalid position\n");
            return head;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Delete from beginning
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) return NULL;

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

    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

// Delete a specific node by value (delete first occurrence)
struct Node* deleteNode(struct Node* head, int value) {
    if (head == NULL) return NULL;

    if (head->data == value) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Element not found\n");
        return head;
    }

    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
    return head;
}

// Search an element
int search(struct Node* head, int key) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return 1; // found
        }
        temp = temp->next;
    }
    return 0; // not found
}

// Display the list
void display(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

