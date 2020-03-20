#ifndef BORROW_H
#define BORROW_H

#include "../main.h"

/**
 * @brief Structure Borrow. Liste chaine d'emprunt.
 */
typedef struct borrow
{
    int             number; // Le numero de l'emprunt
    int             date; // La date de l'emprunt
    struct borrow * next; // L'emprunt suivant
} borrow_t;

borrow_t * initBorrow();
borrow_t * createBorrow(int, int);
void       addNextBorrow(borrow_t **, borrow_t *);
void       addBorrow(borrow_t **, borrow_t *);
void       removeBorrow(borrow_t **, int);
void       displayBorrow(borrow_t *);
void       freeBorrow(borrow_t *);

#endif