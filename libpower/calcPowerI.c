/* Liselott Kronquist
 * 2015-09-27
 * Exercise 6:
 * calc_power_i: calculate the power, given volatage and current, in a serial connection
 */

#include <stdlib.h>
#include "math.h"
#include "float.h"

float calc_power_i(float volt, float current)
{
    float power;
    power = volt * current;
    return power;
}
