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
double **a, **b, **c ;
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
      c[i][j] = 0.0;
for ( i = 0; i < MATRIX_SIZE; i++ )
   for ( k = 0; k < MATRIX_SIZE; k++ )
      {
      register double aik;

      aik = a[i][k];
      for ( j = 0; j < MATRIX_SIZE; j++ )
         c[i][j] += aik * b[k][j];
      }
stopTime = dtime();
printf("Interchange\t%d\t%4.6f\n",
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
