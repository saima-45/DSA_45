#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// Check precedence of operators
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

// Check if operator is right associative
bool isRightAssociative(char op) {
    return op == '^';
}

// Check if character is operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Convert infix to postfix
string infixToPostfix(const string& infix) {
    stack<char> s;
    string postfix;

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty()) s.pop(); // Remove '('
        } else if (isOperator(c)) {
            while (!s.empty() &&
                  (precedence(s.top()) > precedence(c) ||
                  (precedence(s.top()) == precedence(c) && !isRightAssociative(c))) &&
                  s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

// Convert infix to prefix
string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());

    // Swap '(' and ')'
    for (char& c : infix) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }

    string postfix = infixToPostfix(infix);
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

// Driver code
int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string prefix = infixToPrefix(infix);
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}
