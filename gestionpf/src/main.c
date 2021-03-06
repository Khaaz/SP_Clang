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

int ackerman(int m, int n)
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

void testStack()
{
    stack_t * stack = createStack(4);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);

    displayStack(stack);

    pop(stack);
    printf("Dernier element de la pile apres un pop : %d\n", peek(stack));

    freeStack(stack);
}

void testQueue()
{
    queue_t * queue = createQueue(4);
    pushBack(queue, 1);
    pushBack(queue, 2);
    pushBack(queue, 3);
    pushBack(queue, 4);

    displayQueue(queue);

    popFront(queue);
    printf("Premier element de la file  apres un pop : %d\n", front(queue));

    freeQueue(queue);
}

void testReverse()
{
    stack_t * stack = createStack(4);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);

    printf("Avant reverse:\n");
    displayStack(stack);

    reverseStack(stack);

    printf("Apres reverse:\n");
    displayStack(stack);

    freeStack(stack);
}

int main()
{

    printf("TEST - Stack:\n");
    testStack();
    printf("TEST - Queue:\n");
    testQueue();

    printf("TEST - Reverse:\n");
    testReverse();

    printf("TEST - Ackermann(2,2) : %d\n", ackerman(2, 2));

    return 0;
}