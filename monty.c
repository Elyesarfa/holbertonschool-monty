#include "monty.h"

/**
 * main - Entry point for the Monty interpreter
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	char *delimiters = " \n\t";
	char *opcode;
	stack_t *stack = NULL;
	int line_number = 0;
	FILE *file;
	char *buffer = NULL;
	size_t len = 0;
	ssize_t read;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&buffer, &len, file)) != -1)
	{
		line_number++;
		opcode = strtok(buffer, delimiters);
		if (opcode != NULL)
			split(&stack, line_number, opcode);
	}

	free(buffer);
	free_stack(stack);
	fclose(file);
	return (0);
}
