#include "monty.h"
#define TOKEN_DELIM " \n\r\t "
/**
 * tokenize - tokenize buffer and execute opcode.
 * @line: line of input file
 * @stack: head of double linked lisd
 * @line_n: line of code of file bytecode
 **/
void tokenize(char *line, stack_s **stack, unsigned int line_n)
{
	char *token = NULL, *token_2 = NULL;

	token = strtok(line, TOKEN_DELIM);
	token_2 = strtok(NULL, TOKEN_DELIM);
	if (strcmp(token, "push") == 0)
		check_token(token_2, line_n);
	if (token && token[0] != '#')
		search_function(token, line_n, stack);
}
