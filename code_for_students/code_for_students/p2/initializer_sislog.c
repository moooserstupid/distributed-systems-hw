/*
RPC client initializing the sislog server
*/
#include <rpc/rpc.h>
#include <sys/types.h>
#include <sys/times.h>
#include <unistd.h>
#include <pthread.h>
#include "sislog.h"
#include "util.h"


int  main(int argc,char *argv[])
{
   CLIENT *cl;
   faclevel params;
   char *sislog_ip;

   if (argc!=4)
   {
      fprintf(stderr,"Usage form: %s <max_facilities> <max_levels> <sislog_ip>.\n",argv[0]);
      exit(1);
   }
   if ((atoi((char *) argv[1])<=0) || (atoi((char *) argv[1])>MAXFACILITIES))
   {

      fprintf(stderr,"The parameter <max_facilities> must be >=0 and <=%d\n",MAXFACILITIES);
      exit(3);
   }
   if ((atoi((char *) argv[2])<=0) || (atoi((char *) argv[2])>MAXLEVELS))
   {
      fprintf(stderr,"The <max_levels> parameter must be >=0 and <=%d\n",MAXLEVELS);
      exit(3);
   }
   sislog_ip=strdup(argv[3]);
   if (!valid_ip(argv[3]))
   {
      fprintf(stderr, "Error: The IP parameter is not valid\n");
      exit(4);
   }

   // We connect to the RPC server by passing it the appropriate parameters
   // to initialize its data structures with the required size
   // TODO
   |
   |
   |
   |

   printf("Sislog initialized\n");
   return 0;
}
