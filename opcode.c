#include "monty.h"
<<<<<<< HEAD
/**
 *push - adds to the stack
 *@head::a pointer to the head of the stack
 *@n:data sto be stored
 */
void push(stack_t **stack, unsigned int line_number)
{
	/*Declarations*/
	char token;
	int value;
	stack_t new_node = malloc(sizeof(stack_t));

	token = strtok(NULL, " "); /*tokenize*/
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
	new_node->next = stack;
	if (stack)
	{
		(*stack)->prev = new_node;
	} /*end stack if*/
	*stack = new_node;
} /*end push*/


=======

/**
 *pall - print all opcode
 *@stack: array of data to print
 *@line_number: lines in input;
 */

void pall(s_t **stack, unsigned int line_number)
{
	s_t *tmp = *stack;

	(void)line_number;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
>>>>>>> e724d6433ffa936c5abc5bbc823d2d6f5cb75697
