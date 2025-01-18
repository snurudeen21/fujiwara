#include "shell.h"

/**
* angles - analyze data
*
* Return: analyzed data
*/

double *analyze(char **args)
{
    int args_count = 0;

    // Loop through each element in the args array until NULL is encountered
    while (args[args_count] != NULL)
    {
        args_count++; // Increment the counter
    }

    if (args_count == 10)
    {
        double *values = (double *)malloc(args_count * sizeof(double));
        if (values == NULL)
        {
          perror("Failed to allocate memory");
          return NULL;
        }

        // Convert strings to floating-point numbers and store in the array
        for (int i = 1; i < args_count; i++)
        {
          values[i] = strtod(args[i], NULL);
          printf("String: %s, Converted to double: %f\n", args[i], values[i]);
        }

        double L = values[0], B = values[1], HC = values[2], HBR = values[3], C = values[4], CBR = values[5], AT = values[6], AL = values[7], AOD = values[8];

        // Free the allocated memory
        free(values);

        float C_x_x0[4] = {-0.33, 0.293, 0.0193, 0.682};
        float C_x_x1[8] = {-1.353, 1.7, 2.87, -0.463, -0.57, -6.64, -0.0123, 0.0202};
        float C_x_x3[8] = {0.83, -0.413, -0.0827, -0.563, 0.804, -5.67, 0.0401, -0.132};
        float C_x_x5[4] = {0.0372, -0.0075, -0.103, 0.0921};
    
        // C_y data
        float C_y_y1[6] = {0.684, 0.717, -3.22, 0.0281, 0.0661, 0.298};
        float C_y_y3[7] = {-0.4,0.282,0.307,0.0519,0.0526,-0.0814,0.0582};     
        float C_y_y5[7] = {0.122, -0.166, -0.0054, -0.0481, -0.0136, 0.0864, -0.0297};
    
        // C_n data
        float C_n_n1[9] = {0.299, 1.71, 0.183, -1.09, -0.0442, -0.289, 4.24, -0.0646, 0.0306};
        float C_n_n2[9] = {0.117, 0.123, -0.323, 0.0041, -0.166, -0.0109, 0.174, 0.214, -1.06};
        float C_n_n3[4] = {0.023, 0.0385, -0.0339, 0.0023};
    
        // C_k data
        float C_k_k1[9] = {3.63, -30.7, 16.8, 3.27, -3.03, 0.552, -3.03, 1.82, -0.224};
        float C_k_k2[8] = {-0.48, 0.166, 0.318, 0.132, -0.148, 0.408, -0.0394, 0.0041};
        float C_k_k3[7] = {0.164, -0.17, 0.0803, 4.92, -1.78, 0.0404, -0.739};
        float C_k_k5[6] = {0.449, -0.148, -0.0049, -0.396, -0.0109, -0.0726};

        double x0 = C_x_x0[0] 
		 + C_x_x0[1]*((B*HBR)/AT)
		 + C_x_x0[2]*(C/HC) 
		 + C_x_x0[3]*(AOD/pow(L,2));
        
        
        double x1 = C_x_x1[0] 
         + C_x_x1[1] * (AL / (L * B)) 
         + C_x_x1[2] * ((L * HC) / AL) 
         + C_x_x1[3] * ((L * HBR) / AL) 
         + C_x_x1[4] * (AOD / AL) 
         + C_x_x1[5] * (AT / (L * B)) 
         + C_x_x1[6] * (pow(L, 2) / AT) 
         + C_x_x1[7] * (L / HC);
         

        double x3 = C_x_x3[0] 
		 + C_x_x3[1]*pow(((L*HBR)/AL),-1)
		 + C_x_x3[2]*(AL/AT)
		 + C_x_x3[3]*((L*HC)/AL)
		 + C_x_x3[4]*(AOD/AL)
		 + C_x_x3[5]*(AOD/pow(L,2))
		 + C_x_x3[6]*(C/HC)
		 + C_x_x3[7]*(CBR/L);
			   
		
        double x5 = C_x_x5[0] 
		 + C_x_x5[1]*(AL/AOD)
		 + C_x_x5[2]*(CBR/L) 
		 + C_x_x5[3]*(AL/(L*B));
        
        double y1 = C_y_y1[0] 
		 + C_y_y1[1]*(CBR/L) 
		 + C_y_y1[2]*(C/L) 
		 + C_y_y1[3]*(AL/AOD)
		 + C_y_y1[4]*(C/HC) 
		 + C_y_y1[5]*(AT/(B*HBR));
		 
		 
        double y3 = C_y_y3[0] 
		 + C_y_y3[1]*(AL/(L*B)) 
		 + C_y_y3[2]*((L*HC)/AL) 
		 + C_y_y3[3]*(CBR/L) 
		 + C_y_y3[4]*(B/HBR)
		 + C_y_y3[5]*(AOD/AL) 
		 + C_y_y3[6]*(AT/(B*HBR));
		 
		 
        double y5 = C_y_y5[0] 
		 + C_y_y5[1]*(AL/(L*B)) 
		 + C_y_y5[2]*(L/HBR) 
		 + C_y_y5[3]*(CBR/L) 
		 + C_y_y5[4]*(AT/pow(B,2)) 
		 + C_y_y5[5]*(C/L) 
		 + C_y_y5[6]*((L*HC)/AL);

        double n1 = C_n_n1[0] 
		 + C_n_n1[1]*(C/L) 
		 + C_n_n1[2]*((L*HC)/AL) 
		 + C_n_n1[3]*(AT/AL)
		 + C_n_n1[4]*(C/HC) 
		 + C_n_n1[5]*(AL/(L*B)) 
		 + C_n_n1[6]*(AT/pow(L,2)) 
		 + C_n_n1[7]*(pow(B,2)/AT) 
		 + C_n_n1[8]*(CBR/L);
		 
		 
        double n2 = C_n_n2[0] 
		 + C_n_n2[1]*(CBR/L) 
		 + C_n_n2[2]*(C/L) 
		 + C_n_n2[3]*(AL/AOD)
		 + C_n_n2[4]*(AT/pow(B,2)) 
		 + C_n_n2[5]*(L/HBR)
		 + C_n_n2[6]*(AT/(B*HBR))
		 + C_n_n2[7]*(AL/(L*B)) 
		 + C_n_n2[8]*(AL/pow(L,2));
		 
		 
        double n3 = C_n_n3[0] 
		 + C_n_n3[1]*(CBR/L) 
		 + C_n_n3[2]*(AT/(B*HBR))
		 + C_n_n3[3]*(AL/AT);
        
        double k1 = C_k_k1[0] 
		 + C_k_k1[1]*(HBR/L) 
		 + C_k_k1[2]*(AT/(L*B)) 
		 + C_k_k1[3]*((L*HC)/AL)
		 + C_k_k1[4]*(C/L)
		 + C_k_k1[5]*(CBR/L) 
		 + C_k_k1[6]*(B/HBR)
		 + C_k_k1[7]*((B*B)/AT) 
		 + C_k_k1[8]*(L/B);
		 
		 
        double k2 = C_k_k2[0] 
		 + C_k_k2[1]*(B/HBR)
		 + C_k_k2[2]*(AT/(B*B)) 
		 + C_k_k2[3]*(AL/(L*HC))
		 + C_k_k2[4]*(CBR/L) 
		 + C_k_k2[5]*((HBR*C)/AL)
		 + C_k_k2[6]*(L/B)
		 + C_k_k2[7]*((L*L)/AL);
		 
		 
        double k3 = C_k_k3[0] 
		 + C_k_k3[1]*((B*B)/AT) 
		 + C_k_k3[2]*(CBR/L) 
		 + C_k_k3[3]*(HC/L) 
		 + C_k_k3[4]*(AT/(L*B)) 
		 + C_k_k3[5]*((L*B)/AL)
		 + C_k_k3[6]*(AOD/pow(L,2));
		
		
        double k5 = C_k_k5[0] 
		 + C_k_k5[1]*(AL/(L*HC))
		 + C_k_k5[2]*(AL/AOD) 
		 + C_k_k5[3]*(AT/AL)
		 + C_k_k5[4]*(L/B)
		 + C_k_k5[5]*(AL/(L*B));

	printf("%.10f", k5); 
	    
        double *result;
        result = (double *)malloc(14 * sizeof(double));
        
        *(result+0) = x0;
        printf("%f", *(result+0));
        *(result+1) = x1;
        *(result+2) = x3;
        *(result+3) = x5;
        *(result+4) = y1;
        *(result+5) = y3;
        *(result+6) = y5;
        *(result+7) = n1;
        *(result+8) = n2;
        *(result+9) = n3;
        *(result+10) = k1;
        *(result+11) = k2;
        *(result+12) = k3;
        *(result+13) = k5;
        printf("%f", *(result+13));
        
        return result;
}
    else
        printf("Arguments must be three, type angles -h for help");
        return NULL;

}
