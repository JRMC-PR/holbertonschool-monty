#include "monty.h"

m_stack_t *g_stack = NULL;

/**
 *
 */

int main(int argc, char *argv[])
{
    char *opcode;
    unsigned int line_number = 0;
    size_t len = 0;
    ssize_t read;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL}};

    while ((read = getline(&opcode, &len, file)) != -1)
    {
        line_number++;
        opcode[strlen(opcode) - 1] = '\0'; /* Remove trailing newline */

        for (int i = 0; instructions[i].opcode; i++)
        {
            if (strcmp(opcode, instructions[i].opcode) == 0)
            {
                instructions[i].f(&g_stack, line_number);
                break;
            }
            if (!instructions[i + 1].opcode)
            {
                fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
                free(opcode);
                fclose(file);
                exit(EXIT_FAILURE);
            }
        }
    }

    free(opcode);
    fclose(file);
    exit(EXIT_SUCCESS);
}
