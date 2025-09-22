#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Stack operations
void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

// Evaluate postfix expression
int evaluatePostfix(char *exp) {
    int i = 0;
    while (exp[i] != '\0') {
        char c = exp[i];

        if (isdigit(c)) {
            push(c - '0'); // Convert char to int
        } else {
            int val2 = pop();
            int val1 = pop();
            switch (c) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
                default:
                    printf("Invalid operator: %c\n", c);
                    exit(1);
            }
        }
        i++;
    }
    return pop();
}

// Driver code
int main() {
    char postfix[MAX];

    printf("Enter postfix expression (e.g., 23*54*+): ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
