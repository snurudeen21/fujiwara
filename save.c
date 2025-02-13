#include "shell.h"

void save_to_csv(char **args) 
{
    int args_count = 0;

    while (args[args_count] != NULL)
    {
        args_count++; // Increment the counter
    }

    if (args[1] && (strcmp(args[1], "-h") == 0) && (args_count == 2 ))
        	{
            	printf("Usage: save file_name\n");
                return;
        	}

    else
    {
        if (args_count == 2)
        {
            if (a != NULL && result != NULL)
            {
                char filename[30];
                if (strlen(args[1]) <=30)
                {
                    strcpy(filename, args[1]);
                }
                else
                {
                    printf("Name of file too long\n");
                    return;
                }
                
                FILE *file = fopen(filename, "w");
                if (file == NULL) {
                    perror("Error opening file");
                    return;
                }

                // Write header row
                fprintf(file, "Angle of Attack,Cx,Cy,Cn,Ck\n");
                
                double Cx[size];
                double Cy[size];
                double Cn[size];
                double Ck[size];

                for (int i = 0; i < size;  i++)
                {
                Cx[i] = result[0] + result[1]*cos((*(a+i))*M_PI/180) + result[2]*(cos(3*(*(a+i))*M_PI/180)) + result[3]*(cos(5*(*(a+i))*M_PI/180));
                }
                for (int j = 0; j < size;  j++)
                {
                Cy[j] = result[4]*sin((*(a+j))*M_PI/180) + result[5]*(sin(3*(*(a+j))*M_PI/180)) + result[6]*(sin(5*(*(a+j))*M_PI/180));
                }
                for (int k = 0; k < size;  k++)
                {
                Cn[k] = result[7]*sin((*(a+k))*M_PI/180) + result[8]*(sin(2*(*(a+k))*M_PI/180)) + result[9]*(sin(3*(*(a+k))*M_PI/180));
                }
                    
                for (int m = 0; m < size;  m++)
                {
                Ck[m] = result[10]*sin((*(a+m))*M_PI/180) + result[11]*(sin(2*(*(a+m))*M_PI/180)) + result[12]*(sin(3*(*(a+m))*M_PI/180)) + result[13]*(sin(5*(*(a+m))*M_PI/180));	
                }
                    
                // Write data rows
                for (int c = 0; c < size; c++) {
                    fprintf(file, "%d,%f,%f,%f,%f\n", a[c], Cx[c], Cy[c], Cn[c], Ck[c]);
                }

                printf("Data successfully saved to %s\n", filename);
                fclose(file);

                return;
            }
            else
            {
                printf("No Data to Save\n");
                return;
            }
        }

        else
        {
            printf("Arguments must be one, type save -h for help\n");
            return;
        }
    }
    
}