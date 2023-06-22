#include "monty.h"

/**
 * swap_func - function to swap the stack top value
 * @top: stack top
 * @line_number: file line number
 * Return: 0 if successful else -1
 */

int swap_func(stack_t **top, unsigned int line_number)
{
	int num_nodes;
	stack_t *ptr;
	int temp_value;

	num_nodes = get_num_nodes(top);
	if (num_nodes >= 2)
	{
		ptr = *top;
		temp_value = ptr->n;
		ptr->n = ptr->next->n;
		ptr->next->n = temp_value;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		return (-1);
	}
	return (0);
}
