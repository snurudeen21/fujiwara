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

	//while (true)
	//{
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
			//break;
		}

		if (bytes == 1 && line[bytes - 1] == '\n')
		{
			free(line);
			return (bytes);
		}

		else
		{
			line[bytes - 1] = '\0';
		}
		
		if (strlen(line) == 0)
		{
			free(line);
			//break;
		}

		//tokenize
		args = split_line(line);
		
		free(line);
		if (args[0] == NULL)
		{
			free_buf(args);
			return (bytes);
			//break;
		}

		/*if (strcmp(args[0], "\n") == 0)
		{
			return (bytes);
		}*/

		if ((strcmp(args[0], "angles") != 0) && (strcmp(args[0], "analyze") != 0) && (strcmp(args[0], "save") != 0) && (strcmp(args[0], "plot") != 0))
			{
            		printf("List of Commands Available: angles, analyze, save and plot\nType: command_name -h to see usage\n");
        	}
		
		if (strcmp(args[0], "angles") == 0)
        	{
            		a =  angles(args);
        	}


		if (strcmp(args[0], "analyze") == 0)
        {
			
            result = analyze(args);
        }

		if (strcmp(args[0], "save") == 0)
        {
    		save_to_csv(args); // Pass the filename to the save_to_csv function
		}

		if (strcmp(args[0], "plot") == 0)
        {
    		plot_with_gnuplot(args); // Pass the filename to the save_to_csv function
		}
		
   		buflen = 0;
		//if (isatty(STDIN_FILENO) != 0)
		//{
			//break;
		//}

	//}
	return (bytes);
}