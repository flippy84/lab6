#include <stdio.h>
#include "libresistance.h"

void print_values(float*, int);

int main(int argc, char* argv[])
{
    float resistors[] = {10000, 10000, 5000, 2500, 1250};

    for(int i = 1; i < 5; i++)
    {
        printf("Värdena ");
        print_values(resistors, i + 1);
        printf("I serie: %.0f\n", calc_resistance(i + 1, 'S', resistors));        
        printf("Parallellt: %.0f\n\n", calc_resistance(i + 1, 'P', resistors));
    }
}

void print_values(float* values, int count)
{
    for(int i = 0; i < count; i++)
    {
        printf("%.0f%s", values[i], i < (count - 1) ? ", " : ": \n");
    }
}
