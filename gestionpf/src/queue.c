#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

queue_t * createQueue(int capacity)
{
    queue_t * queue = malloc(sizeof(*queue));

    queue->capacity = capacity;
    queue->base     = malloc(capacity * sizeof(T));
    queue->head     = 0;
    queue->tail     = 0;
    return queue;
}

void displayQueue(queue_t * queue)
{
    int i = queue->head;
    while(i != queue->tail)
    {
        printf("%d\n", queue->base[i]);
        i = (i + 1) % queue->capacity;
    }
}

int pushBack(queue_t * queue, T element)
{
    int success = 1;
    if(isFullQueue(queue))
    {
        success = 0;
    }
    else
    {
        queue->base[queue->tail] = element;

        if(queue->tail + 1 == queue->capacity)
        {
            queue->tail = 0;
        }
        else
        {
            queue->tail += 1;
        }
    }
    return success;
}

int popFront(queue_t * queue)
{
    int success = 1;
    if(isEmptyQueue(queue))
    {
        success = 0;
    }
    else
    {
        if(queue->head == queue->capacity)
        {
            queue->head = 0;
        }
        else
        {
            queue->head += 1;
        }
    }
    return success;
}

T front(queue_t * queue)
{
    T element;
    if(isEmptyQueue(queue))
    {
        element = 0;
    }
    element = queue->base[queue->head];
    return element;
}

int isEmptyQueue(queue_t * queue)
{
    int empty = 0;
    if(queue->tail == queue->head)
    {
        empty = 1;
    }
    return empty;
}

int isFullQueue(queue_t * queue)
{
    int full = 0;
    if(queue->tail == queue->head - 1)
    {
        full = 1;
    }
    return full;
}

void freeQueue(queue_t * queue)
{

    free(queue->base);
    free(queue);
    queue = NULL;
}
