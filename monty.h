#ifndef MONTY_H
#define MONTY_H

#define STACK_SIZE 1000

typedef struct Stack {
    int items[STACK_SIZE];
    int top;
} Stack;

void initStack();
int isFull();
int isEmpty();
void push(int value);
void pop();
void swap();
void add();
void nop();
void pall();

#endif