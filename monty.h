#ifndef MONTY_H
#define MONTY_H

/* Macros */
#define _GNU_SOURCE

/* Header Files */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stdbool.h>

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
} stack_t;

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

/* GLobal Variable Declaration */
extern stack_t *top;

/* Function Prototypes */
void get_line(FILE *file_ptr);
bool search_opcode(char *opcode, int opnum, stack_t **top);
void push_func(stack_t **top, unsigned int data);
void pall_func(stack_t **top);
void free_stack(stack_t **top);
void clean_up(FILE *file_ptr, stack_t **top, char *line);

#endif /* MONTY_H */
