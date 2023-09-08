#include "monty.h"

m_stack_t *g_stack = NULL;

/**
 *main - execute monty interpreter
 *@arg: argument vector size
 *@argv: argument vector for input
 *Retunr: 0 or 1
 */

int main(int argc, char *argv[])
{
	/*Declarations*/
	char *opcode = NULL, T_op = NULL;
	char (*valid_func)(m_stack_t)(unsigned int);

	unsigned int line_number = 0;
	size_t len = 0;
	ssize_t read;
	/*verify input*/
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	/*open file*/
	FILE *file = fopen(argv[1], "r");
	if (!file)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	} /*end file if*/
	while ((read = getline(&opcode, &len, file)) != -1)
	{
		line_number++;
		opcode[strlen(opcode) - 1] = '\0'; /* Remove trailing newline */
		opcode = trim(opcode);
		T_op = Tok(opcode);
		valid_func = get_func(opcode)(g_stack, line_number);
		valid_func(m_stack_t, line_number);
	} /*end read while*/
	return (0);
} /*end main function*/





