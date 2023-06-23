#include "monty.h"

/**
 * get_line - Function that reads the file line by line
 * @file_ptr: file pointer parameter
*/

void get_line(FILE *file_ptr)
{
	stack_t *top = NULL; /* Global variable Definition */
	char *line = NULL;
	size_t line_length = 0;
	char *opcode, *opnum, *trimmed_line;
	int opint = 0;
	unsigned int line_number = 0;

	while (getline(&line, &line_length, file_ptr) != -1)
	{
		line_number++;
		/* Remove leading and trailing spaces from the line */
		trimmed_line = trim_white_space(line);
		if (strlen(trimmed_line) == 0)
			continue;  /* Skip blank lines */
		if (strcmp(trimmed_line, "\n") == 0)
			continue;
		opcode = strtok(trimmed_line, " \t\n"); /* Extract the first str from line */
		while (opcode != NULL)
		{
			opnum = strtok(NULL, " \t\n"); /* Extract the second str from line */
			break;
		}
		/* opcode is nop, nop does nothing OR line is a comment, #*/
		if (strcmp(opcode, "nop") == 0 || opcode[0] == '#')
			continue;
		if (strcmp(opcode, "push") == 0) /* opcode is push */
		{
			stack_push(&top, file_ptr, line, opnum, opint, line_number);
			continue;
		}
		if (!search_opcode(opcode, &top, line_number)) /* Unknown Instruction */
			clean_up(file_ptr, &top, line);
	}
	if (line == NULL || line_length == 0)
	{
		fprintf(stderr, "Error: malloc failed\n");
		clean_up(file_ptr, &top, line);
	} free_stack(&top);
	free(line);
}

/**
 * stack_push - function that handles push opcode
 * @top: stack top parameter
 * @file_ptr: file pointer parameter
 * @line: file line parameter
 * @opnum: opcode number parameter
 * @opint: opcode integer parameter
 * @line_number: file line number
 */

void stack_push(stack_t **top, FILE *file_ptr, char *line,
char *opnum, int opint, unsigned int line_number)
{
	if (opnum != NULL)
	{
		if (!is_valid_number(opnum))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			clean_up(file_ptr, top, line);
		}
		opint = atoi(opnum);
	}
	else /* No argument to push */
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		clean_up(file_ptr, top, line);
	}
	if (push_func(top, opint) == -1)
		clean_up(file_ptr, top, line);
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
