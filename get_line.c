#include "monty.h"

/**
 * get_line - Function that reads the file line by line
 * @file_ptr: file pointer parameter
*/

void get_line(FILE *file_ptr)
{
	stack_t *top = NULL; /* Global variable Definition */
	char *line = NULL;
	unsigned int line_number = 1;
	size_t line_length = 0;
	ssize_t read = 0;
	char *opcode = NULL;
	char *opnum = NULL;

	while ((read = getline(&line, &line_length, file_ptr)) != -1)
	{
		if (strcmp(line, "\n") == 0)
			continue;
		opcode = strtok(line, " \t\n"); /* Extract the first string from line */
		while (opcode != NULL)
		{
			opnum = strtok(NULL, " \t\n"); /* Extract the second string from line */
			break;
		}

		if (strcmp(opcode, "pall") == 0) /* opcode is pall */
		{
			pall_func(&top);
			continue;
		}

		if (opnum == NULL) /* No argument to opcode */
		{
			fprintf(stderr, "L %d: usage: push integer\n", line_number);
			clean_up(file_ptr, &top, line);
		}

		if (!search_opcode(opcode, opnum, &top)) /* Unknown Instruction */
		{
			fprintf(stderr, "L %d: unknown instruction %s\n", line_number, opcode);
			clean_up(file_ptr, &top, line);
		}
		line_number++;
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
