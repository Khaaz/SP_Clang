#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

/**
 * @brief Creer un objet Queue (File).
 * C'est le pointeur sur le premier element.
 *
 * @param capacity int - Le nombre maximum d'element dans la file
 * @return queue_t*
 */
queue_t * createQueue(int capacity)
{
    queue_t * queue = malloc(sizeof(*queue));

    queue->capacity = capacity;
    queue->size     = 0;
    queue->base     = malloc(capacity * sizeof(T));
    queue->head     = 0;
    queue->tail     = 0;
    return queue;
}

/**
 * @brief Ajoute un element a la fin de la file. Si la file est deja pleine,
 * n'ajoutes pas l'element et renvoie 0
 *
 * @param queue queue_t* - La file ou ajouter un element
 * @param element T - L'element a ajouter
 * @return int - Si l'ajout a ete effectue avec succes
 */
int pushBack(queue_t * queue, T element)
{
    int success = 1;
    if(isFullQueue(queue))
    {
        success = 0;
    }
    else
    {
        if(!isEmptyQueue(queue))
        {
            queue->tail = (queue->tail + 1) % queue->capacity;
        }
        queue->base[queue->tail] = element;
        queue->size += 1;
    }
    return success;
}

/**
 * @brief Enleve le premier element de la file. Si la pile est deja vide,
 * remvoie 0;
 *
 * @param queue queue_t* - La file d'ou enlever l'element
 * @return int - Si la suppression a ete effectue avec succes.
 */
int popFront(queue_t * queue)
{
    int success = 1;
    if(isEmptyQueue(queue))
    {
        success = 0;
    }
    else
    {
        if (queue->size > 1) {
            queue->head = (queue->head + 1) % queue->capacity;
        }
        queue->size -= 1;
    }
    return success;
}

/**
 * @brief Retourne le premier element de la file sans le supprimer.
 *
 * @param queue queue_t* - La file dont on veut regarder le premier element
 * @return T - Le premier element de la file
 */
T front(queue_t * queue)
{
    T element;
    if(isEmptyQueue(queue))
    {
        element = NULL;
    }
    element = queue->base[queue->head];
    return element;
}

/**
 * @brief Si la file est vide ou pas
 *
 * @param queue queue_t* - La file dont on veut savoir si elle est vide
 * @return int - Si la file est vide (0 si non, 1 si oui)
 */
int isEmptyQueue(queue_t * queue)
{
    int empty = 0;
    if(queue->size == 0)
    {
        empty = 1;
    }
    return empty;
}

/**
 * @brief Si la file est pleine ou pas
 *
 * @param queue queue_t* - La file dont on veut savoir si elle est pleine
 * @return int - Si la file est pleine (0 si non, 1 si oui)
 */
int isFullQueue(queue_t * queue)
{
    int full = 0;
    if(queue->size == queue->capacity)
    {
        full = 1;
    }
    return full;
}

/**
 * @brief Libere la file
 *
 * @param queue queue_t* - La queue que on libere.
 */
void freeQueue(queue_t * queue)
{
    int i = queue->head;
    while(i != queue->tail)
    {
        free(queue->base[i]);
        i = (i + 1) % queue->capacity;
    }
    free(queue->base);
    free(queue);
    queue = NULL;
}
