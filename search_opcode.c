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
		{"pall", pall_func},
		{"pint", pint_func},
		{NULL, NULL}
	};

	j = 0;
	while (intruct_opcode[j].opcode != NULL)
	{
		if (strcmp(intruct_opcode[j].opcode, opcode) == 0) /* valid opcode */
		{
			intruct_opcode[j].f(top, line_number);
			return (true);
		}
		j = j + 1;
	}
	return (false); /* invalid opcode */
}
