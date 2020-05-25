#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

/**
 * @brief Creer un Stack (Pile)
 *
 * @param capacity - La taille maximum de cette pile
 * @return stack_t*
 */
stack_t * createStack(int capacity)
{
    stack_t * stack = malloc(sizeof(*stack));
    stack->capacity = capacity;
    stack->top      = -1;
    stack->base     = malloc(capacity * sizeof(T));
    return stack;
}

/**
 * @brief Affiche le contenue de la pile
 *
 * @param stack stack_t* - La pile a afficher
 */
void displayStack(stack_t * stack)
{
    for(int i = 0; i < stack->top + 1; i++)
    {
        printf("%d \n", stack->base[i]);
    }
}

/**
 * @brief Ajoute un element a la fin (au dessus) de la pile.
 * Retourne 1 si l'ajout ete effectue correctement
 *
 * @param stack stack_t* - La pile auquelle on veut ajouter un element
 * @param t T - L'element que l'on veut ajouter
 * @return int - Si l'ajout a ete effectue avec succes
 */
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

/**
 * @brief Supprime le premier element de la pile (element du dessus de la pile /
 * element de la fin du tableau). Renvoie 1 si la suppression a ete correctement
 * effectuee
 *
 * @param stack stack_t* - La pile dont on veut supprimer l'element du dessus
 * @return int - Si la suppression a ete effectue avec succes
 */
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

/**
 * @brief Retourne l'element du dessus de la pile sans le supprimer.
 * Retourne NULL si la pile est vide.
 * Si on avait utilise des structures on aurait pu retourner NULL ce qui aurait
 * ete plus adapte.
 *
 * @param stack stack_t* - La pile dont on veut voir l'element du dessus
 * @return T
 */
T peek(stack_t * stack)
{
    T t;
    if(isEmptyStack(stack))
    {
        t = NULL;
    }
    else
    {
        t = stack->base[stack->top];
    }

    return t;
}

/**
 * @brief Si la pile est vide ou pas
 *
 * @param stack stack_t
 * @return int - 1 si la pile est vide, 0 sinon
 */
int isEmptyStack(stack_t * stack)
{
    int success = 0;
    if(stack->top == -1)
    {
        success = 1;
    }
    return success;
}

/**
 * @brief Libere la pile
 *
 * @param stack stack_t* - La pile que l'on veut liberer
 */
void freeStack(stack_t * stack)
{

    for(int i = 0; i < stack->top; i++)
    {
        free(stack->base[i]);
    }
    free(stack->base);
    free(stack);
    stack = NULL;
}