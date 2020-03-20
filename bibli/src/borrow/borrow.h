#ifndef BORROW_H
#define BORROW_H

#include "../main.h"

typedef struct borrow
{
    int             number;
    int             date;
    struct borrow * next;
} borrow_t;

borrow_t * initBorrow();
borrow_t * createBorrow(int, int);
void       addNextBorrow(borrow_t **, borrow_t *);
void       addBorrow(borrow_t **, borrow_t *);
void       removeBorrow(borrow_t **, int);
void       displayBorrow(borrow_t *);

#endif