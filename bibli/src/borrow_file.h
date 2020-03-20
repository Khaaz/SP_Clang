#ifndef BORROW_FILE_H
#define BORROW_FILE_H

#include "./borrow/borrow.h"
#include "lib/lib.h"

int        loadBorrow(char *, borrow_t**, category_t *);
int        saveBorrow(char *, borrow_t*);
int        addBorrowFromFile(char *, borrow_t **, category_t *);
int        removeBorrowFromFile(char *, borrow_t **, category_t *);

#endif