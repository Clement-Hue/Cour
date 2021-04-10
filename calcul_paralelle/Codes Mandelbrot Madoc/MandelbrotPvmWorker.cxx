// (c) February 25, 2021, José Martinez, Polytech Nantes
//
// The use of this library is not authorised outside the Polytechnic School of the University of Nantes.
//

#include <assert.h>
#include <stdio.h>
#include "pvm3.h"
#include "MandelbrotPvmConstants.h"
#include "MandelbrotPvmMessages.h"

void WorkerInterval(int workerID,
                    unsigned int numberOfWorkers,
                    int workerTaskIDs[MAX_WORKERS],
                    int hauteur,
                    int &begin,
                    int &end)
{

   const unsigned int width = hauteur / numberOfWorkers;

   for (unsigned int i = 0; i < numberOfWorkers; i++)
      if (workerTaskIDs[i] == workerID)
      {
#ifdef TRACE
         printf("I am the worker number %d\n", i);
#endif
         // que se passe t-il quand i vaut 0 ?
         begin = width * i;
         if (i == numberOfWorkers - 1)
            end = hauteur;
         else
            end = begin + width;

         break;
      }
}

/***************************************************************/
/* MEMBERSHIP COMPUTATION                                      */
/***************************************************************/

template <class T>
inline T square(T x)
{
   return x * x;
}

double PointMandelbrot(double x0,
                       double y0,
                       unsigned long n_max)
{
#ifdef PRE_CONDITIONS
   assert(n_max > 0);
#endif

   double x, y;

   x = y = 0.0;
   for (unsigned long n = 0; n < n_max; n++)
   {
      const double x_prec = x;
      const double y_prec = y;

      x = x0 + square(x_prec) - square(y_prec);
      y = y0 + 2 * x_prec * y_prec;

      if (square(x) + square(y) > 4.0)
         return (double)n / n_max;
   }
   return 0.0;
}

/***************************************************************/
/* PIXEL COLOURS                                               */
/***************************************************************/

Couleur CouleurMandelbrot(double p)
{
#ifdef PRE_CONDITIONS
   assert(0.0 <= p);
   assert(p <= 1.0);
#endif

   if (p == 0.0)
      return (Couleur){0, 0, 0};
   else
   {
      const unsigned long value = (1.0 - p) * 256 * 256 * 256;
      const unsigned short v1 = value % 256;
      const unsigned short v2 = value / 256 % 256;
      const unsigned short v3 = value / 256 / 256 % 256;

      if (value % 3 == 0)
         return (Couleur){v1, v2, v3};
      else if (value % 3 == 1)
         return (Couleur){v3, v1, v2};
      else
         return (Couleur){v2, v3, v1};
   }
}

void ImageMandelbrot(unsigned short *rouge,
                     unsigned short *vert,
                     unsigned short *bleu,
                     unsigned int largeur,
                     int begin,
                     int end,
                     double x0,
                     double y0,
                     double dx,
                     double dy,
                     unsigned long n_max)
{
   double y, x;
   for (unsigned long i = begin; i < end; i++)
   {
      y = y0 + i * dy;
      for (unsigned long j = 0; j < largeur; j++)
      {
         x = x0 + j * dx;
         const double p = PointMandelbrot(x, y, n_max);
         const Couleur &c = CouleurMandelbrot(p);
         rouge[i * largeur + j] = c.rouge;
         vert[i * largeur + j] = c.vert;
         bleu[i * largeur + j] = c.bleu;
      }
   }
}

int main()
{
   unsigned int numberOfWorkers;
   int workerTaskIDs[MAX_WORKERS];
   unsigned int hauteur;
   int largeur, begin, end;
   double x0, y0, dx, dy;
   unsigned long n_max;
   const int workerID = pvm_mytid();
   assert(pvm_parent() != PvmNoParent);
   ReceiveParameters(numberOfWorkers, workerTaskIDs, hauteur, largeur, x0, y0, dx, dy, n_max);
   const int SIZE = hauteur * largeur;
   unsigned short rouge[SIZE];
   unsigned short vert[SIZE];
   unsigned short bleu[SIZE];
   WorkerInterval(workerID, numberOfWorkers, workerTaskIDs, hauteur, begin, end);
   ImageMandelbrot(rouge, vert, bleu, largeur, begin, end, x0, y0, dx, dy, n_max);
   SendResult(workerID, begin, end, SIZE, rouge, vert, bleu);
   pvm_exit();

   return 0;
}
