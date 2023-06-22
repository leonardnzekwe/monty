#include "monty.h"

/**
 * search_opcode - search for opcode function
 * @opcode: operation code parameter
 * @opnum: operation number parameter
 * @top: stack top parameter
 * Return: True if opcode found, else False
 */

bool search_opcode(char *opcode, char *opnum, stack_t **top)
{
	int j;
	unsigned int opint;

	/* struct two dimensional array */
	instruction_t intruct_opcode[] = {
		{"push", push_func},
		{NULL, NULL}
	};

	if (opnum != NULL)
		opint = atoi(opnum);

	j = 0;
	while (intruct_opcode[j].opcode != NULL)
	{
		if (strcmp(intruct_opcode[j].opcode, opcode) == 0) /* valid opcode */
		{
			intruct_opcode[j].f(top, opint);
			return (true);
		}
		j = j + 1;
	}
	return (false); /* invalid opcode */
}