#include <iostream>
#include <stack>
#include <string>
using namespace std;


bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isBalanced(const string& expr) {
    stack<char> s;

    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty() || !isMatchingPair(s.top(), ch)) {
                return false;
            }
            s.pop();
        }
    }

    return s.empty();
    return s.empty();
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    cin >> expression;

    if (isBalanced(expression))
        cout << "Balanced parentheses ✅" << endl;
    else
        cout << "Unbalanced parentheses ❌" << endl;

    return 0;
}
