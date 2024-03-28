#include "monty.h"

/**
 * _push - Pushes an element to the stack.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number being executed
 */
void _push(stack_t **stack, unsigned int line_number)
{
    stack_t *newnode;
    int data;
    char *op;

    op = strtok(NULL, "$ \n\t");
    if (op == NULL || !isdigit(*op))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    data = atoi(op);
    newnode = malloc(sizeof(stack_t));
    if (newnode == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    newnode->n = data;
    newnode->next = *stack;
    newnode->prev = NULL;

    if (*stack != NULL)
        (*stack)->prev = newnode;

    *stack = newnode;
}

/**
 * _pall - Prints all the values on the stack.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number being executed
 */
void _pall(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = *stack;
    (void)line_number;

    while (tmp != NULL)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
}
