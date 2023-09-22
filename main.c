#include "monty.h"

/**
 * main - main functuon
 * @argc: arguments
 * @argv: argument array
 * Return: int
 */

m_stack_t *new_node = NULL;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    m_stack_t *stack = NULL;
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;

    while (getline(&line, &len, file) != -1)
    {
        line_number++;
        getf(&stack, line, line_number);
    }

    fclose(file);
    free_token(stack);

    if (line)
        free(line);

    exit(EXIT_SUCCESS);
}

/**
 * add - Add the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: The line number where the "add" opcode appears.
 */

void add(m_stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;
}

/**
 * nop - Do nothing.
 * @stack: Pointer to the stack.
 * @line_number: The line number where the "nop" opcode appears.
 */

void nop(m_stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    /* This function does nothing, as it's a placeholder for a no-op */
}
