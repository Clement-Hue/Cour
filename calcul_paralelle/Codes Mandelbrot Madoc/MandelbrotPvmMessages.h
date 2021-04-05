#ifndef sum_messages
#define sum_messages

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "MandelbrotPvmConstants.h"

#include "pvm3.h"

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
void BroadcastParameters(unsigned int numberOfWorkers,
                         int workerTaskIDs[MAX_WORKERS],
                         int hauteur,
                         int largeur)
{
#ifdef PRE_CONDITIONS
    assert(numberOfWorkers <= MAX_WORKERS);
#endif

#if TRACE > 0
    printf("BroadcastParameters(numberOfWorkers = %u , largeur = %d, hauteur = %d", numberOfWorkers, hauteur, largeur);
#endif

    pvm_initsend(PvmDataDefault);
    pvm_pkuint(&numberOfWorkers, 1, 1); // (---, 1, 1) means scalar
    pvm_pkint(workerTaskIDs, numberOfWorkers, 1);
    pvm_pkint(&hauteur, 1, 1);
    pvm_pkint(&largeur, 1, 1);
    pvm_mcast(workerTaskIDs, numberOfWorkers, PARAMETERS_TAG);
}

void ReceiveParameters(unsigned int &numberOfWorkers,
                       int workerTaskIDs[MAX_WORKERS],
                       int hauteur,
                       int largeur)
{
    pvm_recv(-1, PARAMETERS_TAG); // (-1, ---) means from any task
    pvm_upkuint(&numberOfWorkers, 1, 1);
    assert(numberOfWorkers <= MAX_WORKERS);
    pvm_upkint(workerTaskIDs, numberOfWorkers, 1);
    pvm_upkint(&hauteur, 1, 1);
    pvm_upkint(&largeur, 1, 1);
    //pvm_upkfloat(data, dataSize, 1);

#if TRACE > 0
    printf("ReceivedParamters(numberOfWorkers = %u , largeur = %d, hauteur = %d", numberOfWorkers, hauteur, largeur);
#endif
}

/*****************************************************************/
/* RESULTS MESSAGES                                              */
/*****************************************************************/

void SendResult(int workerID,
                unsigned int begin,
                unsigned int end,
                float result)
//
// Depending on its index, a worker is in charge of summing up only a sub-interval of the array of values.
// It is this partial sum that is send back to the farmer, which is, implicitly, the parent process.
//
{
#if TRACE > 0
    printf("SendResult(workerID = %d, begin = %u, end = %u, result = %f)\n", workerID, begin, end, result);
#endif

    pvm_initsend(PvmDataDefault);
    pvm_pkint(&workerID, 1, 1);
    pvm_pkuint(&begin, 1, 1);
    pvm_pkuint(&end, 1, 1);
    pvm_pkfloat(&result, 1, 1);
    pvm_send(pvm_parent(), RESULT_TAG);
}

void ReceiveResult(int &workerID,
                   unsigned int &begin,
                   unsigned int &end,
                   float &result)
{
    pvm_recv(-1, RESULT_TAG);
    pvm_upkint(&workerID, 1, 1);
    pvm_upkuint(&begin, 1, 1);
    pvm_upkuint(&end, 1, 1);
    pvm_upkfloat(&result, 1, 1);

#if TRACE > 0
    printf("ReceiveResult(workerID = %d, begin = %u, end = %u, result = %f)\n", workerID, begin, end, result);
#endif
}

#endif
