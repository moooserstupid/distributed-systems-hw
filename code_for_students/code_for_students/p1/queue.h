#include <netinet/in.h> // Necesario para sockaddr_in
#include <pthread.h>
#include <semaphore.h>

#define MAXMSGSIZE 1024

typedef struct {
  unsigned char facility; // origin of the event
  unsigned char level;     // severity of the event
  char msg[TAMMAXMSG];     // explanatory message of the event
} data_queue;

struct Queue {
    data_queue **data; // the Queue itself is an array of pointers to queue_data
    int head;
    int tail;
    int data_socket;
    pthread_mutex_t mutex_head;
    pthread_mutex_t mutex_tail;
    sem_t num_spaces;
    sem_t num_allocated;
};
typedef struct Queue Queue;

void initialize_queue(Queue *queue, int queue_size);
void destroy_queue(Queue *queue);
void insert_queue_data(Queue *queue, data_queue * dato);
data_queue *get_queue_data(Queue *queue);
