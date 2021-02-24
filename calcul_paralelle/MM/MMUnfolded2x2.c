/***************************************************************************/
/* (c) 2009, José Martinez, Polytech Nantes                                */
/***************************************************************************/
/* This program cannot be used, copied, stored, transmitted, etc., outside */
/* the Polytechnic School of the University of Nantes without the prior    */
/* explicit and written authorisation of the author and/or the School.     */
/***************************************************************************/

#include <assert.h>
#include "timer.h"
#include <stdio.h>
#include "matrixalloc.h"

double value (int i,
              int j)
{
return i * j * (double) (MATRIX_SIZE - 1) * MATRIX_SIZE / 2 +
           j * (double) (MATRIX_SIZE - 1) * MATRIX_SIZE * (2 * (MATRIX_SIZE - 1) + 1) / 6;
}

void main ()
{
double **a, **b, **c;
register int i;
register int j;
register int k;
double startTime;
double stopTime;

assert( MATRIX_SIZE % 2 == 0 /* PRE_CONDITION:  MATRIX_SIZE MUST BE AN EVEN NUMBER */ );

/* Array allocation */
a = matrixalloc(MATRIX_SIZE, MATRIX_SIZE);
b = matrixalloc(MATRIX_SIZE, MATRIX_SIZE);
c = matrixalloc(MATRIX_SIZE, MATRIX_SIZE);

/* Initialise */
for ( i = 0; i < MATRIX_SIZE; i++ )
   for ( j = 0; j < MATRIX_SIZE; j++ )
      {
      a[i][j] = i + j;
      b[i][j] = i * j;
      }

/* Matrix multiply */
startTime = dtime();
for ( i = 0; i < MATRIX_SIZE; i += 2 )
   for( j = 0; j < MATRIX_SIZE; j += 2 )
      {
      register double s00;
      register double s01;
      register double s10;
      register double s11; 

      s00 = s01 = s10 = s11 = 0.0; 
      for( k = 0; k < MATRIX_SIZE; k++ )
         {
         s00 += a[i]    [k] * b[k][j];
         s01 += a[i]    [k] * b[k][j + 1];
         s10 += a[i + 1][k] * b[k][j];
         s11 += a[i + 1][k] * b[k][j + 1];
         }
      c[i]    [j]     = s00;
      c[i]    [j + 1] = s01;
      c[i + 1][j]     = s10;
      c[i + 1][j + 1] = s11;
      }
stopTime = dtime();
printf("Unfolded subblock 2x2\t%d\t%4.6f\n",
       MATRIX_SIZE,
       stopTime - startTime);

/* Verify */
for ( i = 0; i < MATRIX_SIZE; i++ )
   for ( j = 0; j < MATRIX_SIZE; j++ )
      if ( c[i][j] != value(i, j) )
         {
         printf("%f vs %f\n", c[i][j], value(i, j));
         assert( c[i][j] == value(i, j) );
         }
}

