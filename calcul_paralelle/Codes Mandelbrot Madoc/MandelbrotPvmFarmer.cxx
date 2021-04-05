
// (c) February 25, 2021, José Martinez, Polytech Nantes:
//
// The use of this library is not authorised outside the Polytechnic School of the University of Nantes.

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "pvm3.h"
#include "MandelbrotPvmConstants.h"
#include "MandelbrotPvmMessages.h"

#define PPM_RAW 0
#define PPM_ASCII 1

#define PPM_FORMAT PPM_RAW

#define X_CENTER 0.0
#define Y_CENTER 0.0
#define X_DELTA 3.0      // > 0
#define Y_DELTA 2.0      // > 0
#define IMAGE_WIDTH 1920 // > 0
#define N_MAX 5000       // > 0

void StartFarm(unsigned int numberOfWorkers,
               int &farmerID,
               int workerTaskIDs[MAX_WORKERS])
{

   farmerID = pvm_mytid(); // Starting PVM by enrolling the farmer

   const int numberOfStartedTasks = pvm_spawn(WORKER_PROGRAM,
                                              (char **)NULL, // no command-line argument
                                              PvmTaskDefault + PvmTaskTrace,
                                              (char *)"", // no specific location on which to start the tasks
                                              numberOfWorkers,
                                              workerTaskIDs); // Starting the workers at any place
   if (numberOfStartedTasks < numberOfWorkers)
   { // ABNORMAL TERMINATION
      printf("%d started tasks out of %d.\n",
             numberOfStartedTasks, numberOfWorkers);
      printf("Aborting the started workers...\n");
      for (unsigned int i = 0; i < numberOfStartedTasks; i++)
         pvm_kill(workerTaskIDs[i]);
      printf("Error codes for the erroneous ones are:\n");
      for (unsigned int i = numberOfStartedTasks; i < numberOfWorkers; i++)
         printf("   %d.  tid:  %d\n", i, workerTaskIDs[i]);
      pvm_exit();
      exit(1);
   }
}

void EndFarm(unsigned int numberOfWorkers,
             int workerTaskIDs[MAX_WORKERS])
{
   for (unsigned int i = 0; i < numberOfWorkers; i++)
      pvm_kill(workerTaskIDs[i]);
   pvm_exit();
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

/***************************************************************/
/* ASCII PPM IMAGE                                             */
/***************************************************************/

void ImageMandelbrot(unsigned int largeur,
                     unsigned int hauteur,
                     double x0,
                     double y0,
                     double x1,
                     double y1,
                     unsigned long n_max,
                     int workerTaskIDs[MAX_WORKERS])
{
#ifdef PRE_CONDITIONS
   assert(largeur > 0);
   assert(hauteur > 0);
   assert(x0 < x1);
   assert(y0 < y1);
   assert(n_max > 0);
#endif

   const double dx = (x1 - x0) / largeur;
   const double dy = (y1 - y0) / hauteur;

#ifdef INVARIANTS
   assert(dx > 0);
   assert(dy > 0);
#endif

#if DRY_RUN == true

   double x, y;

   y = y0;
   for (unsigned long i = 0; i < hauteur; i++, y += dy)
   {
      x = x0;
      for (unsigned long j = 0; j < largeur; j++, x += dx)
      {
         const double p = PointMandelbrot(x, y, n_max);
         const Couleur c = CouleurMandelbrot(p);
      }
   }

#else

   double y, x;
   Couleur **couleurs = new Couleur *[hauteur];
   for (unsigned int i = 0; i < hauteur; i++)
   {
      couleurs[i] = new Couleur[largeur];
   }

   printf("P3\n#Mandelbrot set\n%d %d\n255\n", (int)largeur, (int)hauteur);

   y = y0;

   BroadcastParameters(NUMBER_OF_WORKERS, workerTaskIDs, hauteur, largeur);
   //   for (unsigned int i = 0; i < NUMBER_OF_WORKERS; i++)
   //   {
   //      /* const */ int workerID;
   //      /* const */ unsigned int begin;
   //      /* const */ unsigned int end;
   //      /* const */ float partialSum;
   //
   //      ReceiveResult(workerID, begin, end, partialSum);
   //   }
   //
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

   //   for (unsigned long i = 0; i < hauteur; i++)
   //   {
   //      for (unsigned long j = 0; j < largeur; j++)
   //      {
   //         printf("%3hd %3hd %3hd   ", couleurs[i][j].rouge, couleurs[i][j].vert, couleurs[i][j].bleu);
   //      }
   //      printf("\n");
   //   }

   for (unsigned int i = 0; i < hauteur; i++)
   {
      delete[] couleurs[i];
   }

   delete[] couleurs;

#endif
}

/***************************************************************/
/* COMMAND-LINE INTERFACE                                      */
/***************************************************************/

void LigneCommande(int argc,
                   char *argv[],
                   double &x,
                   double &y,
                   double &dx,
                   double &dy,
                   int &width,
                   unsigned long &n_max)
{
#if PRE_CONDITIONS
   assert(X_DELTA > 0);
   assert(Y_DELTA > 0);
   assert(IMAGE_WIDTH > 0);
   assert(N_MAX > 0);
#endif

   if (argc == 1)
   {
      x = X_CENTER;
      y = Y_CENTER;
      dx = X_DELTA;
      dy = Y_DELTA;
      width = IMAGE_WIDTH;
      n_max = N_MAX;
      return;
   }
   if (argc != 7)
   {
      printf("Usage:  Mandelbrot x y dx dy width n_max\n");
      printf("where (x, y) is the coordinate of the center of the region of interest in the plane,\n");
      printf("      (dx, dy) is the width and height of the region of interest,\n");
      printf("      'width' is the width, in pixels, of the image to generate.\n");
      printf("      and 'n_max' is the maximum number of iterations before a point is declared outside the Mandelbrot set.\n");
      printf("Default values are:  0 0 3 2 500 200\n");
      printf("The result is sent on the standard output.\n");
      exit(1);
   }
   x = atof(argv[1]);
   y = atof(argv[2]);
   dx = atof(argv[3]);
   dy = atof(argv[4]);
   width = atoi(argv[5]);
   n_max = atol(argv[6]);
   if (dx <= 0.0 ||
       dy <= 0.0 ||
       width <= 0 ||
       n_max <= 0)
   {
      printf("Error:  'dx,' 'dy,' 'width,' and 'n_max' must be strictly greater than zero.\n");
      exit(2);
   }
}

int main(int argc,
         char *argv[])
{
   double xc;
   double yc;
   double dx;
   double dy;
   int farmerID;
   int workerTaskIDs[MAX_WORKERS];
   int largeur;
   unsigned long n_max;

   LigneCommande(argc, argv,
                 xc, yc, dx, dy, largeur, n_max);

   const unsigned int hauteur = (dy / dx) * largeur;
   const double x0 = xc - dx;
   const double x1 = xc + dx;
   const double y0 = yc - dy;
   const double y1 = yc + dy;

   StartFarm(NUMBER_OF_WORKERS, farmerID, workerTaskIDs);
   ImageMandelbrot(largeur, hauteur, x0, y0, x1, y1, n_max, workerTaskIDs);
   EndFarm(NUMBER_OF_WORKERS, workerTaskIDs);
}
