#ifndef sum_messages
#define sum_messages

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "pvm3.h"

#include "sum_constants.h"

/*****************************************************************/
/* PARAMETERS MESSAGES                                           */
/*****************************************************************/
/* It is wise to pair up sent and received messages              */
/* in order to avoid common mistakes                             */
/* related to the order and/or the type                          */
/* of the transmitted fields.                                    */
/*                                                               */
/* Furthermore, by creating specific functions,                  */
/* the structure of the message is made explicit                 */
/* by the signature of the procedures.                           */
/*****************************************************************/

/*******************************************************************/
/* GLOBAL PARAMETERS                                               */
/*******************************************************************/

void BroadcastParameters (unsigned int numberOfWorkers,
                          int          workerTaskIDs [MAX_WORKERS],
                          unsigned int dataSize,
                          float        data          [MAX_DATA_SIZE])
   //
   // After initialising a farm-of-workers architecture,
   // the main program is going to send two arrays to all the workers.
   // The first one is the array of all the workers.
   // The second one is the array of values to sum up.
   //
{
#ifdef PRE_CONDITIONS
assert( numberOfWorkers <= MAX_WORKERS );
assert( dataSize <= MAX_DATA_SIZE );
#endif

#if TRACE > 0
printf("BroadcastParameters(numberOfWorkers = %u , workerTaskIDs = ---, dataSize = %u, data = ---)\n", numberOfWorkers, dataSize);
#endif

pvm_initsend(PvmDataDefault);
pvm_pkuint(& numberOfWorkers, 1, 1); // (---, 1, 1) means scalar
pvm_pkint(workerTaskIDs, numberOfWorkers, 1);
pvm_pkuint(& dataSize, 1, 1);
pvm_pkfloat(data, dataSize, 1);
pvm_mcast(workerTaskIDs, numberOfWorkers, PARAMETERS_TAG);
}

void ReceiveParameters (unsigned int & numberOfWorkers,
                        int            workerTaskIDs [MAX_WORKERS],
                        unsigned int & dataSize,
                        float          data [MAX_DATA_SIZE])
{
pvm_recv(-1, PARAMETERS_TAG); // (-1, ---) means from any task
pvm_upkuint(& numberOfWorkers, 1, 1);
assert( numberOfWorkers <= MAX_WORKERS );
pvm_upkint(workerTaskIDs, numberOfWorkers, 1);
pvm_upkuint(& dataSize, 1, 1);
pvm_upkfloat(data, dataSize, 1);

#ifdef INVARIANTS
assert( dataSize == DATA_SIZE );
#endif

#if TRACE > 0
printf("ReceiveParameters(numberOfWorkers = %u , workerTaskIDs = ---, dataSize = %u, data = ---)\n", numberOfWorkers, dataSize);
#endif
}

/*****************************************************************/
/* RESULTS MESSAGES                                              */
/*****************************************************************/

void SendResult (int          workerID,
                 unsigned int begin,
                 unsigned int end,
                 float        result)
   //
   // Depending on its index, a worker is in charge of summing up only a sub-interval of the array of values.
   // It is this partial sum that is send back to the farmer, which is, implicitly, the parent process.
   //
{
#if TRACE > 0
printf("SendResult(workerID = %d, begin = %u, end = %u, result = %f)\n", workerID, begin, end, result);
#endif

pvm_initsend(PvmDataDefault);
pvm_pkint(& workerID, 1, 1);
pvm_pkuint(& begin, 1, 1);
pvm_pkuint(& end, 1, 1);
pvm_pkfloat(& result, 1, 1);
pvm_send(pvm_parent(), RESULT_TAG);
}

void ReceiveResult (int          & workerID,
                    unsigned int & begin,
                    unsigned int & end,
                    float        & result)
{
pvm_recv(-1, RESULT_TAG);
pvm_upkint(& workerID, 1, 1);
pvm_upkuint(& begin, 1, 1);
pvm_upkuint(& end, 1, 1);
pvm_upkfloat(& result, 1, 1);

#if TRACE > 0
printf("ReceiveResult(workerID = %d, begin = %u, end = %u, result = %f)\n", workerID, begin, end, result);
#endif
}

#endif

