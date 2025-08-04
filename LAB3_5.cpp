/* 5. Write a C and C++ program for implementation of Singly Linked List consisting of 
following operations:(In C++)
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
• Display the entire linked list (Traversal) */

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, head};
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr};
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    void deleteFromBeginning() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd() {
        if (head == nullptr) return;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void display() {
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;

    // Insert at beginning
    list.insertAtBeginning(45);
    list.insertAtBeginning(55);
    list.insertAtBeginning(65);

    // Insert at end
    list.insertAtEnd(67);
    list.insertAtEnd(77);
    list.insertAtEnd(87);

    // Display
    list.display();

    // Delete from beginning twice
    list.deleteFromBeginning();
    list.deleteFromBeginning();

    // Display
    list.display();

    // Delete from end twice
    list.deleteFromEnd();
    list.deleteFromEnd();

    // Final display
    list.display();

    return 0;
}

