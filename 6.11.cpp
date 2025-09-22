#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverseString(const string& input) {
    stack<char> s;


    for (char ch : input) {
        s.push(ch);
    }


    string reversed;
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }

    return reversed;
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    string reversed = reverseString(str);
    cout << "Reversed string: " << reversed << endl;

    return 0;
}
