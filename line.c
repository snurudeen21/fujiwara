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
		
		free(line);
		if (args[0] == NULL)
		{
			free_buf(args);
			break;
		}
		
		if (strcmp(args[0], "angles") == 0)
        	{
            		a =  angles(args);
			args_counter = 0;     //args_counter
			// Loop through each element in the args array until NULL is encountered
			while (args[args_counter] != NULL)
			{
				args_counter++; // Increment the counter
			}
        	}

		if (strcmp(args[0], "analyze") == 0)
        	{
			//double Cx[args_counter];
            		double *result = analyze(args);
			/*for (int i = 0; i < (args_counter-1);  i++)
				{
					Cx[i] = result[0] + result[1]*cos((*(a+i)*M_PI/180)) + result[2]*(cos(3*(*(a+i))*M_PI/180)) + result[3]*(cos(5*(*(a+i))*M_PI/180));
					printf("%f\n", Cx[i]);
				}*/
        	}
		
   		buflen = 0;
		if (isatty(STDIN_FILENO) != 0)
		{
			break;
		}

	}
	return (bytes);
}
