#include "monty.h"
/**
 *getf - gets function o to be used
 *@T_op: pointer to tokenizd input
 *@line_number: holds the line number of the file read
 *Return: function pointer
 */
void *getf(m_stack_t **g_stack, char *option, unsigned int line_number)
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
	if (option == NULL)
		instructions[6].f(g_stack, line_number);
	while (instructions[i].opcode)
	{
		/*verify if match*/
		if (strcmp(option, instructions[i].opcode) == 0)
		{
			instructions[i].f(g_stack, line_number);
			return (0);
		}
		i++; /*move to the next option*/
	} /*end while loop*/
	if (i == 7)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, option);
		exit(EXIT_FAILURE);
	} /*end positon if*/
	return (0);
} /*end get_func*/

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
		if ((*toki)->next != NULL)
		{
			*toki = (*toki)->next;
			free(current);
		}
		else
			return;
	}
} /*end free_token function*/

/**
 *isInteger - checks if its integer or not
 *@token: pointer to the string
 *Return: confirmation its a integer
 */
bool isInteger(const char *token)
{
	/*Declarations*/
	char *end;
	/*if empty return false*/
	if (*token == '\0')
		return (false);
	strtol(token, &end, 10);
	return (*end == '\0');
} /*end isInteger*/
