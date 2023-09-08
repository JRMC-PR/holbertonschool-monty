#include "monty.h"
/**
 *push - adds to the stack
 *@head::a pointer to the head of the stack
 *@n:data sto be stored
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
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	} /*end token if*/
	/*store data*/
	value = atoi(token);
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
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

void pall(m_stack_t **stack, unsigned int line_number) // print all
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
 * pint - prints current int
 * @stack: array of data
 * @line_number: line
 */

void pint(m_stack_t **stack, unsigned int line_number) //print current
{
/*check if the stck is empty*/
	if (*stack == NULL)
	{
		perror("L<%f>: can't pint, stack empty", line_number);
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
	m_stack_t *tmp;

	if (*stack == NULL)
	{
		perror("L<%f>: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	} /*end stack if*/	
	*tmp = *stack;
	*stack = (*stack)->next;
	/*check if stil in stack*/
	if (*stack)
		(*stack)->prev = NULL;

	free(tmp);}

/**
 * swap - swap top 2 elements of stack
 * @stack: array of data
 * @line_number: line
 */

void swap(m_stack_t **stack, unsigned int line_number) //swap top 2 elements of stack
{
	int tmp;
/*check if the stck is empty*/
	if (*stack == NULL)
	{
		perror("L<%f>: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	} /*end stack if*/	

	tmp = (*stack)->n;
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
		perror("L<%f>: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	} /*end stack if*/
	(*stack)->next->n += (*stack)->n;
	//send to pop}

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

