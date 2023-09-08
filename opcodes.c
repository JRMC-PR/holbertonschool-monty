#include "monty.h"

void push
{

}

void pall // print all
{
	stack_t *current = *stack;
	(void)line_number;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

void pint //print current
{
	//if error 
	//else
	printf("%d\n", (*stack)->n);
}

void pop //remove from stack
{
	//if error
	stack_t *tmp = *stack;
	*stack = (*stack)->next;

	if (*stack)
		(*stack)->prev = NULL;

	free(tmp);

}

void swap //swap top 2 elements of stack
{
	//if for errors

	int tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;

}

void add // add top 2 elements of stack
{
	//if for errors
	(*stack)->next->n += (*stack)->n;
	//send to pop
}

void nop
{
 //void everything given to func
}
