#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct m_stack_s
{
    int n;
    struct m_stack_s *prev;
    struct m_stack_s *next;
} m_stack_t;

typedef struct instruction_s
{
    char *opcode;
    void (*f)(m_stack_t **stack, unsigned int line_number);
} instruction_t;


void free_token(m_stack_t *stack);
int isInteger(const char *str);
void add(m_stack_t **stack, unsigned int line_number);
void nop(m_stack_t **stack, unsigned int line_number);
void push(m_stack_t **stack, unsigned int line_number);
void pall(m_stack_t **stack, unsigned int line_number);
void pint(m_stack_t **stack, unsigned int line_number);
void pop(m_stack_t **stack, unsigned int line_number);
void swap(m_stack_t **stack, unsigned int line_number);
void getf(m_stack_t **stack, char *line, unsigned int line_number);

#endif
