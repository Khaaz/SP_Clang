#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

queue_t * createQueue(int capacity)
{
    queue_t * queue = malloc(sizeof(*queue));

    queue->capacity = capacity;
    queue->size     = 0;
    queue->base     = malloc(capacity * sizeof(T));
    queue->head     = -1;
    queue->tail     = -1;
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
    if(queue->size == queue->capacity)
    {
        success = 0;
    }
    else
    {
        queue->size += 1;

        if(queue->tail + 1 == queue->capacity)
        {
            queue->tail = 0;
        }
        else
        {
            queue->tail += 1;
        }

        queue->base[queue->tail] = element;
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
        queue->size -= 1;

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

T back(queue_t * queue)
{
    T element;
    if(isEmptyQueue(queue))
    {
        element = 0;
    }
    element =  queue->base[queue->tail];
    return element;
}

int isEmptyQueue(queue_t * queue)
{
    int empty = 0;
    if(queue->size == 0)
    {
        empty = 1;
    }
    return empty;
}

void freeQueue(queue_t * queue)
{

    free(queue->base);
    free(queue);
    queue = NULL;
}
