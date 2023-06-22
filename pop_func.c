#include "monty.h"

/**
 * pop_func - function to remove the top of the stack
 * @top: stack top
 * @line_number: file line number
 * Return: 0 if successful else -1
 */

int pop_func(stack_t **top, unsigned int line_number)
{
	stack_t *ptr;

	if (*top != NULL)
	{
		ptr = *top;
		while (ptr != NULL)
		{
			*top = (**top).next;
			free(ptr);
			break;
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		return (-1);
	}
	return (0);
}
