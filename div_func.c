#include "monty.h"

/**
 * div_func - function to divide topmost two values of the stack
 * Afterwhich it removes the top node of the stack
 * @top: stack top
 * @line_number: file line number
 * Return: 0 if successful else -1
 */

int div_func(stack_t **top, unsigned int line_number)
{
	int num_nodes;
	stack_t *ptr;
	int a, b;

	num_nodes = get_num_nodes(top);
	if (num_nodes >= 2)
	{
		ptr = *top;
		a = ptr->n;
		b = ptr->next->n;
		if (a == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			return (-1);
		}
		ptr->next->n = b / a;
		pop_func(top, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		return (-1);
	}
	return (0);
}
