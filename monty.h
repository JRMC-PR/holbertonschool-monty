#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct m_stack_s
{
int n;
struct  m_stack_s *prev;
struct m_stack_s *next;
} m_stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(m_stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * function prototypes
 */
m_stack_t *new_node;

void pall(m_stack_t **stack, unsigned int line_number);
void push(m_stack_t **stack, unsigned int line_number);
void pint(m_stack_t **stack, unsigned int line_numbe);
void pop(m_stack_t **stack, unsigned int line_numbe);
void swap(m_stack_t **stack, unsigned int line_number);
void add(m_stack_t **stack, unsigned int line_number);
void nop(m_stack_t **stack, unsigned int line_number);
void *getf(m_stack_t **g_stack, char *option, unsigned int line_nuber);
void **Tok(char *opcode, char **tokens);
void free_token(m_stack_t **toki);


#endif
