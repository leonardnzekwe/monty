#include "monty.h"

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

/**
 * pop_end_func - function to remove the bottom of the stack
 * @top: stack top
 * @line_number: file line number
 * Return: 0 if successful else -1
 */

int pop_end_func(stack_t **top, unsigned int line_number)
{
	stack_t *ptr;

	if (*top != NULL)
	{
		ptr = *top;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->prev->next = NULL;
		free(ptr);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		return (-1);
	}
	return (0);
}
