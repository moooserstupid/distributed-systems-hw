#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include "util.h"

// Utility function that determines whether the characters in a string are all numerical characters
int valid_number(char *str) {
    // TODO
    |
    |
    |
    |
}

// Utility function that validates whether a character string represents a valid IPv4.
int valid_ip(char *ip)
{
    // Checks if the string contains a valid ip
    // TODO
    |
    |
    |
    |
}

// Utility function, to generate the random times between a
// min and max
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
//  log_debug("Message to be displayed on the screen")
//
void log_debug(char *msg){
  struct timespec t;
  clock_gettime(_POSIX_MONOTONIC_CLOCK, &t);
  printf("[%ld.%09ld] %s", t.tv_sec, t.tv_nsec, msg);
}
