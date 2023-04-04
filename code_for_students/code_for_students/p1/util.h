#ifndef __UTIL_H__

#include <pthread.h>
#include <semaphore.h>
#include <ctype.h>
#include <string.h>

#define FALSE   0
#define TRUE  1
#define TAMMSG  1024

int valid_number(char *str);
int valid_ip(char *ip);
double randRange(double min, double max);
void log_debug(char *msg);

#define __UTIL_H__
#endif
