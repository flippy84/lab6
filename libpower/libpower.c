/* Liselott Kronquist
 * 2015-09-30
 *
 * Exercise 6:
 * libpower.c: this file contains two functions, one for calculating the power 
 * given the resistance and one for calculating the power given the current. 
 */
#include "libpower.h"

float calc_power_r(float volt, float resistance)
{
    float power = 0.0;
    
    if (resistance <= 0)
    {
        printf("Resistance needs to be greater than 0");
    }
    else power = volt * volt / resistance;

    return power;
}

float calc_power_i(float volt, float current)
{
    float power;
    power = volt * current;
    return power;
}
