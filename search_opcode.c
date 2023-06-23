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
