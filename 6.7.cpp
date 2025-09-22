#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;

    // Push elements
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Elements pushed: 10, 20, 30\n";

    // Access top element
    if (!s.empty()) {
        cout << "Top element: " << s.top() << endl;
    }

    // Pop an element
    s.pop();
    cout << "One element popped\n";

    // Access top again
    if (!s.empty()) {
        cout << "New top element: " << s.top() << endl;
    }

    // Display size
    cout << "Current stack size: " << s.size() << endl;

    // Check if stack is empty
    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl;

    return 0;
}
