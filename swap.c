#include "monty.h"

/**
 * _swap - Swaps the top two elements of the stack.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number being executed
 */
void _swap(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    tmp = (*stack)->next;
    (*stack)->next = tmp->next;
    if (tmp->next != NULL)
        tmp->next->prev = *stack;
    tmp->prev = NULL;
    tmp->next = *stack;
    (*stack)->prev = tmp;
    *stack = tmp;
}
