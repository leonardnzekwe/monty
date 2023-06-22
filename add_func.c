#include "monty.h"

/**
 * add_func - function to remove the top of the stack
 * @top: stack top
 * @line_number: file line number
 * Return: 0 if successful else -1
 */

int add_func(stack_t **top, unsigned int line_number)
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
		ptr->next->n = a + b;
		pop_func(top, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		return (-1);
	}
	return (0);
}
