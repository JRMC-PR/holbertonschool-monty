#include "monty.h"

/**
 *pall - print all opcode
 *@stack: array of data to print
 *@line_number: lines in input;
 */

{
	s_t *tmp = *stack;

	(void)line_number;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
