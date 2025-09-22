#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    char data;
    struct Node* next;
} Node;


void push(Node** top, char value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}


char pop(Node** top) {
    if (*top == NULL) return '\0'; // Underflow
    Node* temp = *top;
    char popped = temp->data;
    *top = temp->next;
    free(temp);
    return popped;
}


char peek(Node* top) {
    if (top == NULL) return '\0';
    return top->data;
}


int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}


int isBalanced(const char* expr) {
