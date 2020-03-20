#include "borrow.h"

borrow_t * initBorrow() {
    return NULL;
}

borrow_t * createBorrow(int date, int number) {
    borrow_t * borrow = malloc(sizeof(borrow));
    borrow->date      = date;
    borrow->number    = number;
    borrow->next      = NULL;
    return borrow;
}

void addNextBorrow(borrow_t **prev, borrow_t *borrow) {
    borrow->next = *prev;
    *prev = borrow;
}

void addBorrow(borrow_t **list, borrow_t * borrow) {
    borrow_t ** prec   = list;

    while(*prec != NULL && (*prec)->date < borrow->date)
    {
        prec = &((*prec)->next);
    }
    addNextBorrow(prec, borrow);
}

void removeBorrow(borrow_t **list, int number) {

    borrow_t ** prec = list;
    while(*prec != NULL && (*prec)->number != number)
    {
        prec = &((*prec)->next);
    }

    borrow_t * tmp = *prec;
    *prec = (*prec)->next;
    free(tmp);
}

void displayBorrow(borrow_t * borrow)
{
    borrow_t * cour = borrow;
    while(cour != NULL)
    {
        printf(" \n numero livre : %d \n  ", cour->number);
        printf("date de retour : %d ", cour->date);
        cour = cour->next;
    }
}

void freeBorrow(borrow_t * list)
{
    while(list != NULL)
    {
        removeBorrow(&list, list->number);
    }
}

