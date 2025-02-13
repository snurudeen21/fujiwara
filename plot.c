#include "shell.h"

void plot_with_gnuplot(char **args) {
    int args_count = 0;

    while (args[args_count] != NULL)
    {
        args_count++; // Increment the counter
    }

    if (args[1] && (strcmp(args[1], "-h") == 0) && (args_count == 2 ))
        	{
            		printf("Usage: plot\n");
                    return;
        	}

    else
    {
        if (args_count == 1)
        {
            if (a != NULL && result != NULL)
            {
                float Cx[size];
                float Cy[size];
                float Cn[size];
                float Ck[size];

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

                FILE *gnuplot = popen("gnuplot -persistent", "w");  // Open gnuplot
                if (gnuplot == NULL) {
                    perror("Error opening gnuplot");
                    return;
                }

                // Set titles, labels, and legend, zero crossing
                fprintf(gnuplot, "Coefficient of Wind Forces and Moments'\n");
                fprintf(gnuplot, "set xlabel 'Attack Angles'\n");
                fprintf(gnuplot, "set ylabel 'Coefficient'\n");
                fprintf(gnuplot, "set key top left\n");  // Position legend in top-left
                fprintf(gnuplot, "set xzeroaxis\n");

                // Plot two datasets with a legend
                fprintf(gnuplot, "plot '-' with linespoints title 'Cx', '-' with linespoints title 'Cy', '-' with linespoints title '10Cn', '-' with linespoints title 'Ck'\n");
                    
                // Plot data rows
                for (int c = 0; c < size; c++) {
                    fprintf(gnuplot, "%d %f\n", a[c], Cx[c]);
                }
                fprintf(gnuplot, "e\n");  // End of first dataset

                // Plot data rows
                for (int c = 0; c < size; c++) {
                    fprintf(gnuplot, "%d %f\n", a[c], Cy[c]);
                }
                fprintf(gnuplot, "e\n");  // End of first dataset

                // Plot data rows
                for (int c = 0; c < size; c++) {
                    fprintf(gnuplot, "%d %f\n", a[c], 10*Cn[c]);
                }
                fprintf(gnuplot, "e\n");  // End of first dataset

                // Plot data rows
                for (int c = 0; c < size; c++) {
                    fprintf(gnuplot, "%d %f\n", a[c], Ck[c]);
                }
                fprintf(gnuplot, "e\n");  // End of first dataset


                fflush(gnuplot);  // Flush data to gnuplot
                pclose(gnuplot);  // Close gnuplot
                return;
            }

            else
            {
                printf("Plot Data Missing\n");
                return;
            }
        }

        else
        {
            printf("This command takes no Argument, type plot -h for help\n");
            return;
        }
    }
}