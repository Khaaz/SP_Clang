typedef int T;

typedef struct queue
{
    int capacity;
    int size;
    int head;
    int tail;
    T * base;
} queue_t;

queue_t * createQueue(int);
int       pushBack(queue_t *, T);
int       popFront(queue_t *);
T         front(queue_t *);
int       isEmptyQueue(queue_t *);
int       isFullQueue(queue_t *);
void      displayQueue(queue_t *);
void      freeQueue(queue_t *);
