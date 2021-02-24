/***************************************************************************/
/* (c) 2016, José Martinez, Polytech Nantes                                */
/***************************************************************************/
/* This program cannot be used, copied, stored, transmitted, etc., outside */
/* the Polytechnic School of the University of Nantes without the prior    */
/* explicit and written authorisation of the author and/or the School.     */
/***************************************************************************/

/* CAUTION.  This "false" matrix multiplication program executes (1 FMA + 1 ADD + 1 MUL) * MATRIX_SIZE^2 floating-point operations.
             In contrast, all the previous programs execute only 1 FMA * MATRIX_SIZE^2 floating-point operations since initialisation time is not measured.
             This has to be taken into account when trying to compare the programs, especially when relying on flops. */

#include "timer.h"
#include <stdio.h>

/* Initialise */

double a (double i,
          double k)
{
return i + k;
}

double b (double k,
          double j)
{
return k * j;
}

/* False Matrix multiply */

void main ()
{
register int i;
register int j;
register int k;
double startTime;
double stopTime;
register double gsum;

startTime = dtime();
gsum = 0.0;
for ( i = 0; i < MATRIX_SIZE; i++ )
   for ( j  = 0; j < MATRIX_SIZE; j++ )
      {
      register double sum1;
      register double sum2;
      register double sum3;
      register double sum4;

      sum1 = sum2 = sum3 = sum4 = 0.0;
      for( k = 0; k < MATRIX_SIZE; k += 4 )
         {
         sum1 += a(i, k)     * b(k,     j);
         sum2 += a(i, k + 1) * b(k + 1, j);
         sum3 += a(i, k + 2) * b(k + 2, j);
         sum4 += a(i, k + 3) * b(k + 3, j);
         }
      gsum = sum1 + sum2 + sum3 + sum4;
      }
stopTime = dtime();
printf("Sustained performances (%f)\t%d\t%4.6f\n",
       gsum,
       MATRIX_SIZE,
       stopTime - startTime);
}

