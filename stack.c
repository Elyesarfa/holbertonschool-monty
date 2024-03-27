#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack stack;

void initStack() {
    stack.top = -1;
}

int isFull() {
    return stack.top == STACK_SIZE - 1;
}

int isEmpty() {
    return stack.top == -1;
}

void push(int value) {
    if (isFull()) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack.items[++stack.top] = value;
}

void pop() {
    if (isEmpty()) {
        fprintf(stderr, "Error: can't pop an empty stack\n");
        exit(EXIT_FAILURE);
    }
    stack.top--;
}

void swap() {
    if (stack.top < 1) {
        fprintf(stderr, "Error: can't swap, stack too short\n");
        exit(EXIT_FAILURE);
    }
    int temp = stack.items[stack.top];
    stack.items[stack.top] = stack.items[stack.top - 1];
    stack.items[stack.top - 1] = temp;
}

void add() {
    if (stack.top < 1) {
        fprintf(stderr, "Error: can't add, stack too short\n");
        exit(EXIT_FAILURE);
    }
    stack.items[stack.top - 1] += stack.items[stack.top];
    stack.top--;
}

void nop() {

}

void pall() {
    int i;
    for (i = stack.top; i >= 0; i--) {
        printf("%d\n", stack.items[i]);
    }
}
