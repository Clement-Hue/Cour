// (c) February 25, 2021, José Martinez, Polytech Nantes
//
// The use of this library is not authorised outside the Polytechnic School of the University of Nantes.
//

#include <assert.h>
#include <stdio.h>
#include "pvm3.h"
#include "MandelbrotPvmConstants.h"
#include "MandelbrotPvmMessages.h"

void ImageMandelbrot(unsigned int largeur,
                     unsigned int hauteur,
                     double x0,
                     double y0,
                     double x1,
                     double y1,
                     unsigned long n_max,
                     int workerTaskIDs[MAX_WORKERS])
{

   double y, x;
   const double dx = (x1 - x0) / largeur;
   const double dy = (y1 - y0) / hauteur;
   Couleur **couleurs = new Couleur *[hauteur];
   for (unsigned int i = 0; i < hauteur; i++)
   {
      couleurs[i] = new Couleur[largeur];
   }

   y = y0;

   for (unsigned long i = 0; i < hauteur; i++)
   {
      y = y0 + i * dy;
      for (unsigned long j = 0; j < largeur; j++)
      {
         x = x0 + j * dx;
         const double p = PointMandelbrot(x, y, n_max);
         couleurs[i][j] = CouleurMandelbrot(p);
      }
   }
}

int main()
{
   unsigned int numberOfWorkers;
   int workerTaskIDs[MAX_WORKERS];
   int hauteur, largeur;
   const int workerID = pvm_mytid();
   assert(pvm_parent() != PvmNoParent);

   ReceiveParameters(numberOfWorkers, workerTaskIDs, hauteur, largeur);
   pvm_exit();

   return 0;
}
