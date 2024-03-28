#include "monty.h"

/**
 * _pint - Prints the value at the top of the stack.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number being executed
 */
void _pint(stack_t **stack, unsigned int line_number)
{
    stack_t *node = *stack;
    if (node != NULL)
    {
        printf("%d\n", node->n);
    }
    else
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        /* Do not exit here, just return */
        return;
    }
}
