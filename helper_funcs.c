#include "monty.h"
/**
 * Tok - Tokenize a command string and execute it
 * @opcode: input
 * Return: pointer to tokens
 */
void **Tok(char *opcode, char **tokens)
{
	/*declaration*/
	char *tok = NULL;
	 int count = 0;
	/*Break it*/
	tok = strtok(opcode, " ");
	if (tok == NULL)
	{ /*verify data*/
		fprintf(stderr, "Error: nothing to Tok");
		exit(EXIT_FAILURE);
	} /*end tok if*/
	while (tok != NULL)
	{
		tokens[count] = malloc((sizeof(tok) - 1) * sizeof(char *));
		if (tokens[count] == NULL)
		{
			fprintf(stderr, "Error: Tokens malloc fail");
			free_token(tokens);
			exit(EXIT_FAILURE);
		} /*end tokens if*/
		tokens[count] = tok;
		count++;
		tok = strtok(NULL, "$");
	} /*end tok while*/
	return(0);
}

/**
 *getf - gets function o to be used
 *@T_op: pointer to tokenizd input
 *@line_number: holds the line number of the file read
 *Return: function pointer
 */
void (*getf(char **T_op, unsigned int line_number))(m_stack_t **, unsigned int)
{
	/*Daclarations*/
	int i = 0;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL},
	};
	while (instructions[i].opcode)
	{
		/*verify if match*/
		if (strcmp(T_op[0], instructions[i].opcode) == 0)
			return (instructions[i].f);
		i++; /*move to the next option*/
	} /*end while loop*/
	if (i == 7)
	{
		fprintf(stderr, "L<%d>: unknown instruction <%s>\n", line_number, T_op[0]);
		exit(EXIT_FAILURE);
	} /*end positon if*/
	return (0);
} /*end get_func*/

/**
 * trim - Remove leading and trailing whitespace from a string
 * @opcode: The string to trim
 * Return: A pointer to the trimmed string
 */
char *trim(char *opcode)
{
	char *end = opcode + strlen(opcode); /*Pointer to the end of the string */
	/* Remove leading whitespace */
	while (isspace((unsigned char)(*opcode)))
		opcode++;
	/* Remove trailing whitespace */
	while (end > opcode && isspace((unsigned char)*end))
		end--;
	/* Null-terminate the trimmed string */
	*(end + 1) = '\0';
	return (opcode); /* Return the trimmed string */
} /*end trim function*/

/**
 * free_token - Frees memory allocated for token array and token strings
 * @toki: The token array to be freed
 */
void free_token(char **toki)
{
	int i;/*counter variable*/
	/*Free array if pointers*/
	for (i = 0; toki[i] != NULL; i++)
	{
		free(toki[i]);
	}
	free(toki);
} /*end free_token function*/
