#include "monty.h"

/**
 * split - Split and process the opcode
 * @stack: Pointer to the top of the stack
 * @line_number: Line number being processed
 * @opcode: Opcode to process
 */
void split(stack_t **stack, unsigned int line_number, char *opcode)
{
    int i = 0;
    instruction_t ops[] = {
        {"push", _push},
        {"pall", _pall},
        {NULL, NULL}
    };

    while (ops[i].opcode != NULL)
    {
        if (strcmp(opcode, ops[i].opcode) == 0)
        {
            ops[i].f(stack, line_number);
            return;
        }
        i++;
    }

    fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}
