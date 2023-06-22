#include "monty.h"

/**
 * pint_func - function that prints the top stack data
 * @top: global stack variable
 * @line_number: file line number
*/

void pint_func(stack_t **top, unsigned int line_number)
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
	}
}
