#include "monty.h"

/**
 * _add - Adds the top two elements of the stack.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number being executed
 */
void _add(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;
    tmp = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    free(tmp);
}
