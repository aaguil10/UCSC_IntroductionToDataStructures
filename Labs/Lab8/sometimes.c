// $Id: sometimes.c,v 1.6 2012-11-28 20:40:49-08 - - $

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void) {
   time_t times[] = {INT_MIN, 0, time (NULL), INT_MAX};
   char *timeformat = "%a %d %b %Y %H:%M:%S %Z";
   printf ("sizeof (time_t) = %ld\n", sizeof (time_t));
   for (size_t i = 0; i < sizeof times / sizeof *times; ++i) {
      time_t when = times[i];
      struct tm *tm = localtime (&when);
      char buffer_local[64];
      strftime (buffer_local, sizeof buffer_local, timeformat, tm);
      char buffer_gmt[64];
      tm = gmtime (&when);
      strftime (buffer_gmt, sizeof buffer_gmt, timeformat, tm);
      printf ("0x%08X = %s = %s\n",
              (int) times[i], buffer_local, buffer_gmt);
   }
   return EXIT_SUCCESS;
}

