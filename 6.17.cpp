#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Stack operations
void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

// Check precedence
int precedence(char op) {
    switch(op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return -1;
    }
}

// Check if operator is right associative
int isRightAssociative(char op) {
    return op == '^';
}

// Check if character is operator
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Reverse a string
void reverse(char *exp) {
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[len - i - 1];
        exp[len - i - 1] = temp;
    }
}

// Convert infix to postfix
void infixToPostfix(char *infix, char *postfix) {
    int i, j = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == ')') {
            push(c);
        } else if (c == '(') {
            while (!isEmpty() && peek() != ')') {
                postfix[j++] = pop();
            }
            pop(); // remove ')'
        } else if (isOperator(c)) {
            while (!isEmpty() && precedence(peek()) > precedence(c) ||
                   (!isRightAssociative(c) && precedence(peek()) == precedence(c))) {
                postfix[j++] = pop();
            }
            push(c);
        }
    }

    while (!isEmpty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

// Main conversion function
void infixToPrefix(char *infix, char *prefix) {
    reverse(infix);

    // Swap '(' and ')' after reversing
    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    char postfix[MAX];
    infixToPostfix(infix, postfix);
    reverse(postfix);
    strcpy(prefix, postfix);
}

// Driver code
int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);

    return 0;
}
