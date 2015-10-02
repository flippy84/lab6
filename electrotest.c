/* Erik Ekstrom
 * Andreas Carlsson 
 * Liselott Kronquist
 * 
 * 2015-09-28
 * Exercise 6
 * 
 * electrotest: main program for testing the libraries 
 */

#include <stdio.h>
#include <stdlib.h>
#include "libresistance.h"
#include "libcomponent.h"
#include "libpower.h"

int main()
{
    float volt;
    int num_resistors;
    float current;
    char conn;
    float orig_resistance;
    int num_e12_res;
    int i;
    float power_i;
    float power_r;
    float* res_array = (float*)malloc(sizeof(float) * 3); 

    /* Ask for values and read and save them */
    printf("Please enter the power supply voltage (V): ");
    scanf("%f", &volt);
    while(getchar() != '\n');
    
    do{
      printf("Please enter connection mode [S | P]: ");
      scanf("%c", &conn);
      getc(stdin);
    } while (conn != 'S' && conn != 'P');
    
    printf("Please enter the current (A): ");
    scanf("%f", &current);
    printf("Please enter the number of resistor: ");
    scanf("%d", &num_resistors);

    /* Allocate memory for the resistances */
    float* resistances = malloc(sizeof(float) * num_resistors);

    for (i = 1; i < num_resistors + 1; i++)
    {
        printf("Please enter resistance (Ohm) for component %d: ", i);
        scanf("%f", &resistances[i-1]);
    }

    /* Calculate the replacement resistance and the different powers. */
    orig_resistance = calc_resistance(num_resistors, conn, resistances);
    power_r = calc_power_r(volt, orig_resistance);
    power_i = calc_power_i(volt, current);

    /* Calculate the three resistances from the E12 series that are needed to 
       replace the orig_resistance. */
    num_e12_res = e_resistance(orig_resistance, res_array);

    /* The results from all our efforts */
    printf("The resulting resistance is:            %22.1f Ohm\n",
	   orig_resistance);
    printf("The power when using curret is:         %22.2f Ohm\n", power_i);
    printf("The power when using resistance is:     %22.2f Ohm\n", power_r);

    if(num_e12_res > 0)
    {
      printf("The replacment resistances from the E12 series are: %10.1f",
	     res_array[0]);
      if(num_e12_res > 1)
	printf(", %10.1f", res_array[1]);
      if(num_e12_res > 2)
	printf(", %10.1f", res_array[2]);
      printf(" Ohm\n");      
    }

    else
    {
      printf("%10.1f has no replacment resistances in the E12.",
	     orig_resistance);
    }
    
    /* Free the memory allocate by mallo before. */
    free(resistances);
    free(res_array);

    return 0;
}
