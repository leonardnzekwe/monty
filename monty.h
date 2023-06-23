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
	int (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* GLobal Variable Declaration */
extern stack_t *top;

/* Function Prototypes */
void get_line(FILE *file_ptr);
bool search_opcode(char *opcode, stack_t **top, unsigned int line_number);
int push_func(stack_t **top, int data);
int push_end_func(stack_t **top, int data);
int pall_func(stack_t **top, unsigned int line_number);
int pint_func(stack_t **top, unsigned int line_number);
int pop_func(stack_t **top, unsigned int line_number);
int swap_func(stack_t **top, unsigned int line_number);
int add_func(stack_t **top, unsigned int line_number);
int sub_func(stack_t **top, unsigned int line_number);
int div_func(stack_t **top, unsigned int line_number);
int mul_func(stack_t **top, unsigned int line_number);
int mod_func(stack_t **top, unsigned int line_number);
int pchar_func(stack_t **top, unsigned int line_number);
int pstr_func(stack_t **top, unsigned int line_number);
int rotl_func(stack_t **top, unsigned int line_number);
int rotr_func(stack_t **top, unsigned int line_number);
int pop_end_func(stack_t **top, unsigned int line_number);
void free_stack(stack_t **top);
void clean_up(FILE *file_ptr, stack_t **top, char *line);
int get_num_nodes(stack_t **top);
int is_valid_number(const char *str);
void stack_push(stack_t **top, FILE *file_ptr, char *line,
char *opnum, int opint, unsigned int line_number);
char *trim_white_space(char *str);

#endif /* MONTY_H */
