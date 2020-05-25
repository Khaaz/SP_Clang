#include "tree.c"

node_t * createNode(char value)
{
    node_t * node = malloc(sizeof(*node));
    if(node != NULL)
    {
        stack->value   = value;
        stack->son     = NULL;
        stack->brother = NULL;
    }
    else
    {
        printf("ERROR: Allocation Node\n")
    }
    return node;
}

void insertBrother(node_t * node, node_t * element)
{
    node->brother = element;
}

void insertSon(node_t * node, node_t * element)
{
    node->son = element;
}