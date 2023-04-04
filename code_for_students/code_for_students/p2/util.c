#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include "util.h"


// Utility function that determines if characters in a string are all numerical
// are all numeric
int valid_number(char *str) {
    // TODO
    |
    |
    |
    |
}

// Utility function that validates whether a character string represents
// a valid IPv4
int valid_ip(char *ip)
{ 
    // Checks if the string contains a valid ip
    // TODO
    |
    |
    |
    |
}


// Utility function, to generate the times used by vessels in port operations.
// Returns a random number between min and max.
double randRange(double min, double max)
{
  return min + (rand() / (double) RAND_MAX * (max - min + 1));
}


// Utility function for debugging. It outputs the message
// that is passed as a parameter, but it puts in front of the message a
// timestamp in front of the message, so that the output can be sorted in case it gets out of order.
//
// Example of use:
//
// log_debug("Message to print")
//
// More examples in the main program.
void log_debug(char *msg){
  struct timespec t;
  clock_gettime(_POSIX_MONOTONIC_CLOCK, &t);
  printf("[%ld.%09ld] %s", t.tv_sec, t.tv_nsec, msg);
}

// Utility function to dump the contents of an array of counters.
void show_event_discount(int nrows, int ncols, char **rows, char ** columns,int **values)
{
  register int i,j;
  printf("*****************  EVENT COUNT *******************\n");

  printf("\t");
  for (i=0;i<ncols;i++)
    printf("%s\t",columns[i]);
  printf("\n");
  for (i=0;i<nrows;i++)
  {
    printf("%s\t",rows[i]);
    for (j=0;j<ncols;j++)
      printf("%d\t",values[i][j]);
    printf("\n");
  }
}
