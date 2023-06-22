#include "monty.h"

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
