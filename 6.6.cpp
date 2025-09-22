#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Stack class
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    // Push operation
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << value << " pushed to stack\n";
    }

    // Pop operation
    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        cout << top->data << " popped from stack\n";
        top = top->next;
        delete temp;
    }

    // Display operation
    void display() const {
        if (top == nullptr) {
            cout << "Stack is empty\n";
            return;
        }
        Node* temp = top;
        cout << "Stack elements:\n";
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    // Destructor to clean up memory
    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

// Main function to test the stack
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.pop();
    s.display();
    return 0;
}
