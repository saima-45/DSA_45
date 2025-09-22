#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Evaluate postfix expression
int evaluatePostfix(const string& expr) {
    stack<int> s;

    for (char c : expr) {
        if (isdigit(c)) {
            s.push(c - '0'); // Convert char to int
        } else {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();

            switch (c) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                default:
                    cout << "Invalid operator: " << c << endl;
                    return -1;
            }
        }
    }

    return s.top();
}

// Driver code
int main() {
    string postfix;
    cout << "Enter postfix expression (e.g., 23*54*+): ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}
