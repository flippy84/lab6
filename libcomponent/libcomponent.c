/* Erik Ekström
 * erek0016@student.umu.se
 * 2015-09-27
 *
 * Uppgift 6: libcomponent.so
 * 
 * int count = e_resistance(float orig_resistance, float *res_array );
 * En funktion som beräknar vilka tre seriekopplade resistorer i E12-serien
 * som närmast ersätter den resistans som skickas med.
 *
 *   orig_resistance är ersättningsresistansen.
 *   res_array är en pekare till en array med 3 resistorer som ska fyllas
 *     med värden ur E12-serien.
 *   count är hur många resistorer ur E12-serien som behövdes för att ersätta
 *    orig_resistance. Om inte alla 3 komponenterna behövs ska de som inte
 *    används fyllas med värdet 0. count kan anta värde mellan 0 och 3
 *
 */

#include <math.h>
#include <float.h>
#include "libcomponent.h"

static const int E12[] = {   8200000,   6800000,   5600000,   4700000, 
			     3900000,   3300000,   2700000,   2200000, 
			     1800000,   1500000,   1200000,   1000000, 
			     820000,    680000,    560000,    470000, 
			     390000,    330000,    270000,    220000, 
			     180000,    150000,    120000,    100000, 
			     82000,     68000,     56000,     47000, 
			     39000,     33000,     27000,     22000, 
			     18000,     15000,     12000,     10000, 
			     8200,      6800,      5600,      4700, 
			     3900,      3300,      2700,      2200, 
			     1800,      1500,      1200,      1000, 
			     820,       680,       560,       470, 
			     390,       330,       270,       220, 
			     180,       150,       120,       100, 
			     82,        68,        56,        47, 
			     39,        33,        27,        22, 
			     18,        15,        12,        10,
			     0 /* nil-resistor */ };

static const int RS = sizeof(E12)/sizeof(int); /* Num of resistor values */

int e_resistance(float orig_resistance, float *res_array ) {
  int i, j, k;
  float e_min = FLT_MAX;

  if(orig_resistance <= 0.0) {
    res_array[0] = 0.0;
    res_array[1] = 0.0;
    res_array[2] = 0.0;
    return 0;
  }

  /* All values may not be zero */
  for(i = 0; i < RS-1; ++i) {
    for(j = i; j < RS; ++j) {
      for(k = j; k < RS; ++k) {
	float e = fabs(orig_resistance - (E12[i] + E12[j] + E12[k]));

	if(e < e_min) {
	  e_min = e;
	  res_array[0] = E12[i];
	  res_array[1] = E12[j];
	  res_array[2] = E12[k];
	}

	if(e_min == 0.0) {
	  return (res_array[0] > 0) + (res_array[1] > 0) + (res_array[2] > 0);
	}
      }
    }
  }

  return (res_array[0] > 0) + (res_array[1] > 0) + (res_array[2] > 0);
}
