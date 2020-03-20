#include "borrow.h"

/**
 * @brief Initialise une liste d'emprunt.
 *
 * @return borrow_t*
 */
borrow_t * initBorrow()
{
    return NULL;
}

/**
 * @brief Creer un emprunt
 *
 * @param date int - La date de l'emprunt
 * @param number int - Le numero de l'emprunt
 * @return borrow_t*
 */
borrow_t * createBorrow(int date, int number)
{
    borrow_t * borrow = malloc(sizeof(*borrow));
    if(borrow != NULL)
    {
        borrow->date   = date;
        borrow->number = number;
        borrow->next   = NULL;
    }
    else
    {
        printf("[ERREUR: malloc] <createBorrow>.\n");
    }
    return borrow;
}

/**
 * @brief Ajoute un emprunt a la suite d'un autre emprunt dans la liste.
 *
 * @param prev borrow_t** - L'emprunt precedent
 * @param borrow borrow_t* - L'emprunt a ajouter
 */
void addNextBorrow(borrow_t ** prev, borrow_t * borrow)
{
    borrow->next = *prev;
    *prev        = borrow;
}

/**
 * @brief Ajoute un emprunt dans la liste d'emprunt trie par date
 *
 * @param list borrow_t** - La liste des emprunts
 * @param borrow borrow* - L'emprunt a ajouter
 */
void addBorrow(borrow_t ** list, borrow_t * borrow)
{
    borrow_t ** prec = list;

    while(*prec != NULL && (*prec)->date < borrow->date)
    {
        prec = &((*prec)->next);
    }
    addNextBorrow(prec, borrow);
}

/**
 * @brief Supprime un emprunt de la liste des emprunts
 *
 * @param list borrow_t** - La liste des emprunts
 * @param number int - Le numero de l'emprunt a supprimer
 */
void removeBorrow(borrow_t ** list, int number)
{

    borrow_t ** prec = list;
    while(*prec != NULL && (*prec)->number != number)
    {
        prec = &((*prec)->next);
    }

    borrow_t * tmp = *prec;
    *prec          = (*prec)->next;
    free(tmp);
}

/**
 * @brief Affiche la liste d'emprunt
 *
 * @param borrow borrow_t* La liste des emprunts
 */
void displayBorrow(borrow_t * borrow)
{
    borrow_t * cour = borrow;
    while(cour != NULL)
    {
        printf("Numero livre : %d\n", cour->number);
        printf("Date de retour : %d\n", cour->date);
        cour = cour->next;
    }
}

/**
 * @brief Libere la liste des emprunts
 *
 * @param list borrow_t* - La liste des emnprunts
 */
void freeBorrow(borrow_t * list)
{
    while(list != NULL)
    {
        removeBorrow(&list, list->number);
    }
}
