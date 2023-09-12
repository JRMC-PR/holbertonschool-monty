#include "monty.h"

m_stack_t **g_stack;

/**
 * main - main functuon
 * @argc: arguments
 * @argv: argument array
 * return: int
 */

int main(int argc, char *argv[])
{
	char *opcode = NULL, *endp = NULL;
	unsigned int line_number = 0;
	size_t len = 0;
	ssize_t read;
	void (*valid_func)(m_stack_t **, unsigned int);
	char **tokens = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	} /*end argc if*/
	FILE *file = fopen(argv[1], "r"); /*open file*/

	if (!file)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	} /*end File if*/
	while ((read = getline(&opcode, &len, file)) != -1)
	{
		line_number++;
		opcode[strlen(opcode) + 1] = '\0'; /* Remove trailing newline */
		/*printf("Before trim\n");*/ /*test*/
		opcode = trim(opcode);
		tokens = malloc((sizeof(opcode) - 1) * sizeof(char *));
		/*printf("before Tok: %s \n", opcode);*/ /*test*/
		Tok(opcode, tokens);
		printf("%s---%s", tokens[0], tokens[1]); /*test*/
		valid_func = getf(tokens, line_number);
		/*add data tho the stack node tobe passed to the new fucntion*/
		(*g_stack)->n = strtol(tokens[1], &endp, 10); /*test invalid size 8 error poop up */
		valid_func(g_stack, line_number);
	} /*end while*/
	free(opcode);
	free_token(tokens);
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
		fprintf(stderr, "L<%d>: can't pint, stack empty", line_number);
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

