#include "monty.h"
/**
 * Tok - Tokenize a command string and execute it
 * @tokI: The command string to tokenize
 * @env: The environment variables
 */
char **Tok(char *opcode)
{
	/*declaration*/
	char *tok = NULL, **tokens = NULL;
	int count = 0;
	/*Break it*/
	tok = strtok(opcode, " ");
	if (tok == NULL){ /*verify data*/
		fprintf(stderr,"Error: nothing to Tok");
		exit(EXIT_FAILURE);
	} /*end tok if*/
	while (tok != NULL){
		tokens[count] = malloc(strlen(tok));
		if (tokens[count] == NULL){
			fprintf(stderr, "Error: Tokens malloc fail");
			exit(EXIT_FAILURE);
		} /*end tokens if*/
		tokens[count] = strdup(tok);
		count++;
		tok = strtok(NULL, " ");
	} /*end tok while*/
	return (tokens);
}

/**
 *get_func - gets function o to be used
 *@T-op: pointer to tokenizd input
 *@line_number: holds the line number of the file read
 *Return: function pointer
 */
char *get_func(char **T_op, unsigned int line_number)(m_stack_t, unsigned int)
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
	while (instructions[i].opcode){
		/*verify if match*/
		if (T_op[0] == instructions[i].opcode)
			return (instructions[i].f);
		i++; /*move to the next option*/
	} /*end while loop*/
	if (i == 7){
		fprintf(stderr, "L<%d>: unknown instruction <%s>\n", line_number, T_op[0]);
		exit(EXIT_FAILURE);
	} /*end positon if*/
	return (NULL);
} /*end get_func*/

/**
 * trim - Remove leading and trailing whitespace from a string
 * @str: The string to trim
 * Return: A pointer to the trimmed string
 */
char *trim(char *opcode)
{
	char *end = opcode + strlen(opcode) - 1; /*Pointer to the end of the string */

	/* Remove leading whitespace */
	while (isspace((unsigned char)(*opcode)))
		opcode++;

	/* Remove trailing whitespace */
	while (end > opcode && isspace((unsigned char)*end))
		end--;

	/* Null-terminate the trimmed string */
	*(end + 1) = '\0';

	return (opcode); /* Return the trimmed string */
}
