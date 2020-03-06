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
    int error = 1;
    if(stack->top + 1 == stack->capacity)
    {
        error = 0;
    }
    else
    {
        stack->top += 1;
        stack->base[stack->top] = t;
    }
    return error;
}

int pop(stack_t * stack)
{
    int error = 1;
    if(stack->top == -1)
    {
        error = 0;
    }
    else
    {
        stack->top -= 1;
    }
    return error;
}

T peek(stack_t * stack)
{
    T t = stack->base[stack->top];
    if(isEmpty(stack))
    {
        t = 0;
    }
    return t;
}

int isEmpty(stack_t * stack)
{
    int error = 0;
    if(stack->top == -1)
    {
        error = 1;
    }
    return error;
}