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

double value (int i,
              int j)
{
return i * j * (double) (MATRIX_SIZE - 1) * MATRIX_SIZE / 2 +
           j * (double) (MATRIX_SIZE - 1) * MATRIX_SIZE * (2 * (MATRIX_SIZE - 1) + 1) / 6;
}

void MatrixMultiplyAdd (double **a, /* a [MATRIX_SIZE] [MATRIX_SIZE] */
                        unsigned int aFirstRow,
                        unsigned int aLastRow,
                        unsigned int aFirstCol,
                        unsigned int aLastCol,
                        double **b, /* b [MATRIX_SIZE] [MATRIX_SIZE] */
                        unsigned int bFirstRow,
                        unsigned int bLastRow,
                        unsigned int bFirstCol,
                        unsigned int bLastCol,
                        double **c) /* c [MATRIX_SIZE] [MATRIX_SIZE] */
{
#ifdef PRE_CONDITIONS
assert( aFirstRow <= aLastRow );
assert( aFirstCol <= aLastCol );
assert( bFirstRow <= bLastRow );
assert( bFirstCol <= bLastCol );
assert( aLastCol - aFirstCol == bLastRow - bFirstRow );
#endif

/****
   With respect to MMRecursive1, we add a "terminal" case that avoids
   too many recursive calls at the bottom of the recursive tree.
 ****/
register unsigned int i;
register unsigned int j;
register unsigned int ka;
register unsigned int kb;
register unsigned int column;

if ( aLastRow - aFirstRow <= MIN_ROW_HEIGHT ||
     aLastCol - aFirstCol <= MIN_COLUMN_WIDTH ||
     bLastRow - bFirstRow <= MIN_ROW_HEIGHT ||
     bLastCol - bFirstCol <= MIN_COLUMN_WIDTH ||
     aLastRow - aFirstRow <= MIN_ROW_HEIGHT ||
     bLastCol - bFirstCol <= MIN_COLUMN_WIDTH)
   { /* matrices are small enough */
   for ( i = aFirstRow; i <= aLastRow; i++ )
      for ( j = bFirstCol; j <= bLastCol; j++ )
         for ( ka = aFirstCol, kb = bFirstRow;
               kb <= bLastRow;
               ka++, kb++ )
            c[i][j] += a[i][ka] * b[kb][j];
   }
else if ( aFirstRow == aLastRow &&
          bFirstCol == bLastCol )
   { /* a is a row matrix and b is a column matrix */
   for ( ka = aFirstCol, kb = bFirstRow;
         kb <= bLastRow;
         ka++, kb++ )
      for ( column = bFirstCol; column <= bLastCol; column++)
         c[aFirstRow][column] += a[aFirstRow][ka] * b[kb][column];
   }
else if ( aFirstRow == aLastRow )
   { /* a is a row matrix */
   /* const */ unsigned int bMiddleCol = (bFirstCol + bLastCol) / 2;

   /* multiply by first vertical half*/
   MatrixMultiplyAdd(a, aFirstRow, aFirstRow, aFirstCol, aLastCol,
                     b, bFirstRow, bLastRow, bFirstCol, bMiddleCol,
                     c);
   /* multiply by second vertical half*/
   MatrixMultiplyAdd(a, aFirstRow, aFirstRow, aFirstCol, aLastCol,
                     b, bFirstRow, bLastRow, bMiddleCol + 1, bLastCol,
                     c);
   }
else if ( bFirstCol == bLastCol )
   { /* b is a column matrix */
   /* const */ unsigned int aMiddleRow = (aFirstRow + aLastRow) / 2;

   /* first vertical half by column matrix */
   MatrixMultiplyAdd(a, aFirstRow, aMiddleRow, aFirstCol, aLastCol,
                     b, bFirstRow, bLastRow, bFirstCol, bFirstCol,
                     c);
   /* second vertical half by column matrix */
   MatrixMultiplyAdd(a, aMiddleRow + 1, aLastRow, aFirstCol, aLastCol,
                     b, bFirstRow, bLastRow, bFirstCol, bFirstCol,
                     c);
   }
else if ( aFirstCol == aLastCol )
   { /* a is a column matrix */
   #ifdef INVARIANTS
   assert( bFirstRow == bLastRow ); /* => b is a row matrix */
   #endif

   /* const */ unsigned int aMiddleRow = (aFirstRow + aLastRow) / 2;
               unsigned int bMiddleCol = (bFirstCol + bLastCol) / 2;

   /* first horizontal half by first vertical half*/
   MatrixMultiplyAdd(a, aFirstRow, aMiddleRow, aFirstCol, aFirstCol,
                     b, bFirstRow, bFirstRow, bFirstCol, bMiddleCol,
                     c);
   /* first horizontal half by second vertical half */
   MatrixMultiplyAdd(a, aFirstRow, aMiddleRow, aFirstCol, aFirstCol,
                     b, bFirstRow, bFirstRow, bMiddleCol + 1, bLastCol,
                     c);
   /* second horizontal half by first vertical half*/
   MatrixMultiplyAdd(a, aMiddleRow + 1, aLastRow, aFirstCol, aFirstCol,
                     b, bFirstRow, bFirstRow, bMiddleCol + 1, bLastCol,
                     c);
   /* second horizontal half by first vertical half */
   MatrixMultiplyAdd(a, aMiddleRow + 1, aLastRow, aFirstCol, aFirstCol,
                     b, bFirstRow, bFirstRow, bFirstCol, bMiddleCol,
                     c);
   }
else
   { /* general recursive decomposition */
   #ifdef INVARIANTS
   assert( aFirstRow < aLastRow );
   assert( aFirstCol <= aLastCol );
   assert( bFirstRow <= bLastRow );
   assert( bFirstCol < bLastCol );
   #endif

   /* const */ unsigned int aMiddleRow = (aFirstRow + aLastRow) / 2;
               unsigned int aMiddleCol = (aFirstCol + aLastCol) / 2;
               unsigned int bMiddleRow = (bFirstRow + bLastRow) / 2;
               unsigned int bMiddleCol = (bFirstCol + bLastCol) / 2;

   #ifdef INVARIANTS
   assert( aFirstRow <= aMiddleRow );
   assert( aMiddleRow < aLastRow );
   assert( aFirstCol <= aMiddleCol );
   assert( aMiddleCol < aLastCol );
   assert( bFirstRow <= bMiddleRow );
   assert( bMiddleRow < bLastRow );
   assert( bFirstCol <= bMiddleCol );
   assert( bMiddleCol < bLastCol );
   #endif

   /* first quadrant */
   /* c11 += a11 + b11 */
   MatrixMultiplyAdd(a, aFirstRow,      aMiddleRow, aFirstCol,      aMiddleCol,
                     b, bFirstRow,      bMiddleRow, bFirstCol,      bMiddleCol,
                     c);
   /* c11 += a12 + b21 */
   MatrixMultiplyAdd(a, aFirstRow,      aMiddleRow, aMiddleCol + 1, aLastCol,
                     b, bMiddleRow + 1, bLastRow,   bFirstCol,      bMiddleCol,
                     c);

   /* second quadrant */
   /* c21 += a22 + b21 */
   MatrixMultiplyAdd(a, aMiddleRow + 1, aLastRow,   aMiddleCol + 1, aLastCol,
                     b, bMiddleRow + 1, bLastRow,   bFirstCol,      bMiddleCol,
                     c);
   /* c21 += a21 + b11 */
   MatrixMultiplyAdd(a, aMiddleRow + 1, aLastRow,   aFirstCol,      aMiddleCol,
                     b, bFirstRow,      bMiddleRow, bFirstCol,      bMiddleCol,
                     c);

   /* fourth quadrant */
   /* c22 += a21 + b12 */
   MatrixMultiplyAdd(a, aMiddleRow + 1, aLastRow,   aFirstCol,      aMiddleCol,
                     b, bFirstRow,      bMiddleRow, bMiddleCol + 1, bLastCol,
                     c);
   /* c22 += a22 + b22 */
   MatrixMultiplyAdd(a, aMiddleRow + 1, aLastRow,   aMiddleCol + 1, aLastCol,
                     b, bMiddleRow + 1, bLastRow,   bMiddleCol + 1, bLastCol,
                     c);

   /* third quadrant */
   /* c12 += a12 + b22 */
   MatrixMultiplyAdd(a, aFirstRow,      aMiddleRow, aMiddleCol + 1, aLastCol,
                     b, bMiddleRow + 1, bLastRow,   bMiddleCol + 1, bLastCol,
                     c);
   /* c12 += a11 + b12 */
   MatrixMultiplyAdd(a, aFirstRow,      aMiddleRow, aFirstCol,      aMiddleCol,
                     b, bFirstRow,      bMiddleRow, bMiddleCol + 1, bLastCol,
                     c);
   }
}

void MatrixMultiply (double **a, /* a [MATRIX_SIZE] [MATRIX_SIZE] */
                     double **b, /* b [MATRIX_SIZE] [MATRIX_SIZE] */
                     double **c) /* c [MATRIX_SIZE] [MATRIX_SIZE] */
{
register unsigned int i;
register unsigned int j;

/* initialise result */
for ( i = 0; i < MATRIX_SIZE; i++ )
   for ( j = 0; j < MATRIX_SIZE; j++ )
      c[i][j] = 0.0;
MatrixMultiplyAdd(a, 0, MATRIX_SIZE - 1, 0, MATRIX_SIZE - 1,
                  b, 0, MATRIX_SIZE - 1, 0, MATRIX_SIZE - 1,
                  c);
}

void main ()
{
double **a, **b, **c ;
register unsigned int i;
register unsigned int j;
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
MatrixMultiply(a, b, c);
stopTime = dtime();
printf("Recursive rectangular (%d x %d)\t%d\t%4.6f\n",
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

