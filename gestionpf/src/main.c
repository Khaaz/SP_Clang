//david.brevet@uca.fr

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "stack.h"


void reverseStack(stack_t * stack){
    queue_t *queue = createQueue(stack->capacity);
    while (!isEmptyStack(stack))
    {
        pushBack(queue, peek(stack));
        pop(stack);
    }
    while (!isEmptyQueue(queue))
    {
        push(stack, front(queue));
        popFront(queue);
    }
}

int main()
{
    stack_t * stack = createStack(4);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    displayStack(stack);
    reverseStack(stack);
    displayStack(stack);

    printf("\nqueue ; \n");

    queue_t * queue = createQueue(5);
    pushBack(queue, 1);
    pushBack(queue, 2);
    pushBack(queue, 3);
    pushBack(queue, 4);
   // displayQueue(queue);
    popFront(queue);
    pushBack(queue, 5);
    pushBack(queue, 6);
    popFront(queue);
    displayQueue(queue);
    freeQueue(queue);




    return 0;
}