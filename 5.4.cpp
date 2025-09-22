#include <iostream>
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

    Polynomial add(Polynomial& other) {
        Polynomial result;
        Node* p1 = head;
        Node* p2 = other.head;

        while (p1 && p2) {
            if (p1->power > p2->power) {
                result.insertTerm(p1->coeff, p1->power);
                p1 = p1->next;
            } else if (p1->power < p2->power) {
                result.insertTerm(p2->coeff, p2->power);
                p2 = p2->next;
            } else {
                result.insertTerm(p1->coeff + p2->coeff, p1->power);
                p1 = p1->next;
                p2 = p2->next;
            }
        }

        while (p1) {
            result.insertTerm(p1->coeff, p1->power);
            p1 = p1->next;
        }

        while (p2) {
            result.insertTerm(p2->coeff, p2->power);
            p2 = p2->next;
        }

        return result;
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
};
