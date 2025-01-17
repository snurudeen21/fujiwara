#include "shell.h"

/**
* angles - read angles
*
* Return: line
*/

double *analyze(char **args)
{
    int args_count = 0;

    // Loop through each element in the args array until NULL is encountered
    while (args[args_count] != NULL)
    {
        args_count++; // Increment the counter
    }

    if (args_count == 11)
    {
        double *values = (double *)malloc(args_count * sizeof(double));
        if (values == NULL)
        {
          perror("Failed to allocate memory");
          return 1;
        }

        // Convert strings to floating-point numbers and store in the array
        for (int i = 0; i < args_count; i++)
        {
          values[i] = strtod(args[i], NULL);
          printf("String: %s, Converted to double: %f\n", args[i], values[i]);
        }

        // Free the allocated memory
        free(values);

        return 0;
}


    else
        printf("Arguments must be three, type angles -h for help");
        return NULL;
}
