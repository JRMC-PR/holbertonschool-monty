#include "monty.h"

/**
 * main - main functuon
 * @argc: arguments
 * @argv: argument array
 * Return: int
 */

int main(int argc, char *argv[])
{
	char *opcode = NULL, *option = NULL;
	unsigned int line_number = 0;
	size_t len = 0;
	ssize_t read;

	g_stack = malloc(sizeof(m_stack_t *));
	if (!g_stack)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	*g_stack = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	} /*end argc if*/
	FILE *file = fopen(argv[1], "r"); /*open file*/

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file HoLbErToN\n");
		exit(EXIT_FAILURE);
	} /*end File if*/
	while ((read = getline(&opcode, &len, file)) != -1)
	{
		line_number++;
		opcode[strlen(opcode) + 1] = '\0'; /* Remove trailing newline */
		opcode = trim(opcode);
		option = strtok(opcode, " \n\t\r$");
		getf(option, line_number);

	} /*end while*/
	free(opcode);
	free_token(g_stack);
	fclose(file);
	exit(EXIT_SUCCESS);
} /*end function*/

/**
 * add - add top 2 elements of stack
 * @stack: array of data
 * @line_number: line
 */

void add(m_stack_t **stack, unsigned int line_number)
{
	/*check if the stck is empty*/
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	} /*end stack if*/
	(*stack)->next->n += (*stack)->n;
} /*end add fucntion*/

/**
 * nop - doesnt do anything
 * @stack: array of data
 * @line_number: line
 */

void nop(m_stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
} /*end nop function*/

