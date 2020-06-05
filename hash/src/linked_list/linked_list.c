#include "linked_list.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief Initialise une liste chainee de mots.
 *
 * @return node_t*
 */
node_t * initList()
{
    return NULL;
}

/**
 * @brief Creer un noeud
 *
 * @param word char* - Le mot
 * @return node_t*
 */
node_t * createNode(char * word)
{
    node_t * node = malloc(sizeof(*node));
    if(node != NULL)
    {
        node->word = malloc(strlen(word) * sizeof(char));
        if (node->word != NULL) {
            strcpy(node->word, word);
            node->count = 1;
            node->next  = NULL;
        } else {
            printf("[ERREUR: malloc] <linked_list: createNode/word>.\n");    
        }
    }
    else
    {
        printf("[ERREUR: malloc] <linked_list: createNode>.\n");
    }
    return node;
}

/**
 * @brief Incremente le nombre d'occurence du mot de ce noeud
 *
 * @param node
 */
void incrementNode(node_t * node)
{
    ++node->count;
}

/**
 * @brief Ajoute un neodu a la suite d'un autre noeud dans la liste.
 *
 * @param prev node_t** - Le noeud precedent
 * @param node node_t* - Le noeud a ajouter
 */
void addNextNode(node_t ** prev, node_t * node)
{
    node->next = *prev;
    *prev      = node;
}

/**
 * @brief Affiche la liste d'emprunt
 *
 * @param list node_t* La liste
 */
void displayList(node_t * list)
{
    node_t * cur = list;
    while(cur != NULL)
    {
        printf("Mot : %s\n", cur->word);
        printf("Nombre d'apparition : %d\n", cur->count);
        cur = cur->next;
    }
}

/**
 * @brief Libere la liste
 *
 * @param list node_t* - La liste
 */
void freeList(node_t * list)
{
    node_t * tmp = NULL;
    while(list != NULL)
    {
        tmp = list->next;
        free(list->word);
        free(list);
        list = tmp;
    }
}

node_t * searchNode(node_t* list, char* word) 
{
    node_t * cour = list;
    while (cour != NULL && strcmp(cour->word, word) != 0)
    {
        cour = cour->next;
    }
    return cour;
}