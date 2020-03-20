#ifndef LIB_H
#define LIB_H

#include "../main.h"

typedef struct book
{
    int           number;
    char          title[10];
    boolean       isTaken;
    struct book * next;
} book_t;

typedef struct category
{
    char              name[3];
    book_t *          books;
    struct category * next;
} category_t;

category_t * createLib();
category_t * createCategory(char[3], book_t *);
book_t *     createBook(int, char[10]);
void         addNextCategory(category_t **, category_t *);
void         addNextBook(book_t **, book_t *);
void         addBookInCategory(category_t *, book_t *);
void         addBookInLib(category_t *, book_t *, char *);
book_t *     findBook(book_t *, int);
book_t *     findBookInLib(category_t *, int);
category_t * findCategory(category_t *, char *);
boolean      isBookTaken(book_t *);
void         displayLib(category_t *);

#endif