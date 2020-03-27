// david.brevet@uca.fr

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "stack.h"

void reverseStack(stack_t * stack)
{
    queue_t * queue = createQueue(stack->capacity);
    while(!isEmptyStack(stack))
    {
        pushBack(queue, peek(stack));
        pop(stack);
    }
    while(!isEmptyQueue(queue))
    {
        push(stack, front(queue));
        popFront(queue);
    }
    freeQueue(queue);
}

int Ackerman(int m, int n)
{
    int       mi     = m;
    int       ni     = n;
    stack_t * pile   = createStack(10);
    int       finBcl = 0;
    while(finBcl == 0)
    {
        if(mi != 0)
        {
            while(ni != 0)
            {
                push(pile, mi);
                ni--;
            }
            mi--;
            ni = 1;
        }
        else
        {
            ni++;
            if(!isEmptyStack(pile))
            {
                mi = peek(pile);
                pop(pile);
                mi--;
            }
            else
            {
                finBcl = 1;
            }
        }
    }
    freeStack(pile);
    return ni;
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

    freeStack(stack);

    printf("\nqueue ; \n");

    // queue_t * queue = createQueue(5);
    // pushBack(queue, 1);
    // pushBack(queue, 2);
    // pushBack(queue, 3);
    // pushBack(queue, 4);
    // // displayQueue(queue);
    // popFront(queue);
    // pushBack(queue, 5);
    // pushBack(queue, 6);
    // popFront(queue);
    // displayQueue(queue);
    // freeQueue(queue);

    return 0;
}