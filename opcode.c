#include "monty.h"
/**
 *push - adds to the stack
 *@head::a pointer to the head of the stack
 *@line_number:data to be stored
 */
void push(m_stack_t **stack, unsigned int line_number)
{
	/*Declarations*/
	char *token;
	int value;
	m_stack_t *new_node = malloc(sizeof(m_stack_t));
	/*Tokenize*/
	token = strtok(NULL, " ");
	if (!token)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	} /*end token if*/
	/*store data*/
	value = atoi(token);
	if (!new_node)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	} /*end node if*/
	/*fill the new node*/
	new_node->n = value;
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
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	} /*end stack if*/
	printf("%d",(*stack)->n);
} /*end pint function*/

/**
 * pop - remove item from stack
 * @stack: array of data
 * @line_number: line
 */
void pop(m_stack_t **stack, unsigned int line_number) //remove from stack
{
	/*check if the stck is empty*/
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	} /*end stack if*/	
	m_stack_t *tmp = *stack;
	*stack = (*stack)->next;
	/*check if stil in stack*/
	if (*stack)
		(*stack)->prev = NULL;

	free(tmp);

}

/**
 * swap - swap top 2 elements of stack
 * @stack: array of data
 * @line_number: line
 */

void swap(m_stack_t **stack, unsigned int line_number) //swap top 2 elements of stack
{
	/*check if the stck is empty*/
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	} /*end stack if*/	

	int tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;

}

/**
 * add - add top 2 elements of stack
 * @stack: array of data
 * @line_number: line
 */

void add(m_stack_t **stack, unsigned int line_number) // add top 2 elements of stack
{
	/*check if the stck is empty*/
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	} /*end stack if*/
	(*stack)->next->n += (*stack)->n;
	//send to pop
}

/**
 * nop - doesnt do anything
 * @stack: array of data
 * @line_number: line
 */

void nop(m_stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
 //void everything given to func
}
