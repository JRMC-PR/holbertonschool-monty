#include "monty.h"
/**
 *getf - gets function o to be used
 *@T_op: pointer to tokenizd input
 *@line_number: holds the line number of the file read
 *Return: function pointer
 */
void (*getf(char *T_op, unsigned int line_number))(m_stack_t **, unsigned int)
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
		if (strcmp(T_op, instructions[i].opcode) == 0)
		{
			instructions[i].f(g_stack, line_number);
			return (0);
		}
		i++; /*move to the next option*/
	} /*end while loop*/
	if (i == 7)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, T_op);
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
void free_token(m_stack_t **toki)
{
	m_stack_t *current;
	/*Free array if pointers*/
	while (toki != NULL)
	{
		current = *toki;
		*toki = (*toki)->next;
		free(current);
	}
} /*end free_token function*/
