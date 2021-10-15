// (c) February 25, 2021, José Martinez, Polytech Nantes
//
// The use of this library is not authorised outside the Polytechnic School of the University of Nantes.
//

#include <assert.h>
#include <stdio.h>
#include "pvm3.h"

#include "sum_constants.h"
#include "sum_messages.h"

void WorkerInterval(int workerID,
                    unsigned int numberOfWorkers,
                    int workerTaskIDs[MAX_WORKERS],
                    unsigned int dataSize,
                    unsigned int &begin,
                    unsigned int &end)
{
#ifdef PRE_CONDITIONS
   bool exists;

   exists = false;
   for (unsigned int i = 0; i < numberOfWorkers; i++)
      if (workerTaskIDs[i] == workerID)
      {
         exists = true;
         break;
      }
   assert(exists);
#endif

   const unsigned int width = dataSize / numberOfWorkers;

#ifdef INVARIANTS
   assert(width > 0);
#endif

   for (unsigned int i = 0; i < numberOfWorkers; i++)
      if (workerTaskIDs[i] == workerID)
      {
#ifdef TRACE
         printf("I am the worker number %d\n", i);
#endif

         begin = width * i;
         if (i == numberOfWorkers - 1)
            end = dataSize;
         else
            end = begin + width;

         break;
      }

#ifdef POST_CONDITIONS
   assert(begin <= end);
   assert(end <= MAX_DATA_SIZE);
#endif
}

float PartialSum(unsigned int dataSize,
                 float data[MAX_DATA_SIZE],
                 unsigned int begin,
                 unsigned int end)
//
// Given an array of values to sum up,
// this function computes a partial sum,
// starting at a beginning index, *inclusive*,
// and ending at en ending index, *exclusive*.
//
// These indices must be well-ordered.
// The ending index cannot be larger than the actual size of the array of values.
// This size itself cannot be larger than the maximal size.
//
{
#ifdef PRE_CONDITIONS
   assert(dataSize <= MAX_DATA_SIZE);
   assert(begin <= end);
   assert(end <= dataSize);
#endif

   float sum;

   sum = 0.0;
   for (unsigned int i = begin; i < end; i++)
   {
#ifdef INVARIANTS
      assert(data[i] == DATA_VALUE);
#endif

      sum += data[i];
   }

#ifdef TRACE
   printf("Sum from %d to %d is %f\n", begin, end, sum);
#endif

   return sum;
}

int main()
{
   const int workerID = pvm_mytid();

   assert(pvm_parent() != PvmNoParent);

   /* const */ unsigned int numberOfWorkers;
   /* const */ int workerTaskIDs[MAX_WORKERS];
   /* const */ unsigned int dataSize;
   /* const */ float data[MAX_DATA_SIZE];

   ReceiveParameters(numberOfWorkers, workerTaskIDs, dataSize, data);

   /* const */ unsigned int begin;
   /* const */ unsigned int end;

   WorkerInterval(workerID, numberOfWorkers, workerTaskIDs, dataSize, begin, end);

   const float sum = PartialSum(dataSize, data, begin, end);

   SendResult(workerID, begin, end, sum);

   pvm_exit();

   return 0;
}
