#include "tree.h"
#include "src\stack.h"
#include "src\queue.h"

void Insertion (node_t * node, int * taille, char * liste)
{
    node_t * cour = node;
    stack_t * stack = createStack(10);
    while ( cour != NULL)
    {
        while (cour->son)
        {
            push(stack, cour);
            cour = cour->son;
        }
        liste[*taille]=cour->value;
        *taille ++;
        cour = cour->brother;
        while (cour = NULL && isEmptyStack(stack) == 0)
        {
            cour = peek(stack);
            pop(stack);
            liste[*taille]=cour->value;
            *taille++;
            cour=cour->brother;
        }
    }
    freeStack(stack);
    
}

void display(char * liste, int * taille)
{   
    int i;
    printf("ordre prefixe : ");

    for(i = 0; i <= *taille; i++)
    {
        print("%c ", liste[i];)
    }


}

node_t * search(node_t * node, char valeur)
{
    node_t * cour = node;
    queue_t * queue = createQueue(10);
    while(cour != NULL || cour->value != valeur)
    {
        
        if (cour->son != NULL)
        {
            pushBack(queue, cour);
        }
        if(cour->brother != NULL)
        {
            cour = cour->brother;
        }else
        {
            cour = front(queue);
            popFront(queue);
        }
        
    }
    return cour;
}


int main()
{
    char * treeString = "a*(b*(k*(h+u)+z)+f*m+x*(p+v+w))";

    return 0;
}