#include "monty.h"

/**
 * search_opcode - search for opcode function
 * @opcode: operation code parameter
 * @top: stack top parameter
 * @line_number: file line number
 * Return: True if opcode found, else False
 */

bool search_opcode(char *opcode, stack_t **top, unsigned int line_number)
{
	int j;
	/* struct two dimensional array */
	instruction_t intruct_opcode[] = {
		{"pall", pall_func}, {"pint", pint_func},
		{"pop", pop_func}, {"swap", swap_func},
		{"add", add_func}, {"sub", sub_func},
		{"div", div_func}, {"mul", mul_func},
		{"mod", mod_func}, {"pchar", pchar_func},
		{"pstr", pstr_func}, {"rotl", rotl_func},
		{NULL, NULL}
	};

	j = 0;
	while (intruct_opcode[j].opcode != NULL)
	{
		if (strcmp(intruct_opcode[j].opcode, opcode) == 0) /* valid opcode */
		{
			if (intruct_opcode[j].f(top, line_number) == -1)
				return (false);
			return (true);
		}
		j = j + 1;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	return (false); /* invalid opcode */
}

/**
 * pchar_func - prints ascii equivalent of the top stack data
 * @top: global stack variable
 * @line_number: file line number
 * Return: 0 if successful else -1
*/

int pchar_func(stack_t **top, unsigned int line_number)
{
	stack_t *ptr;
	int data;

	if (*top != NULL)
	{
		ptr = *top;
		while (ptr != NULL)
		{
			data = (*ptr).n;
			if (!isascii(data))
			{
				fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
				return (-1);
			}
			printf("%c\n", (char)data);
			break;
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		return (-1);
	}
	return (0);
}

/**
 * pstr_func - prints ascii equivalent of the top stack data
 * Till it encounters a non ascii value
 * @top: global stack variable
 * @line_number: file line number
 * Return: 0 if successful else -1
*/

int pstr_func(
	stack_t **top, __attribute__ ((unused)) unsigned int line_number)
{
	stack_t *ptr;
	int data;

	if (*top != NULL)
	{
		ptr = *top;
		while (ptr != NULL)
		{
			data = (*ptr).n;
			if (!isascii(data) || data == 0)
			{
				break;
			}
			printf("%c", (char)data);
			ptr = ptr->next;
		}
		printf("\n");
	}
	else
		printf("\n");
	return (0);
}

/**
 * rotl_func - function rotates the stack to the top
 * The top element of the stack becomes the last one
 * And the second top element of the stack becomes the first one
 * @top: stack top
 * @line_number: file line number
 * Return: 0 if successful else -1
 */

int rotl_func(stack_t **top, unsigned int line_number)
{
	stack_t *ptr;
	int top_value;

	ptr = *top;
	top_value = ptr->n;
	if (pop_func(top, line_number) == -1)
		return (-1);
	if (push_end_func(top, top_value) == -1)
		return (-1);
	return (0);
}

/**
 * push_end_func - function that pushes node to the end of the stack
 * @top: stack top
 * @data: stack data
 * Return: 0 if successful else -1
*/

int push_end_func(stack_t **top, int data)
{
	stack_t *new;
	stack_t *ptr;

	new = malloc(sizeof(stack_t));
	if (new != NULL)
	{
		new->prev = NULL;
		new->n = data;
		new->next = NULL;

		if (*top == NULL)
			*top = new;
		else
		{
			ptr = *top;
			while (ptr->next != NULL)
			{
				ptr = ptr->next;
			}
			ptr->next = new;
			new->prev = ptr;
		}
	}
	else
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (-1);
	}
	return (0);
}
