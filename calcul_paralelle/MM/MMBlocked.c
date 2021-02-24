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

#ifndef BLOCK_SIZE
   #define BLOCK_SIZE 20
#endif

double value (int i,
              int j)
{
return i * j * (double) (MATRIX_SIZE - 1) * MATRIX_SIZE / 2 +
           j * (double) (MATRIX_SIZE - 1) * MATRIX_SIZE * (2 * (MATRIX_SIZE - 1) + 1) / 6;
}

void main()
{
double **a, **b, **c ;
int i;
int j;
int k;
register int ii;
register int jj;
register int kk;
double startTime;
double stopTime;

assert( MATRIX_SIZE % BLOCK_SIZE == 0 /* PRE_CONDITION:  BLOCK_SIZE MUST BE A DIVIDER OF MATRIX_SIZE (TO AVOID CLEAN-UP CODE) */ );

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
   for ( j = 0; j < MATRIX_SIZE; j++ )
      c[i][j] = 0.0;
for ( i = 0; i < MATRIX_SIZE; i += BLOCK_SIZE )
   for ( j = 0; j < MATRIX_SIZE; j += BLOCK_SIZE )
      for ( k = 0; k < MATRIX_SIZE; k += BLOCK_SIZE )
         for ( ii = i; ii < i + BLOCK_SIZE; ii++ )
            for ( jj = j; jj  < j + BLOCK_SIZE; jj++ )
               for ( kk = k; kk < k + BLOCK_SIZE; kk++ )
                  c[ii][jj] += a[ii][kk] * b[kk][jj];
stopTime = dtime();
printf("Blocked (%d)\t%d\t%4.6f\n",
       BLOCK_SIZE,
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




