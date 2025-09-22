#include <iostream>
#include <stack>
#include <sstream>
#include <cmath>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to perform arithmetic operations
int applyOp(char op, int a, int b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
        default: return 0;
    }
}

// Function to evaluate prefix expression
int evaluatePrefix(const string& expr) {
    stack<int> s;
    for (int i = expr.length() - 1; i >= 0; i--) {
        char c = expr[i];

        if (isspace(c)) continue;

        if (isdigit(c)) {
            s.push(c - '0');  // Convert char to int
        } else if (isOperator(c)) {
            int op1 = s.top(); s.pop();
            int op2 = s.top(); s.pop();
            int result = applyOp(c, op1, op2);
            s.push(result);
        }
    }
    return s.top();
}

int main() {
    string expr = "-+7*45+20";  // Example prefix expression
    cout << "Result: " << evaluatePrefix(expr) << endl;
    return 0;
}
