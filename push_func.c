#include "monty.h"

/**
 * push_func - function that pushes node to the stack
 * @top: stack top
 * @data: stack data
 * Return: 0 if successful else -1
*/

int push_func(stack_t **top, int data)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new != NULL)
	{
		new->prev = NULL;
		new->n = data;
		new->next = NULL;

		new->next = *top;
		if (*top != NULL)
			(**top).prev = new;
		*top = new;
	}
	else
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (-1);
	}
	return (0);
}
