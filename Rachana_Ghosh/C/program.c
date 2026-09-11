#include <stdio.h>
#define SIZE 5

int stack[SIZE], top = -1;

void push(int x) {
    if (top == SIZE - 1)
        printf("Stack is full\n");
    else
        stack[++top] = x;
}

void pop() {
    if (top == -1)
        printf("Stack is empty\n");
    else
        printf("Deleted: %d\n", stack[top--]);
}

int main() {
    push(10);
    push(20);
    push(30);

    pop();
    pop();

    return 0;
}