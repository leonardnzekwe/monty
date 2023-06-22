#include "monty.h"

/**
 * add_func - function to add topmost two values of the stack
 * Afterwhich it removes the top node of the stack
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

/**
 * sub_func - function to substract topmost two values of the stack
 * Afterwhich it removes the top node of the stack
 * @top: stack top
 * @line_number: file line number
 * Return: 0 if successful else -1
 */

int sub_func(stack_t **top, unsigned int line_number)
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
		ptr->next->n = b - a;
		pop_func(top, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		return (-1);
	}
	return (0);
}

/**
 * mul_func - function to multiply topmost two values of the stack
 * Afterwhich it removes the top node of the stack
 * @top: stack top
 * @line_number: file line number
 * Return: 0 if successful else -1
 */

int mul_func(stack_t **top, unsigned int line_number)
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
		ptr->next->n = b * a;
		pop_func(top, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		return (-1);
	}
	return (0);
}

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

/**
 * mod_func - function to get the mod of topmost two values of the stack
 * Afterwhich it removes the top node of the stack
 * @top: stack top
 * @line_number: file line number
 * Return: 0 if successful else -1
 */

int mod_func(stack_t **top, unsigned int line_number)
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
		ptr->next->n = b % a;
		pop_func(top, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		return (-1);
	}
	return (0);
}
