#include "monty.h"

/**
 * get_num_nodes - function to get the number of nodes in the stack
 * @top: stack top parameter
 * Return: number of elements/ nodes
 */

int get_num_nodes(stack_t **top)
{
	int num_nodes = 0;
	stack_t *ptr;

	if (*top == NULL)
		return (0);
	ptr = *top;
	while (ptr != NULL)
	{
		num_nodes++;
		ptr = (*ptr).next;
	}
	return (num_nodes);
}

/**
 * is_valid_number - function to check if a string is a valid number
 * @str: string to check
 * Return: 1 if the string is a valid number, 0 otherwise
 */

int is_valid_number(const char *str)
{
	int i = 0;

	if (str == NULL || *str == '\0')
		return (0);

	if (str[i] == '-' || str[i] == '+')
		i++;

	if (str[i] == '\0') /* The string contains only a sign character */
		return (0);

	for (; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}

/**
 * trim_white_space - function that trims
 * leading and trailing white spaces
 * @str: string to trim
 * Return: trimmed string
 */

char *trim_white_space(char *str)
{
	char *end;

	/* Trim leading spaces */
	while (isspace((unsigned char)*str))
		str++;

	if (*str == '\0')  /* Line contains only spaces */
		return (str);

	/* Trim trailing spaces */
	end = str + strlen(str) - 1;
	while (end > str && isspace((unsigned char)*end))
		end--;

	/* Null-terminate the trimmed line */
	*(end + 1) = '\0';

	return (str);
}

/**
 * free_stack - function to free the stack
 * @top: stack to be freed
 */

void free_stack(stack_t **top)
{
	stack_t *ptr;

	while (*top != NULL)
	{
		ptr = *top;
		*top = (**top).next;
		free(ptr);
	}
}

/**
 * clean_up - function for cleaning up, in failure scenarios
 * @file_ptr: file pointer parameter
 * @top: stack top parameter
 * @line: file line paramter
*/
void clean_up(FILE *file_ptr, stack_t **top, char *line)
{
	free_stack(top);
	free(line);
	fclose(file_ptr);
	exit(EXIT_FAILURE);
}
