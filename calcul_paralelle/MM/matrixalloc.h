#include <stdlib.h>

double ** matrixalloc (unsigned int dim1,
                       unsigned int dim2)
{ 
#ifdef PRE_CONDITIONS
assert( dim1 > 0 );
assert( dim2 > 0 );
#endif

double ** result = (double **) malloc (dim1 * sizeof(double *));
    
unsigned int i;

for ( i = 0; i < dim1; i++ )
   result[i] = (double *) malloc (dim2 * sizeof(double));

return result;
}

