#include <iostream>
using namespace std;

class Stack {
private:
    static const int MAX = 100;
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow\n";
        } else {
            arr[++top] = value;
            cout << value << " pushed to stack\n";
        }
    }

    void pop() {
        if (top < 0) {
            cout << "Stack Underflow\n";
        } else {
            cout << arr[top--] << " popped from stack\n";
        }
    }

    void peek() const {
        if (top < 0) {
            cout << "Stack is empty\n";
        } else {
            cout << "Top element is " << arr[top] << endl;
        }
    }

    void display() const {
        if (top < 0) {
            cout << "Stack is empty\n";
        } else {
            cout << "Stack elements:\n";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << endl;
            }
        }
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.peek();
    s.pop();
    s.display();
    return 0;
}
