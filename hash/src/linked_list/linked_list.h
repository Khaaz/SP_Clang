#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdlib.h>

/**
 * @brief Structure Neud pour la liste chainee. Liste chaine de mots.
 */
typedef struct node
{
    char *        word;  // Le mot
    int           count; // Le nombre d'apparition du mot
    struct node * next;  // Le maillon suivant
} node_t;

node_t * initList();
node_t * createNode(char *);
void     addNextNode(node_t **, node_t *);
void     incrementNode(node_t *);
void     displayList(node_t *);
void     freeList(node_t *);
node_t * searchNode(node_t *, char *);

#endif