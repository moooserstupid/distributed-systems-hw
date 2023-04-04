#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>
#include <sched.h>

// Header files for socket manipulation
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <time.h>

#include "queue.h"
#include "util.h"

#define TRUE 1
#define FALSE 0

#define NUMFACILITIES   10
#define NUMLEVELS        8

// Data structure for passing parameters to the attention threads
struct param_thread_aten{
    int num_thread;
    int s;
};

typedef struct param_thread_aten param_thread_aten;

// ====================================================================
// PROTOTYPES FUNCTIONS
// ====================================================================
static void handler(int signum); // Manejador de señal SIGINT

// ====================================================================
// GLOBAL VARIABLES
// ====================================================================

// Queue for synchronizing the request handling threads with the
// worker threads
Queue events_queue;

// Port where we wait for messages
int port;

// Boolean variable indicating whether the socket is connection oriented or not
unsigned char is_stream=TRUE;

// Variable that stores the number of threads for handling requests.
int num_threads_aten;

// Variable storing the number of worker threads
int num_threads_work;

// Pointer to the starting address of the thread data array
// of the request handling threads
pthread_t *threads_aten;

// Pointer to the starting address of the thread data array.
// of the worker threads
pthread_t *threads_work;

// Arrays for translating level names and facility names
// and to obtain the names of the log files
char * facilities_names[NUMFACILITIES]={
    "kern",
    "user",
    "mail",
    "daemon",
    "auth",
    "syslog",
    "lpr",
    "news",
    "uucp",
    "cron"};

char * level_names[NUMLEVELS]={
    "emerg",
    "alert",
    "crit",
    "err",
    "warning",
    "notice",
    "info",
    "debug"};

char * facilities_file_names[NUMFACILITIES]={
    "fac00.dat",
    "fac01.dat",
    "fac02.dat",
    "fac03.dat",
    "fac04.dat",
    "fac05.dat",
    "fac06.dat",
    "fac07.dat",
    "fac08.dat",
    "fac09.dat"};

// exclusion mutex to log files
pthread_mutex_t mfp[NUMFACILITIES];


// Circular Queue Size
int queue_size;

// ====================================================================
// Handler function of the signals received by the vessel thread
// ====================================================================
static void handler(int signum)
{
    register int i;

    switch (signum){
        case SIGINT:
            // If this signal is received, you must terminate "OK" by
            // releasing all resources in use before terminating
            // TODO
            |
            |
            |
            |
        default:
            pthread_exit(NULL);
    }
}

void process_arguments(int argc,char *argv[])
{
    // TODO
    |
    |
    |
    |
}

// ====================================================================
// Thread implementation
// ====================================================================

void *Worker(int *id)
{
    int id_worker;
    FILE *fp;
    data_queue *evt;
    char msg[2048];
    char *datetime;
    time_t timeraw;

    // We make a copy of the received parameter
    id_worker=*id;

    // and release the memory reserved for it
    free(id);

    // We display debugging information on the screen
    sprintf(msg, "Worker %d begins\n", id_worker);
    log_debug(msg);

    // Worker code. It waits for data from the synchronization queue,
    // generates based on it the line to write, and writes it // to the corresponding file.
    // in the corresponding file. Look at "Queue.h"
    // to remember the queue_data structure it receives from the queue.
    while (1)
    {
        // TODO
        |
        |
        |
        |
    }
}

void * AttentionRequests (param_thread_aten *q)
{
   int data_socket, received;
   struct sockaddr_in client_addr;
   socklen_t l_dir=sizeof(client_addr);
   char msg[100];
   char buffer[TAMMSG];
   char * token;
   char * loc;
   data_queue *p;
   int s;  // Local variable to store the socket received as a parameter
   int num_thread; // local variable to store the thread number received as parameter
                 // (not used, but you can use it to print debug messages)

   // Debugging information
   sprintf(msg, "Beginning of the Request Thread %d\n", q->num_thread);
   log_debug(msg);

   // We make a copy of the received parameters
   s = q->s;
   num_thread = q->num_thread;

   // and we free the memory reserved for the parameter
   free(q);

   while (1) // Infinite loop of message attention
   {
        // First, the customer's message is received. How this is done depends on
        // on whether the socket is connection-oriented or not
        if (is_stream) // TCP
        {
            // Accept the client, read your message until you receive it in its entirety, and close the connection.
            // TODO
            |
            |
            |
            |
        }
        else // UDP
        {
            // Receive datagram message
            // TODO
            |
            |
            |
            |
        }
        // Once the message is received, it is necessary to separate its parts,
        // store them in the appropriate structure, and put that structure into the 
        // synchronization queue.
        // TODO
        |
        |
        |
        |
   }
}


// ====================================================================
// MAIN PROGRAM
// ====================================================================

// Its mission is to create and initialize the global synchronization resources,
// launch all threads and wait for them to finish.

int main(int argc,char *argv[])
{
    register int i;   // Index for loops
    int *id;          // To pass the identifier to each worker thread
    int passive_socket;
    struct sockaddr_in local_addr;
    param_thread_aten *q;

    process_arguments(argc,argv);

    setbuf(stdout,NULL); // we remove the buffer from the standard output
    signal(SIGINT, handler); // we establish the behavior upon asynchronous arrival of the signal

    // Data to assign port to socket
    local_addr.sin_family= AF_INET;
    local_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    local_addr.sin_port=htons(port);

    if (is_stream) // Prepare TCP socket
    {
        // TODO
        |
        |
        |
        |
    }
    else // Prepare UDP socket
    {
        // TODO
        |
        |
        |
        |
    }

    // Assign the port to the socket
    // TODO
    |
    |
    |
    |

    // we create the space for the thread data objects
    threads_aten=(pthread_t *)malloc(num_threads_aten*sizeof(pthread_t));

    // Initialize the exclusion mutexes to the log files
    // in which the workers will write
    // TODO
    |
    |
    |
    |

    // We reserve space for the thread data objects of the worker threads.
    threads_work=(pthread_t *)malloc(num_threads_work*sizeof(pthread_t));

    // Initialize the Queue
    // TODO
    |
    |


    // We create each one of the threads of attention of requests
    for (i=0;i<num_threads_aten;i++)
    {
        // TODO
        |
        |
        |
        |
    }
    // We create each one of the worker threads
    for (i=0;i<num_threads_work;i++)
    {
        // TODO
        |
        |
        |
        |
    }

    // We wait for all threads to finish
    for (i=0;i<num_threads_aten;i++)
    {
        pthread_join(threads_aten[i],NULL);
    }
    for (i=0;i<num_threads_work;i++)
    {
        pthread_join(threads_work[i],NULL);
    }
}
