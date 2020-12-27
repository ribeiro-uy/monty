#include "monty.h"
/*#define TOKEN_DELIM " \n\r\t "*/
/* Number = global variable. */
int number = 0;
/**
 * main - Main function
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 in success, 1 in error
 **/
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	func_main(argv[1]);
	exit(EXIT_SUCCESS);
}

/**
 * func_main - function with main loop
 * @filename: the name of the file
 * Return: Nothing
 */

void func_main(char *filename)
{
	FILE *stream;
	size_t len = 0;
	ssize_t nread;
	unsigned int line_n = 1;
	char *line = NULL;
	stack_s *stack = NULL;
	int count = 0;

	stream = fopen(filename, "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while ((nread = getline(&line, &len, stream)) != EOF)
	{
		while (line[0] == 32 || line[0] == 9)
		{
			count++;
			line++;
		}
		if (line[0] == '\n' || line[0] == '\0')
		{
			line_n++;
			continue;
		}
		tokenize(line, &stack, line_n);
		line_n++;
	}
	for (; count > 0; count--)
		line--;
	free(line);
	free_stack(stack);
	fclose(stream);
}
