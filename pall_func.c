#include "monty.h"

/**
 * pall_func - function that prints the stack data
 * @top: global stack variable
*/

void pall_func(stack_t **top)
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
}
