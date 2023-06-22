#include "monty.h"

/**
* main - Entry Point of Monty Program
* @argc: Argument Count
* @argv: Argument Vector
* Return: Success (0)
*/

int main(int argc, char **argv)
{
	FILE *file_ptr;
	char *file;

	if (argc != 2) /* Invalid number of argument */
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = argv[1];
	file_ptr = fopen(file, "r");
	if (file_ptr == NULL) /* Can't open file */
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	get_line(file_ptr); /* Get line */

	fclose(file_ptr);
	return (0);
}
