#include "monty.h"

/**
 * get_line - Function that reads the file line by line
 * @file_ptr: file pointer parameter
*/

void get_line(FILE *file_ptr)
{
	stack_t *top = NULL; /* Global variable Definition */
	char *line = NULL;
	unsigned int line_number = 0;
	size_t line_length = 0;
	ssize_t read = 0;
	char *opcode = NULL;
	char *opnum = NULL;
	int opint;

	while ((read = getline(&line, &line_length, file_ptr)) != -1)
	{
		line_number++;
		if (strcmp(line, "\n") == 0)
			continue;
		opcode = strtok(line, " \t\n"); /* Extract the first string from line */
		while (opcode != NULL)
		{
			opnum = strtok(NULL, " \t\n"); /* Extract the second string from line */
			break;
		}
		if (strcmp(opcode, "push") == 0) /* opcode is push */
		{
			if (opnum != NULL)
				opint = atoi(opnum);
			else /* No argument to push */
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				clean_up(file_ptr, &top, line);
			}
			if (push_func(&top, opint) == -1)
				clean_up(file_ptr, &top, line);
			continue;
		}
		if (!search_opcode(opcode, &top, line_number)) /* Unknown Instruction */
		{
			clean_up(file_ptr, &top, line);
		}
	}
	free_stack(&top);
	free(line);
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
 * clean_up - helper function to get_line()
 * For cleaning up, in failure scenarios
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
