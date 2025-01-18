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
        	}

		if (strcmp(args[0], "analyze") == 0)
        	{
			double Cx[size];
			double Cy[size];
			double Cn[size];
			double Ck[size];
		
            		result = analyze(args);
			for (int i = 0; i < size;  i++)
				{
					Cx[i] = result[0] + result[1]*cos((*(a+i))*M_PI/180) + result[2]*(cos(3*(*(a+i))*M_PI/180)) + result[3]*(cos(5*(*(a+i))*M_PI/180));
					printf("%f  ", Cx[i]);
				}
			printf("************************************************");
			printf("************************************************");
			for (int j = 0; j < size;  j++)
				{
					Cy[j] = result[4]*sin((*(a+j))*M_PI/180) + result[5]*(sin(3*(*(a+j))*M_PI/180)) + result[6]*(sin(5*(*(a+j))*M_PI/180));
					printf("%f  ", Cy[j]);
				}
			printf("************************************************");
			printf("************************************************");
			for (int k = 0; k < size;  k++)
				{
					Cn[k] = result[7]*sin((*(a+k))*M_PI/180) + result[8]*(sin(2*(*(a+k))*M_PI/180)) + result[9]*(sin(3*(*(a+k))*M_PI/180));
					printf("%f  ", Cn[k]);
				}
			printf("************************************************");
			printf("************************************************");
			for (int m = 0; m < size;  m++)
				{
					Ck[m] = result[10]*sin((*(a+m))*M_PI/180) + result[11]*(sin(2*(*(a+m))*M_PI/180)) + result[12]*(sin(3*(*(a+m))*M_PI/180)) + result[13]*(sin(5*(*(a+m))*M_PI/180));
					printf("%f  ", Ck[m]);
				}
			printf("************************************************\n");
        	}

		if (strcmp(args[0], "save") == 0)
        	{
			char filename[30]; // Allocate enough space for a typical filename (255 characters + null terminator)
    
    			printf("Enter the filename to save: ");
   	 		scanf("%30s", filename); // Read the filename, limiting input to 255 characters
    			save_to_csv(filename); // Pass the filename to the save_to_csv function
		}	
		
   		buflen = 0;
		if (isatty(STDIN_FILENO) != 0)
		{
			break;
		}

	}
	return (bytes);
}
