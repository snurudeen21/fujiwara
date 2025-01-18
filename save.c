#include "shell.h"

void save_to_csv(const char *filename) 
{
    
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Write header row
    fprintf(file, "a,Cx,Cy,Cn,Ck\n");
    
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

    fclose(file);
    printf("Data successfully saved to %s\n", filename);

    return;
}
