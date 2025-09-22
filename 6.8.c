#include <stdio.h>
#define MAX 100

int arr[MAX];
int top1 = -1;
int top2 = MAX;

// Push to Stack 1
void push1(int value) {
    if (top1 + 1 == top2) {
        printf("Stack Overflow (Stack 1)\n");
        return;
    }
    arr[++top1] = value;
    printf("%d pushed to Stack 1\n", value);
}

// Push to Stack 2
void push2(int value) {
    if (top2 - 1 == top1) {
        printf("Stack Overflow (Stack 2)\n");
        return;
    }
    arr[--top2] = value;
    printf("%d pushed to Stack 2\n", value);
}


void pop1() {
    if (top1 == -1) {
        printf("Stack Underflow (Stack 1)\n");
        return;
    }
    printf("%d popped from Stack 1\n", arr[top1--]);
}


void pop2() {
    if (top2 == MAX) {
        printf("Stack Underflow (Stack 2)\n");
        return;
    }
    printf("%d popped from Stack 2\n", arr[top2++]);
}


void display1() {
    if (top1 == -1) {
        printf("Stack 1 is empty\n");
        return;
    }
    printf("Stack 1 elements:\n");
    for (int i = 0; i <= top1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void display2() {
    if (top2 == MAX) {
        printf("Stack 2 is empty\n");
        return;
    }
    printf("Stack 2 elements:\n");
    for (int i = MAX - 1; i >= top2; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    push1(10);
    push1(20);
    push2(100);
    push2(200);
    display1();
    display2();
    pop1();
    pop2();
    display1();
    display2();
    return 0;
}
