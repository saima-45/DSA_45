#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    void push(int value) {
        if (top >= capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    bool isEmpty() const {
        return top == -1;
    }

    ~Stack() {
        delete[] arr;
    }
};

void reverseArray(int arr[], int size) {
    Stack stack(size);


    for (int i = 0; i < size; i++) {
        stack.push(arr[i]);
    }


    for (int i = 0; i < size; i++) {
        arr[i] = stack.pop();
    }
}

void displayArray(const int arr
