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

void main(int argc, char *argv[])
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
    pintf("Please enter the power supply in voltage\n");
    scanf("%f", &volt);
    printf("Please enter the current.\n");
    scanf("%f", &current);
    printf("Please enter the number of resistor.\n");
    scanf("%d", &num_resistors);

    /* Allocate memory for the resistances */
    float* resistances = malloc(sizeof(float) * num_resistors);

    for (i = 1; i < num_resistors + 1, i++)
    {
        printf("Please enter resistance for component %d\n", i);
        scanf("%d", &resistances[i-1]);
    }

    /* Calculate the replacement resistance and the different powers. */
    orig_resistance = calc_resistance(num_resistors, conn, resistances);
    power_r = calc_power_r(volt, orig_Resistance);
    power_i = calc_power_i(volt, current);

    /* Calculate the three resistances from the E12 series that are needed to 
       replace the orig_resistance. */
    num_e12_res = e_resistance(orig_resistance, res_array);

    /* The results from all our efforts */
    printf("The resulting resistance is: %12.1f\n", orig_resistance);
    printf("The power when using curret is: %12.2f\n", power_i);
    printf("The power when using resistance is: %12.2f\n", power_r);
    printf("The resistances from the E12 series are: %10.1f, %10.1f, %10.1f\n", res_array[0], res_array[1], res_array[2]);

    /* Free the memory allocate by mallo before. */
    free(resistances);
    free(res_array);

}
