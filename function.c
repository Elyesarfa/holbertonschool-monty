#include "monty.h"

/**
 * _push - add new element to the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number being executed
 */
void _push(stack_t **stack, unsigned int line_number)
{
    stack_t *newnode = malloc(sizeof(stack_t));
    char *d = "$ \n\t", *op;
    int data;

    if (newnode == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    op = strtok(NULL, d);
    if (op == NULL)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        free(newnode);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; op[i] != '\0'; i++)
    {
        if (!isdigit(op[i]) && !(op[i] == '-' && i == 0))
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            free(newnode);
            exit(EXIT_FAILURE);
        }
    }

    data = atoi(op);
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
