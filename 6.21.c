#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

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

// Evaluate prefix expression
int evaluatePrefix(char *exp) {
    int len = strlen(exp);

    for (int i = len - 1; i >= 0; i--) {
        char c = exp[i];

        if (isdigit(c)) {
            push(c - '0'); // Convert char to int
        } else {
            int val1 = pop();
            int val2 = pop();

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
    }

    return pop();
}

// Driver code
int main() {
    char prefix[MAX];

    printf("Enter prefix expression (e.g., +*23*54): ");
    scanf("%s", prefix);

    int result = evaluatePrefix(prefix);
    printf("Result: %d\n", result);

    return 0;
}
