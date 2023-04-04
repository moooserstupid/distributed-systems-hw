/*
Client de RPC que simula las operaciones de varios clientes del servidor de log
*/
#include <rpc/rpc.h>
#include <sys/types.h>
#include <sys/times.h>
#include <unistd.h>
#include <pthread.h>
#include "util.h"
#include "sislog.h"

#define LINESIZE 1024
#define MSGSIZE  1024

// Global variables

// IP of the sislog process
char *sislog_ip;

// number of clients
int num_clients;


// type of data to be received by client wires
struct thread_data{
  FILE *fp;
  int client_id;
};

typedef struct thread_data thread_data;

void *Client(thread_data *p)
{
    // Implementation of the thread that generates the events that are sent to the server via RPC.
    // server via RPC
    CLIENT *cl;
    FILE *fp;
    int client_id;
    char buffer[LINESIZE];   // Buffer for reading lines from the event file
    char msg[LINESIZE*2];

    Result *res;
    char *s;
    char * token;
    char * loc;

    eventsislog evt;

    client_id = p->client_id;   // Capture Client id in a local variable
    fp=p->fp;
    free(p);          // We do not need the received parameter anymore, we release it


    // Event reading loop
    do
    {
        // we create a connection hadler with the RPC server
        // and check that it has been created correctly
        cl = clnt_create(sislog_ip, SISLOG, FIRST, "tcp");
        if (cl == NULL) {
        clnt_pcreateerror(sislog_ip);
        exit(1);
        }

        // we read by exclusion the following line from the file whose *FILE
        // we receive in one of the fields of the thread_data structure
        // FILLS THIS GAP
        |
        |
        |

        // if the string read from the file is not null, we tokenize the line in a
        // reentrantly tokenize the line to extract its tokens and to compose
        // the message of the remote invocation to the sislog
        if (s!=NULL)
        {
            // Tokenize string and fill in the data structure
            // TODO
            |
            |
            |
            |
            |
            |

            // Debugging message
            sprintf(msg, "Client %d sends event. Facility: %d, Level: %d, Text: %s",client_id, evt.facility, evt.level, evt.msg);
            log_debug(msg);

            // Send event via RPC and print the returned value
            // and then release the data structures used
            // TODO
            |
            |
            |
            |
            |
            |
            |

        }
        clnt_destroy(cl);
    } while(s);
    return NULL;
}

int  main(int argc,char *argv[])
{
    register int i;    // Index for loops
    pthread_t *th;
    thread_data *q;
    FILE *fp;
    char msg[LINESIZE*2];


    if (argc!=4)
    {
        fprintf(stderr,"Usage form: %s <num_clients> <ip_serv_sislog> <event_file>",argv[0]);
        exit(1);
    }
    if (atoi((char *) argv[1])<=0)
    {
        fprintf(stderr,"The parameter <customer_number> must be a positive integer.\n");
        exit(3);
    }
    sislog_ip=strdup(argv[2]);
    if (!valid_ip(argv[2]))
    {
        fprintf(stderr, "The IP entered is not valid\n");
        exit(4);
    }
    num_clients=atoi(argv[1]);

    // We reserve memory for the thread data objects
    th=(pthread_t *) malloc(sizeof(pthread_t)*num_clients);
    if (th==NULL)
    {

        sprintf(msg, "Error: not enough memory for thread data objects\n");
        log_debug(msg);
        exit(5);
    }

    if ((fp=fopen(argv[3],"r"))==NULL)
    {
        perror("Error opening the event file");
        exit(6);
    }


    // Creation of a thread for each Client. These do receive as parameter
    // an integer pointer that will be its client_id. One is dynamically created
    // for each thread and the loop counter is assigned to it.
    for (i=0;i<num_clients;i++)
    {
        // TODO
        |
        |
        |
        |

    }

    // main waits for all vessels to be completed
    for (i=0;i<num_clients;i++)
    {
        pthread_join(th[i],NULL);
    }
    free(th);
}
