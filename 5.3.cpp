#include <iostream>
#include <cmath>
using namespace std;

class Node {
public:
    int coeff;
    int power;
    Node* next;
    Node(int c, int p) : coeff(c), power(p), next(NULL) {}
};

class Polynomial {
private:
    Node* head;

public:
    Polynomial() : head(NULL) {}

    void insertTerm(int coeff, int power) {
        Node* newNode = new Node(coeff, power);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->coeff << "x^" << temp->power;
            temp = temp->next;
            if (temp)
                cout << " + ";
        }
        cout << endl;
    }

    double evaluate(int x) {
        double result = 0;
        Node* temp = head;
        while (temp) {
            result += temp->coeff * pow(x, temp->power);
            temp = temp->next;
        }
        return result;
    }
};

int main() {
    Polynomial poly;
    int n, coeff, power, x;

    cout << "Enter number of terms in the polynomial: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter coefficient and power for term " << i + 1 << ": ";
        cin >> coeff >> power;
        poly.insertTerm(coeff, power);
    }

    cout << "Polynomial: ";
    poly.display();

    cout << "Enter value of x to evaluate: ";
    cin >> x;

    cout << "Value of polynomial at x = " << x << " is " << poly.evaluate(x) << endl;

    return 0;
}
