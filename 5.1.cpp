#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* last;

public:
    CircularLinkedList() {
        last = NULL;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        if (last == NULL) {
            newNode->next = newNode;
            last = newNode;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }

    void display() {
        if (last == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = last->next;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != last->next);
        cout << "(head)\n";
    }

    void deleteFromBeginning() {
        if (last == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = last->next;
        if (last == temp) {
            last = NULL;
        } else {
            last->next = temp->next;
        }
        delete temp;
    }
};

int main() {
    CircularLinkedList cll;
    int choice, value;
    while (true) {
        cout << "\n1. Insert at End\n2. Display\n3. Delete from Beginning\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                cll.insertAtEnd(value);
                break;
            case 2:
                cll.display();
                break;
            case 3:
                cll.deleteFromBeginning();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice.\n";
        }
    }
    return 0;
}
