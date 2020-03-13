#include <stdio.h>

typedef int T;

typedef struct queue
{
    int capacity;
    int size;
    int head;
    int tail;
    T * base;
} queue_t;

queue_t * create(int);
void      pushBack();
void      popFront();
void      front();
void      back();
void      isEmpty();
void      display(queue_t);
