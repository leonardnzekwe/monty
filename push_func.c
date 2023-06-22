#include "monty.h"

/**
 * push_func - function that pushes node to the stack
 * @top: stack top
 * @data: stack data
*/

void push_func(stack_t **top, unsigned int data)
{
	stack_t *new;
	int n;

	new = malloc(sizeof(stack_t));
	if (new != NULL)
	{
		n = (int)data;
		new->prev = NULL;
		new->n = n;
		new->next = NULL;

		new->next = *top;
		if (*top != NULL)
			(**top).prev = new;
		*top = new;
	}
}
