#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

class DoublyCircularLinkedList {
private:
    Node* head;

public:
    DoublyCircularLinkedList() {
        head = NULL;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        if (head == NULL) {
            newNode->next = newNode->prev = newNode;
            head = newNode;
        } else {
            Node* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    void insertAtBeginning(int value) {
        insertAtEnd(value);
        head = head->prev;
    }

    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        if (head->next == head) {
            delete head;
            head = NULL;
        } else {
            Node* temp = head;
            Node* tail = head->prev;
            head = head->next;
            head->prev = tail;
            tail->next = head;
            delete temp;
        }
    }

    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        if (head->next == head) {
            delete head;
            head = NULL;
        } else {
            Node* tail = head->prev;
            Node* newTail = tail->prev;
            newTail->next = head;
            head->prev = newTail;
            delete tail;
        }
    }

    void displayForward() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " <-> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)\n";
    }

    void displayBackward() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head->prev;
        do {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        } while (temp != head->prev);
        cout << "(tail)\n";
    }
};

int main() {
    DoublyCircularLinkedList dcll;
    int choice, value;
    while (true) {
        cout << "\n1. Insert at Beginning\n2. Insert at End\n3. Delete from Beginning\n4. Delete from End\n5. Display Forward\n6. Display Backward\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                dcll.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                dcll.insertAtEnd(value);
                break;
            case 3:
                dcll.deleteFromBeginning();
                break;
            case 4:
                dcll.deleteFromEnd();
                break;
            case 5:
                dcll.displayForward();
                break;
            case 6:
                dcll.displayBackward();
                break;
            case 7:
                exit(0);
            default:
                cout << "Invalid choice.\n";
        }
    }
    return 0;
}
