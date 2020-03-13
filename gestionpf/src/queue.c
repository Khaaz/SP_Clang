#include "queue.h"

queue_t * create(int capacity)
{
    queue_t * queue = malloc(sizeof(*queue));

    queue->capacity = capacity;
    queue->size     = 0;
    queue->base     = malloc(capacity * sizeof(T));
    queue->head     = -1;
    queue->tail     = -1;
}

void display(queue)
{
    int i = queue->head;
    while(i != queue->end)
    {
        printf("%d\n", queue->base[i]);
        i = (i + 1) % queue->capacity;
    }
}

/*
void      pushBack();
void      popFront();
void      front();
void      back();
void      isEmpty();
void      display(queue_t);
*/