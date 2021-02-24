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
for ( i = 0; i < MATRIX_SIZE; i++ )
   for( j = 0; j < MATRIX_SIZE; j++ )
      {
      register double sum1;
      register double sum2;
      register double sum3;
      register double sum4;

      sum1 = sum2 = sum3 = sum4 = 0.0;
      for( k = 0; k < MATRIX_SIZE; k += 4 )
         {
         sum1 += a[i][k]     * b[k]    [j];
         sum2 += a[i][k + 1] * b[k + 1][j];
         sum3 += a[i][k + 2] * b[k + 2][j];
         sum4 += a[i][k + 3] * b[k + 3][j];
         }
      c[i][j] = sum1 + sum2 + sum3 + sum4;
      }
stopTime = dtime();
printf("Unfolded (4)\t%d\t%4.6f\n",
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
