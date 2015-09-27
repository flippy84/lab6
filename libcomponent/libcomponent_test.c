/* Erik Ekström
 * erek0016@student.umu.se
 * 2015-09-27
 *
 * Uppgift 6: libcomponent.so
 */

#include <stdio.h>
#include <stdlib.h>
#include "libcomponent.h"

#define MAX_R         100000
                      
int main(int argc, char * argv[]) {
  int N = (argc > 1) ? atoi(argv[1]) : 5;


  float *res_array = (float*) malloc(3*sizeof(float)); /* Result array */
  float *rs = (float*) malloc(N*sizeof(float));       /* Resistor values */
  
  int i;
  for(i = 0; i < N; ++i) {
    rs[i] = ((float) MAX_R / RAND_MAX) * rand();
  }


  for(i = 0; i < N; ++i) {
    int count = e_resistance(rs[i], res_array);
    float e_res = res_array[0] + res_array[1] + res_array[2];
    switch(count) {
    case 0:
    case 1:
      printf("%12.3f approximated by: %10.1f (= %10.1f, error = %7.3f)\n",
	     rs[i], res_array[0], e_res, rs[i] - e_res);
       break;
    case 2:
      printf("%12.3f approximated by: %10.1f + %10.1f (= %10.1f, error = %7.3f)\n",
	     rs[i], res_array[0], res_array[1], e_res, rs[i] - e_res);
      break;
    default:
      printf("%12.3f approximated by: %10.1f + %10.1f + %10.1f (= %10.1f, error = %7.3f)\n",
	     rs[i], res_array[0], res_array[1], res_array[2],
	     e_res, rs[i] - e_res);
      break;      
    }   
  }
  
  free(rs);
  rs = NULL;
  free(res_array);
  res_array = NULL;

  return 0;
}
