#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

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
    stack_t * stack = create(3);
    push(stack, 5);
    push(stack, 5);
    push(stack, 5);
    pop(stack);
    pop(stack);
    pop(stack);
    display(stack);
    return 0;
}