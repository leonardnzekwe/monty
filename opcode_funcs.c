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

/**
 * pall_func - function that prints the stack data
 * @top: global stack variable
 * @line_number: file line number
 * Return: 0 if successful else do nothing
*/

int pall_func(
	stack_t **top, __attribute__ ((unused)) unsigned int line_number)
{
	stack_t *ptr;

	if (*top != NULL)
	{
		ptr = *top;
		while (ptr != NULL)
		{
			printf("%d\n", (*ptr).n);
			ptr = (*ptr).next;
		}
	}
	return (0);
}

/**
 * pint_func - function that prints the top stack data
 * @top: global stack variable
 * @line_number: file line number
 * Return: 0 if successful else -1
*/

int pint_func(stack_t **top, unsigned int line_number)
{
	stack_t *ptr;

	if (*top != NULL)
	{
		ptr = *top;
		while (ptr != NULL)
		{
			printf("%d\n", (*ptr).n);
			break;
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		return (-1);
	}
	return (0);
}

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
