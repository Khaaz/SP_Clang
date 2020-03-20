#include "lib.h"
 
//
// CREATE
//

category_t * createLib() {
    return NULL;
}

category_t * createCategory(char name[3], book_t * books) {
    category_t * cat = malloc(sizeof(*cat));
    if (cat != NULL) {
    strcpy(cat->name, name);
    cat->next  = NULL;
    cat->books = books;
    } else {
        printf("ERREUR malloc createCategory");
    }
    return cat;
}

book_t * createBook(int number, char title[10]) {
    book_t * book = malloc(sizeof(*book));
    if (book != NULL) {
    book->number   = number;
    strcpy(book->title, title);
    book->next    = NULL;
    book->isTaken = false;
    } else {
        printf("ERREUR malloc createBook");
    }
    return book;
}

//
// ADD
//

void addNextCategory(category_t **prev, category_t *toAdd) {
    toAdd->next = *prev;
    *prev = toAdd;
}

void addNextBook(book_t **prev, book_t *toAdd ) {
    toAdd->next = *prev;
    *prev = toAdd;
}

// TODO: refaire ca
void addBookInCategory(category_t *category, book_t *book) {
    if(category->books == NULL)
    {
        category->books = book;
        book->next = NULL;
    }
    else if(category->books->number > book->number)
    {
        book->next = category->books;
        category->books = book;
    }
    else
    {
        book_t * prec = category->books;
        while(prec->next != NULL && (prec->next->number <= book->number))
        {
            prec = prec->next;
        }
        if(prec->next == NULL)
        {
            book->next = NULL;
            prec->next = book;
        }
        else
        {
            book->next = prec->next;
            prec->next = book;
        }
    }
}

void addBookInLib(category_t *lib, book_t *book, char* categoryName) {
    category_t * category = findCategory(lib, categoryName);
    addBookInCategory(category, book);
}


// TODO remove
void removeBook() {

}


//
// find
//

book_t * findBook(book_t * book, int bookNumber) {
    book_t * cour = book;
    while(cour != NULL && cour->number != bookNumber)
    {
        cour = cour->next;
    }
    return cour;
}

book_t * findBookInLib(category_t * lib, int bookNumber) {
    category_t * cour = lib;
    book_t *result = NULL;
    while(cour != NULL && result == NULL)
    {
        result = findBook(cour->books, bookNumber);
        cour = cour->next;
    }
    return result;
}

category_t * findCategory(category_t * lib, char* categoryName) {
    category_t * cour = lib;

    while(cour != NULL && (strcmp(cour->name,categoryName) != 0) )
    {
        cour = cour->next;
    }
    return cour;
}

boolean isBookTaken(book_t *book) {
    return book->isTaken;
}

void displayLib(category_t * library)
{
    category_t * cour1 = library;
    while(cour1 != NULL)
    {
        printf(" \n Categorie : %s : ", cour1->name);
        book_t * cour2 = cour1->books;
        while(cour2 != NULL)
        {
            printf(" \n livre N %d : %s", cour2->number, cour2->title);
            cour2 = cour2->next;
        }
        cour1 = cour1->next;
    }
}
