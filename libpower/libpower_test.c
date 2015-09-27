#include <stdio.h>
#include <stdlib.h>
#include "libpower.h"

void main()
{ 
    float resistance = 350.0;
    float current = 0.45;
    float volt = 12.0;
    float powerR;
    float powerI;
    /* Test that calc_power_r works */
    powerR = calc_power_r(volt, resistance);
    powerI = calc_power_i(volt, current);

    printf("The power calculated from volt and resistance is: %.2f\n", powerR);
    printf("The power calculated from volt and current is: %.2f\n", powerI);
}

