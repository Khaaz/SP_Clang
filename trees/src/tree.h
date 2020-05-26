#include <stdio.h>
#include <stdlib.h>

#ifndef _INCL_GUARD
#define _INCL_GUARD

/**
 * @brief Structure Tree. Le noeud (maillon) qui compose notre arbre
 *
 */
typedef struct node
{
    char          value;   // valeur du noeud (une lettre)
    struct node * son;     // pointeur vers l'element file (lien vertical)
    struct node * brother; // pointeur vers l'element frere (lien horizontal)
} node_t;

node_t * createNode(char);
node_t * createTree(char *);
void     freeTree(node_t *);
void     insertBrother(node_t *, node_t *);
void     insertSon(node_t *, node_t *);
void     getPostfix(node_t *, char *, int *);
void     displayPostfix(char *, int);
node_t * search(node_t *, char);
int      insertion(node_t *, char, char);

#endif