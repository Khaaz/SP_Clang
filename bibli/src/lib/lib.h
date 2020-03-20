#ifndef LIB_H
#define LIB_H

#include "../main.h"

/**
 * @brief Structure Book. List chainee de livre triee en fonction des numero de livre.
 * 
 */
typedef struct book
{
    int           number; // Le numero du livre
    char          title[10]; // Le titre du livre
    boolean       isTaken; // Si le livre est emprunte ou pas
    struct book * next; // Le livre suivant
} book_t;

/**
 * @brief Structure Category. Liste chainee de categorie.
 * 
 */
typedef struct category
{
    char              name[3]; // Le nom de la categorie
    book_t *          books; // La liste de livre de cette categorie
    struct category * next; // La categorie suivante
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
void         removeBook(book_t **, int);
void         removeCategory(category_t **, char *);
void         freeLib(category_t *);

#endif