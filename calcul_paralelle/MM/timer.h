/************************************************************/
/*  UNIX dtime(). This is the preferred UNIX timer.         */
/*  It returns the time used by the user program rather     */
/* than the elapsed time from the beginning of the process. */
/************************************************************/

#ifndef Includedtime
#define Includedtime

#include <sys/time.h>
#include <sys/resource.h>

struct rusage rusage;

double dtime ()
{
register double q;

getrusage(RUSAGE_SELF,&rusage);
q = (double) rusage.ru_utime.tv_sec +
    (double) rusage.ru_utime.tv_usec * 1.0e-06;
  
return q;
}

#endif
