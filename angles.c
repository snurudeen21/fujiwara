#include "shell.h"

/**
* angles - read angles
*
* Return: angles
*/

int *angles(char **args)
{
    int args_count = 0;

    // Loop through each element in the args array until NULL is encountered
    while (args[args_count] != NULL)
    {
        args_count++; // Increment the counter
    }

    if (args_count == 4)
    {
        int *array;
        int start = atoi(args[1]);  // Convert first argument to an integer
        int end = atoi(args[2]);    // Convert second argument to an integer
        int step = atoi(args[3]);   // Convert third argument to an integer
    
        if (step <= 0 || start > end)
        {
            printf("Invalid arguments: Ensure step > 0 and start <= end\n");
            return NULL;
        }
    
        size = 1 + ((end - start) / step); // Calculate array size
        int counter = 0;
    
        // Dynamically allocate memory for the array
        array = (int *)malloc(size * sizeof(int));
        if (array == NULL)
        {
            perror("Failed to allocate memory");
            return NULL;
        }
    
        // Fill the array
        for (int i = start; i <= end; i += step)
        {
            *(array+counter) = i;
            printf("%d ", *(array+counter));
            counter++;
        }
    
        return array; // Return the array
    }

    else
        printf("Arguments must be three, type angles -h for help");
        return NULL;
}
