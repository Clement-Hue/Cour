// (c) February 25, 2021, José Martinez, Polytech Nantes
//
// The use of this library is not authorised outside the Polytechnic School of the University of Nantes.
//
// Largely adapted from the sum_master / sum_slave example of the PVM library.
// 

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "pvm3.h"

#include "sum_constants.h"
#include "sum_messages.h"

/***************************************************************************/
/* FARM MANAGEMENT                                                         */
/***************************************************************************/

void StartFarm (unsigned int   numberOfWorkers,
                int          & farmerID,
                int            workerTaskIDs [MAX_WORKERS])
   //
   // Starting the farm-of-workers parallel architecture.
   // It consists of a single farmer and, preferably, at least two workers, though a single one is allowed.
   //
   // Should there be an issue when building the farm-of-workers, the whole program would gracefully abort.
   //
{
#ifdef PRE_CONDITIONS
assert( 1 < numberOfWorkers                );
assert(     numberOfWorkers <= MAX_WORKERS );
#endif

farmerID = pvm_mytid(); // Starting PVM by enrolling the farmer

const int numberOfStartedTasks = pvm_spawn(WORKER_PROGRAM,
                                           (char * *) NULL, // no command-line argument
                                           PvmTaskDefault + PvmTaskTrace,
                                           (char *) "", // no specific location on which to start the tasks
                                           numberOfWorkers,
                                           workerTaskIDs); // Starting the workers at any place
if ( numberOfStartedTasks < numberOfWorkers )
   { // ABNORMAL TERMINATION
   printf("%d started tasks out of %d.\n",
          numberOfStartedTasks, numberOfWorkers);
   printf("Aborting the started workers...\n");
   for ( unsigned int i = 0; i < numberOfStartedTasks; i++ )
      pvm_kill(workerTaskIDs[i]);
   printf("Error codes for the erroneous ones are:\n");
   for ( unsigned int i = numberOfStartedTasks; i < numberOfWorkers; i++ )
      printf("   %d.  tid:  %d\n", i, workerTaskIDs[i]);
   pvm_exit();
   exit(1);
   }
}

void EndFarm (unsigned int   numberOfWorkers,
              int            workerTaskIDs [MAX_WORKERS])
   //
   // Ending the farm.
   //
{
for ( unsigned int i = 0; i < numberOfWorkers; i++ )
   pvm_kill(workerTaskIDs[i]);
pvm_exit();
}

/***************************************************************************/
/* SIMPLE FARM-OF-WORKERS APPLICATION                                      */
/***************************************************************************/

int main ()
   //
   // A uniformly initialised array is sent to a number of workers.
   // Depending on their indices, which have also been sent to the workers,
   // they sum up a disjoint interval of the values in the array.
   // The farmer gathers all these partial sums and finishes the whole sum.
   //
   // The number of workers and the size of the array of values are limited
   // by respective maximal sizes.
   //
{
#ifdef PRE_CONDITIONS
assert( DATA_SIZE <= MAX_DATA_SIZE );
assert( NUMBER_OF_WORKERS <= MAX_WORKERS );
#endif

/* const */ float data [MAX_DATA_SIZE];

for( unsigned int i = 0; i < DATA_SIZE; i++ )
   data[i] = DATA_VALUE;

int farmerID;
int workerTaskIDs [MAX_WORKERS];

StartFarm(NUMBER_OF_WORKERS, farmerID, workerTaskIDs);
BroadcastParameters(NUMBER_OF_WORKERS, workerTaskIDs, DATA_SIZE, data);

float result;

result = 0.0;
for ( unsigned int i = 0; i < NUMBER_OF_WORKERS; i++ )
   {
   /* const */ int          workerID;
   /* const */ unsigned int begin;
   /* const */ unsigned int end;
   /* const */ float        partialSum;

   ReceiveResult(workerID, begin, end, partialSum);
   result += partialSum;
   }

EndFarm(NUMBER_OF_WORKERS, workerTaskIDs);

#ifdef TRACE
printf("Sum is %f.  It should be %f.\n", result, DATA_SIZE * DATA_VALUE);
#endif

#ifdef POST_CONDITIONS
assert( result == DATA_SIZE * DATA_VALUE);
#endif

return 0;
}

