#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

categories_t *CreateCategorie(char name[3], books_t *books)
{
    categories_t *cat = malloc(sizeof(*cat));
    strcpy(cat->name, name);
    cat->next = NULL;
    cat->books = books;
    return cat;
}

books_t *CreateBook(int number, char title[10])
{
    books_t *book = malloc(sizeof(*book));
    book->number = number;
    strcpy(book->title, title);
    book->next = NULL;
    book->isTaken = false;
    return book;
}

void AddCategorie(categories_t *lib, char name[3], books_t *book)
{
    categories_t *cat = CreateCategorie(name, book);
    lib->next = cat;
}

int main()
{
    books_t *livre = CreateBook(1, "Harie Pôteure");
    categories_t *library = CreateCategorie("FAN", livre);
    books_t *livre2 = CreateBook(3, "BO2LR");
    AddCategorie(library, "ROM", livre2);
    return 0;
}
