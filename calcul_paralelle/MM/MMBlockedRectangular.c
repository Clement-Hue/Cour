/***************************************************************************/
/* (c) 2016, José Martinez, Polytech Nantes                                */
/***************************************************************************/
/* This program cannot be used, copied, stored, transmitted, etc., outside */
/* the Polytechnic School of the University of Nantes without the prior    */
/* explicit and written authorisation of the author and/or the School.     */
/***************************************************************************/

#include <assert.h>
#include "timer.h"
#include <stdio.h>
#include "matrixalloc.h"

#ifndef MIN_COLUMN_WIDTH
   #define MIN_COLUMN_WIDTH 8
#endif

#ifndef MIN_ROW_HEIGHT
   #define MIN_ROW_HEIGHT 4
#endif

#define min(x, y) (((x) < (y)) ? (x) : (y))

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

assert( MATRIX_SIZE % MIN_COLUMN_WIDTH == 0 /* PRE_CONDITION:  MIN_COLUMN_WIDTH MUST BE A DIVIDER OF MATRIX_SIZE (TO AVOID CLEAN-UP CODE) */ );
assert( MATRIX_SIZE % MIN_ROW_HEIGHT == 0 /* PRE_CONDITION:  MIN_ROW_HEIGHT MUST BE A DIVIDER OF MATRIX_SIZE (TO AVOID CLEAN-UP CODE) */ );

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
for ( i = 0; i < MATRIX_SIZE; i += MIN_ROW_HEIGHT )
   for ( j = 0; j < MATRIX_SIZE; j += MIN_COLUMN_WIDTH )
      for ( k = 0; k < MATRIX_SIZE; k += min(MIN_ROW_HEIGHT, MIN_COLUMN_WIDTH) )
         for ( ii = i; ii < i + MIN_ROW_HEIGHT; ii++ )
            for ( jj = j; jj  < j + MIN_COLUMN_WIDTH; jj++ )
               for ( kk = k; kk < k + min(MIN_ROW_HEIGHT, MIN_COLUMN_WIDTH); kk++ )
                  c[ii][jj] += a[ii][kk] * b[kk][jj];
stopTime = dtime();
printf("BlockedRectangular (%d x %d)\t%d\t%4.6f\n",
       MIN_ROW_HEIGHT,
       MIN_COLUMN_WIDTH,
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




