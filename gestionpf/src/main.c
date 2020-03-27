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
    return ni;
    freeStack(pile);
}

void test_Stack(){
    printf("jeux de test pour la pile :\n");
    stack_t * stack = createStack(4);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    displayStack(stack);
    pop(stack);
    printf("\n dernier element de la pile apres un pop : %d \n", peek(stack));
    free(stack);
}

void test_queue(){
    printf("jeux de test pour la file :\n");
    queue_t * queue = createQueue(5);
    pushBack(queue, 1);
    pushBack(queue, 2);
    pushBack(queue, 3);
    pushBack(queue, 4);
    displayQueue(queue);
    popFront(queue);
    printf("\n le premier element de la file  apres un pop est %d \n", front(queue));
    free(queue);

}
int main()
{
    
    test_Stack();
    test_queue();

    printf("test de la fonction reverse :\n");
    stack_t * stack = createStack(4);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    reverseStack(stack);
    
    printf("\n test fonction Ackermann(2,2) : %d", Ackerman(2,2));

    return 0;
}