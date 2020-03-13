#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    stack_t * stack = create(3);
    display(stack);
    printf("%d\n", peek(stack));
    freeStack(stack);

    return 0;
}