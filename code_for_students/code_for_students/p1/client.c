// Header files for socket manipulation
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <ctype.h>
#include <pthread.h>
#include <errno.h>
#include "util.h"

#define LINESIZE 1024
#define FALSE 0
#define TRUE 1
#define SINASIGNAR -1

// type of data to be received by the reader wires
struct thread_data
{
  FILE *fp;
  struct sockaddr *dserv;
};

typedef struct thread_data thread_data;

//
// GLOBAL VARIABLES
//

// IP of the syslog process
char *ip_syslog;

// Port on which the syslog process waits for the
int syslog_port;

// Number of reader threads
int nthreads;

// Whether or not connection oriented
unsigned char is_stream = TRUE;

// name of the event source file
char *events_file;

// file handler
FILE *fp;

void process_arguments(int argc, char *argv[])
{
  // TODO
  |
      |
      |
      |
}

void get_out_well(int s)
{
  fclose(fp);
  exit(0);
}

void *reader_thread(thread_data *p)
{
  int sent;
  char buffer[LINESIZE];
  char *s;
  int data_socket;

  do
  {
    bzero(buffer, LINESIZE);
    // Read the next line of the file with fgets
    // (making mutual exclusion with other threads)
    // The file (already opened by main) is received in one of the parameters
    // TODO -----------------
    |
        |
        |
        |
        |

        if (s != NULL)
    {
      // The IP and port of the server are in a sockaddr_in structure
      // which is received in one of the parameters
      if (is_stream) // Send the line over a TCP socket
      {
        // TODO
        |
            |
            |
            |
      }
      else // Send the line over a UDP socket
      {
        // TODO
        |
            |
            |
            |
      }
      close(data_socket);
      printf("%s", s); // For debugging, print the line that we have sent you
    }
  } while (s); // As long as the end of the file is not reached
}

void main(int argc, char *argv[])
{
  // The main function creates the reader threads, passing them the necessary parameters,
  // and waits for them to finish

  register int i;

  pthread_t *th;
  thread_data q;

  int data_socket, sent;
  struct sockaddr_in server_addr;

  socklen_t ldir;
  char buffer[50];

  // Installing the SIGINT signal processing routine
  // TODO
  |
      |

      // Processing command line arguments
      process_arguments(argc, argv);

  printf("Server IP %s, is_stream=%d\n", ip_syslog, is_stream);
  if ((fp = fopen(events_file, "r")) == NULL)
  {
    perror("Error opening the event file");
    exit(6);
  }

  // we create space for thread data objects
  // TODO
  |
      |
      |
      |

      // we initialize the data that we are going to pass as parameter to the reader_threads
      // (the same parameter is passed to all of them)
      // TODO
      |
      |
      |
      |

      for (i = 0; i < nthreads; i++)
  {
    // we launch the reader thread
    // TODO
    |
        |
        |
  }

  // Once all of them have been launched, we make a join on each one of them
  for (i = 0; i < nthreads; i++)
  {
    pthread_join(th[i], NULL);
  }
  // By the time you get here, all the threads have ended
  fclose(fp);
}
