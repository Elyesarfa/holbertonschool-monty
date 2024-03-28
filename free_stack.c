#include "monty.h"
/**
* free_stack - Frees a stack.
* @stack: Pointer to the top of the stack
*/
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
