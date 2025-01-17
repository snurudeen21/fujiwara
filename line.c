#include "shell.h"

/**
* read_line - read <stdin> using <getline>
*
* Return: line
*/
ssize_t read_line(void)
{
	char *line = NULL;
	char **args;
	size_t buflen = 0;
	ssize_t bytes;

	while (true)
	{
		bytes = getline(&line, &buflen, stdin);

		if (bytes == EOF)
		{
			free(line);
			return (bytes);
		}

		if (bytes == -1)
		{
			perror("Error in getline");
			free(line);
			break;
		}
		if (line[bytes - 1] == '\n')
		{
			line[bytes - 1] = '\0';
		}
		
		if (_strlen(line) == 0)
		{
			free(line);
			break;
		}

		args = split_line(line);
		int args_count = 0;

		// Loop through each element in the args array until NULL is encountered
		while (args[args_count] != NULL)
		{
			args_count++; // Increment the counter
		}
		
		free(line);
		if (args[0] == NULL)
		{
			free_buf(args);
			break;
		}
		
		if (strcmp(args[0], "angles") == 0)
        	{
            		int *angle_of _attack =  angles(args);
        	}

		if (strcmp(args[0], "analyze") == 0)
        	{
            		double result = analyze(args);
			for (i = 0; i < (args_count-1);  i++)
				Cx = Cx = x0 + x1*round(math.cos(math.radians(a)), 6) + x3*round(math.cos(math.radians(3*a)), 6) + x5*round(math.cos(math.radians(5*a)), 6)	
        	}
		
   		buflen = 0;
		if (isatty(STDIN_FILENO) != 0)
		{
			break;
		}

	}
	return (bytes);
}
