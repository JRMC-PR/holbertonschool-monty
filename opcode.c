#include "monty.h"
/**
 *push - adds to the stack
 *@stack:a pointer to the head of the stack
 *@line_number:data to be stored
 */
void push(m_stack_t **stack, unsigned int line_number)
{
	/*Declarations*/
	char *token, *end;
	m_stack_t *new_node = malloc(sizeof(m_stack_t));
	/*Tokenize*/
	printf("inside push\n");
	token = strtok(NULL, " $");
	printf("integer: %s", token);
	if (!token)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	} /*end token if*/
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	} /*end node if*/
	/*fill the new node*/
	new_node->n = strtol(token, &end, 10);
	new_node->prev = NULL;
	new_node->next = *stack;
	if (stack)
	{
		(*stack)->prev = new_node;
	} /*end stack if*/
	*stack = new_node;
} /*end push function*/

/**
 *pall - print all opcode
 *@stack: array of data to print
 *@line_number: lines in input;
 */
void pall(m_stack_t **stack, unsigned int line_number)
{
	/*Declarations*/
	m_stack_t *tmp = *stack;
	/*void unused parameter*/
	(void)line_number;
	/*print everything in the stack*/
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	} /*end while*/
} /*end pall function*/

/**
 *pint - prints the value @ the top of the stack
 *@stack: pointer to the stack
 *@line_number: unused param in this function
 */
void pint(m_stack_t **stack, unsigned int line_number)
{
	/*check if the stck is empty*/
	if (*stack == NULL)
	{
		fprintf(stderr, "L<%d>: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	} /*end stack if*/
	printf("%d", (*stack)->n);
} /*end pint function*/

/**
 * pop - remove item from stack
 * @stack: array of data
 * @line_number: line
 */
void pop(m_stack_t **stack, unsigned int line_number)
{
	m_stack_t *tmp;
	/*check if the stck is empty*/
	if (*stack == NULL)
	{
		fprintf(stderr, "L<%d>: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	} /*end stack if*/
	 tmp = *stack;
	*stack = (*stack)->next;
	/*check if stil in stack*/
	if (*stack)
		(*stack)->prev = NULL;
	free(tmp);
} /*end pop function*/

/**
 * swap - swap top 2 elements of stack
 * @stack: array of data
 * @line_number: line
 */

void swap(m_stack_t **stack, unsigned int line_number)
{
	int tmp;
	/*check if the stck is empty*/
	if (*stack == NULL)
	{
		fprintf(stderr, "L<%d>: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	} /*end stack if*/
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
} /*end swap function*/


