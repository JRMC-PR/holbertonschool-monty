#include "monty.h"

m_stack_t *g_stack = NULL;

/**
 * main - main functuon
 * @argc: arguments
 * @argv: argument array
 * return: int
 */

int main(int argc, char *argv[])
{
	char *opcode = NULL, **T_op = NULL;
	unsigned int line_number = 0;
	size_t len = 0;
	ssize_t read;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	} /*end argc if*/
	FILE *file = fopen(argv[1], "r");
	if (!file)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	} /*end File if*/
	while ((read = getline(&opcode, &len, file)) != -1)
	{
		line_number++;
		opcode[strlen(opcode) + 1] = '\0'; /* Remove trailing newline */
		printf("Before trim\n");
		opcode = trim(opcode);
		printf("before Tok");
		T_op = Tok(opcode);
		printf("%s", T_op[0]);
	} /*end while*/
	free(opcode);
	fclose(file);
	exit(EXIT_SUCCESS);
} /*end function*/
