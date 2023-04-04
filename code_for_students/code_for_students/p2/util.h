#ifndef __UTIL_H__

#define TRUE 1
#define FALSE 0

int valid_number(char *str);
int valid_ip(char *ip);
double randRange(double min, double max);
void log_debug(char *msg);
void show_event_discount(int ncols, int nfils, char **filas,char ** columnas,int **valores);

#define __UTIL_H__
#endif
