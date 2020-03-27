typedef int T;

/**
 * @brief Structure Queue. La file.
 *
 */
typedef struct queue
{
    int capacity; // La capactie maximum de la file (nombre d'elements maximum
                  // dans cette file)
    int size;     // La taille actuelle de la file
    int head;     // L'indice du premier element
    int tail;     // L'indice du dernier element
    T * base;     // Le tableau d'elements de la file
} queue_t;

queue_t * createQueue(int);
int       pushBack(queue_t *, T);
int       popFront(queue_t *);
T         front(queue_t *);
int       isEmptyQueue(queue_t *);
int       isFullQueue(queue_t *);
void      displayQueue(queue_t *);
void      freeQueue(queue_t *);
