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
                         unsigned int hauteur,
                         int largeur,
                         double x0, double y0, double dx, double dy,
                         unsigned long n_max)
{
#ifdef PRE_CONDITIONS
    assert(numberOfWorkers <= MAX_WORKERS);
#endif

#if TRACE > 0
    printf("BroadcastParameters(numberOfWorkers = %u , largeur = %d, hauteur = %d", numberOfWorkers, largeur, hauteur);
#endif

    pvm_initsend(PvmDataDefault);
    pvm_pkuint(&numberOfWorkers, 1, 1); // (---, 1, 1) means scalar
    pvm_pkint(workerTaskIDs, numberOfWorkers, 1);
    pvm_pkuint(&hauteur, 1, 1);
    pvm_pkint(&largeur, 1, 1);
    pvm_pkdouble(&x0, 1, 1);
    pvm_pkdouble(&y0, 1, 1);
    pvm_pkdouble(&dx, 1, 1);
    pvm_pkdouble(&dy, 1, 1);
    pvm_pkulong(&n_max, 1, 1);
    pvm_mcast(workerTaskIDs, numberOfWorkers, PARAMETERS_TAG);
}

void ReceiveParameters(unsigned int &numberOfWorkers,
                       int workerTaskIDs[MAX_WORKERS],
                       unsigned int &hauteur,
                       int &largeur,
                       double &x0, double &y0, double &dx, double &dy,
                       unsigned long &n_max)
{
    pvm_recv(-1, PARAMETERS_TAG); // (-1, ---) means from any task
    pvm_upkuint(&numberOfWorkers, 1, 1);
    assert(numberOfWorkers <= MAX_WORKERS);
    pvm_upkint(workerTaskIDs, numberOfWorkers, 1);
    pvm_upkuint(&hauteur, 1, 1);
    pvm_upkint(&largeur, 1, 1);
    pvm_upkdouble(&x0, 1, 1);
    pvm_upkdouble(&y0, 1, 1);
    pvm_upkdouble(&dx, 1, 1);
    pvm_upkdouble(&dy, 1, 1);
    pvm_upkulong(&n_max, 1, 1);

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
                const int SIZE,
                unsigned short *rouge, unsigned short *vert, unsigned short *bleu)
//
// Depending on its index, a worker is in charge of summing up only a sub-interval of the array of values.
// It is this partial sum that is send back to the farmer, which is, implicitly, the parent process.
//
{
#if TRACE > 0
    printf("SendResult(workerID = %d, begin = %u, end = %u \n", workerID, begin, end);
#endif
    pvm_initsend(PvmDataDefault);
    pvm_pkint(&workerID, 1, 1);
    pvm_pkuint(&begin, 1, 1);
    pvm_pkuint(&end, 1, 1);
    pvm_pkushort(rouge, SIZE, 1);
    pvm_pkushort(vert, SIZE, 1);
    pvm_pkushort(bleu, SIZE, 1);
    pvm_send(pvm_parent(), RESULT_TAG);
}

void ReceiveResult(int &workerID,
                   unsigned int &begin,
                   unsigned int &end,
                   const int SIZE,
                   unsigned short *rouge, unsigned short *vert, unsigned short *bleu)
{
    pvm_recv(-1, RESULT_TAG);
    pvm_upkint(&workerID, 1, 1);
    pvm_upkuint(&begin, 1, 1);
    pvm_upkuint(&end, 1, 1);
    pvm_upkushort(rouge, SIZE, 1);
    pvm_upkushort(vert, SIZE, 1);
    pvm_upkushort(bleu, SIZE, 1);

#if TRACE > 0
    printf("ReceiveResult(workerID = %d, begin = %d, end = %d \n", workerID, begin, end);
#endif
}

#endif
