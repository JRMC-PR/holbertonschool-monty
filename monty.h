<<<<<<< HEAD
#ifndef monty_h
#define monty_h
#include <>
=======
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


>>>>>>> e724d6433ffa936c5abc5bbc823d2d6f5cb75697
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} s_t;

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
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
<<<<<<< HEAD
/*Funciton protoypes*/
void push(stack_t stack, unsigned int line_number);
=======


s_t *stack = NULL;

/**
 * function prototypes
 */

void pall(s_t **stack, unsigned int line_number);


>>>>>>> e724d6433ffa936c5abc5bbc823d2d6f5cb75697
#endif
