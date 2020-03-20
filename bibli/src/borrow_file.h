#ifndef BORROW_FILE_H
#define BORROW_FILE_H

#include "./borrow/borrow.h"
#include "lib/lib.h"

borrow_t * loadBorrow(char *);

void saveBorrow();

int addBorrowFromFile(char*, borrow_t *, category_t *);


int removeBorrowFromFile(char* , borrow_t * , category_t * );

void saveBooks();

#endif