#include "monty.h"

/**
 * pchar_func - prints ascii equivalent of the top stack data
 * @top: global stack variable
 * @line_number: file line number
 * Return: 0 if successful else -1
*/

int pchar_func(stack_t **top, unsigned int line_number)
{
	stack_t *ptr;
	int data;

	if (*top != NULL)
	{
		ptr = *top;
		while (ptr != NULL)
		{
			data = (*ptr).n;
			if (!isascii(data))
			{
				fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
				return (-1);
			}
			printf("%c\n", (char)data);
			break;
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		return (-1);
	}
	return (0);
}

/**
 * pstr_func - prints ascii equivalent of the top stack data
 * Till it encounters a non ascii value
 * @top: global stack variable
 * @line_number: file line number
 * Return: 0 if successful else -1
*/

int pstr_func(
	stack_t **top, __attribute__ ((unused)) unsigned int line_number)
{
	stack_t *ptr;
	int data;

	if (*top != NULL)
	{
		ptr = *top;
		while (ptr != NULL)
		{
			data = (*ptr).n;
			if (!isascii(data) || data == 0)
			{
				break;
			}
			printf("%c", (char)data);
			ptr = ptr->next;
		}
		printf("\n");
	}
	else
		printf("\n");
	return (0);
}

/**
 * rotl_func - function rotates the stack to the top
 * The top element of the stack becomes the last one
 * And the second top element of the stack becomes the first one
 * @top: stack top
 * @line_number: file line number
 * Return: 0 if successful else -1
 */

int rotl_func(stack_t **top, unsigned int line_number)
{
	stack_t *ptr;
	int top_value;

	if (*top != NULL)
	{
		ptr = *top;
		top_value = ptr->n;
		if (pop_func(top, line_number) == -1)
			return (-1);
		if (push_end_func(top, top_value) == -1)
			return (-1);
	}
	else
	{
		fprintf(stderr, "L%d: can't rotl, stack empty\n", line_number);
		return (-1);
	}
	return (0);
}

/**
 * rotr_func - function rotates the stack to the bottom
 * The last element of the stack becomes the top element of the stack
 * @top: stack top
 * @line_number: file line number
 * Return: 0 if successful else -1
 */

int rotr_func(stack_t **top, unsigned int line_number)
{
	stack_t *ptr;
	int bottom_value;

	if (*top != NULL)
	{
		ptr = *top;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		bottom_value = ptr->n;
		if (push_func(top, bottom_value) == -1)
			return (-1);
		if (pop_end_func(top, line_number) == -1)
			return (-1);
	}
	else
	{
		fprintf(stderr, "L%d: can't rotr, stack empty\n", line_number);
		return (-1);
	}
	return (0);
}
