/* Liselott Kronquist
 * 2015-09-27
 *
 * Exercise 6:
 * calc_power_r: calculate the power, given voltage and resistance 
 */

#include "math.h"
#include "float.h"

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
