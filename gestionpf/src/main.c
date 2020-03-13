#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "stack.h"

/*
void reverseStack(stack_t * stack){
    queue_t *queue = createQueue();
    while (!isEmptyStack)
    {
        pushBack(queue, peek(stack_t));
        pop(stack);
    }
    while (!isEmptyQueue)
    {
        push(stack_t *, front(queue));
        popFront(queue);
    }
}
*/
int main()
{
    stack_t * stack = createStack(3);
    push(stack, 5);
    push(stack, 5);
    push(stack, 5);
    pop(stack);
    pop(stack);
    pop(stack);
    displayStack(stack);
    freeStack(stack);

    queue_t * queue = createQueue(5);
    pushBack(queue, 1);
    pushBack(queue, 2);
    pushBack(queue, 3);
    pushBack(queue, 4);
    popFront(queue);
    pushBack(queue, 5);
    pushBack(queue, 6);
    popFront(queue);

    return 0;
}