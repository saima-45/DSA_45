/*5. Write a C and C++ program for implementation of Singly Linked List consisting of 
following operations: (in C)
• Inserting a new node in a Linked List at the beginning
• Inserting a new node in a Linked List at the end.
• Deleting a node from a Linked List from beginning
• Deleting a node from a Linked List from end
• Display the entire linked list (Traversal)
• Now test the working of the program by calling these functions as follows:
• Inserting a new node in a Linked List at the beginning: 45
• Inserting a new node in a Linked List at the beginning:55
• Inserting a new node in a Linked List at the beginning:65
• Inserting a new node in a Linked List at the end: 67
• Inserting a new node in a Linked List at the end: 77
• Inserting a new node in a Linked List at the end: 87
• Display the entire linked list (Traversal)
• Deleting a node from a Linked List from beginning
• Deleting a node from a Linked List from beginning
• Display the entire linked list (Traversal)
• Deleting a node from a Linked List from end
• Deleting a node from a Linked List from end
• Display the entire linked list (Traversal)
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Insert at beginning
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Insert at end
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Delete from beginning
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) return;

    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete from end
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* temp = *head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

// Display list
void display(struct Node* head) {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Insert at beginning
    insertAtBeginning(&head, 45);
    insertAtBeginning(&head, 55);
    insertAtBeginning(&head, 65);

    // Insert at end
    insertAtEnd(&head, 67);
    insertAtEnd(&head, 77);
    insertAtEnd(&head, 87);

    // Display
    display(head);

    // Delete from beginning twice
    deleteFromBeginning(&head);
    deleteFromBeginning(&head);

    // Display
    display(head);

    // Delete from end twice
    deleteFromEnd(&head);
    deleteFromEnd(&head);

    // Final display
    display(head);

    return 0;
}





