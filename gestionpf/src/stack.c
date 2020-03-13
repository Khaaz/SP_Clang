#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

stack_t * create(int capacity)
{
    stack_t * stack = malloc(sizeof(*stack));
    stack->capacity = capacity;
    stack->top      = -1;
    stack->base     = malloc(capacity * sizeof(T));
    return stack;
}

void display(stack_t * stack)
{
    for(int i = 0; i < stack->top + 1; i++)
    {
        printf("%d \n", stack->base[i]);
    }
}

int push(stack_t * stack, T t)
{
    int success = 1;
    if(stack->top + 1 == stack->capacity)
    {
        success = 0;
    }
    else
    {
        stack->top += 1;
        stack->base[stack->top] = t;
    }
    return success;
}

int pop(stack_t * stack)
{
    int success = 1;
    if(stack->top == -1)
    {
        success = 0;
    }
    else
    {
        stack->top -= 1;
    }
    return success;
}

T peek(stack_t * stack)
{
    T t;
    if(isEmpty(stack))
    {
        t = 0;
    }else
    {
        t = stack->base[stack->top];
    }
    
    return t;
}

int isEmpty(stack_t * stack)
{
    int success = 0;
    if(stack->top == -1)
    {
        success = 1;
    }
    return success;
}


void freeStack(stack_t * stack){

    free(stack->base);
    free(stack);
    stack=NULL;
}