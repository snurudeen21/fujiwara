#include "shell.h"

/**
* main - execute line, tokens and excecute functions
*
* Return: 0
*/

int main(void)
{
	bool is_pipe = false;
	ssize_t bytes;

	while (true && !is_pipe)
	{
		if (isatty(STDIN_FILENO) == 0)
		{
			is_pipe = true;
		}
		else
			my_prompt();
		bytes = read_line();
		if (bytes == EOF)
		{
			is_pipe = true;
			exit(0);
		}
	}
	return (0);
}
