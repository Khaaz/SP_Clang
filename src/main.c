#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void AfficheBibli(categories_t * library)
{
    categories_t * cour1 = library;
    while(cour1 != NULL)
    {
        printf(" \n Categorie : %s : ", cour1->name);
        books_t * cour2 = cour1->books;
        while(cour2 != NULL)
        {
            printf(" \n livre N %d : %s", cour2->number, cour2->title);
            cour2 = cour2->next;
        }
        cour1 = cour1->next;
    }
}

categories_t * CreateCategorie(char name[3], books_t * books)
{
    categories_t * cat = malloc(sizeof(*cat));
    strcpy(cat->name, name);
    cat->next  = NULL;
    cat->books = books;
    return cat;
}

books_t * CreateBook(int number, char title[10])
{
    books_t * book = malloc(sizeof(*book));
    book->number   = number;
    strcpy(book->title, title);
    book->next    = NULL;
    book->isTaken = false;
    return book;
}

categories_t * AddCategorie(categories_t * lib, char name[3], books_t * book)
{
    categories_t * cat = CreateCategorie(name, book);
    if(lib->next == NULL)
    {
        lib->next = cat;
    }
    else
    {
        cat->next = lib->next;
        lib->next = cat;
    }

    return cat;
}

void AddBook(categories_t * Cat, int number, char title[10])
{

    books_t * book = malloc(sizeof(*book));
    book->number   = number;
    strcpy(book->title, title);

    if(Cat->books == NULL)
    {
        Cat->books = book;
        book->next = NULL;
    }
    else if(Cat->books->number > number)
    {
        book->next = Cat->books;
        Cat->books = book;
    }
    else
    {
        books_t * prec = Cat->books;
        while(prec->next != NULL && (prec->next->number <= number))
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

void AddBookWithCategoryName(categories_t * lib, char name[3], int number,
                             char title[10])
{
    categories_t * cour = lib;
    while(strcmp(cour->name, name) != 0)
    {
        cour = cour->next;
    }
    AddBook(cour, number, title);
}

void AddFichier(char * path, categories_t * lib)
{
    categories_t * cat;
    char           category[4];
    char           title[11];
    int            nbrLivres = 0;
    int            number    = 0;
    int            i;
    FILE *         file = fopen(path, "r");
    if(file != NULL)
    {
        fscanf(file, "%s %d", category, &nbrLivres);
        while(!feof(file))
        {
            cat = AddCategorie(lib, category, NULL);
            for(i = 0; i < nbrLivres; i++)
            {
                fscanf(file, "%d", &number);
                fgets(title, 12, file);
                AddBook(cat, number, title);
            }
            fscanf(file, "%s %d", category, &nbrLivres);
        }
        fclose(file);
    }
    else
    {

        printf("erreur");
    }
}
borrow_t * initBorrow()
{
    borrow_t * bow = malloc(sizeof(bow));
    bow->date      = 0;
    bow->number    = 0;
    bow->next      = NULL;
    return bow;
}
books_t * existBook(int number, categories_t * lib)
{
    categories_t * cour = lib;
    while(cour != NULL)
    {
        books_t * cour2 = cour->books;
        while(cour2 != NULL)
        {
            if(cour2->number == number)
            {
                return cour2;
            }
            else
            {
                cour2 = cour2->next;
            }
        }
        cour = cour->next;
    }
    return NULL;
}

void AddBorrowFromFile(borrow_t * bow, char * path, categories_t * lib)
{
    int       number = 0;
    char      annee[5], mois[3], jour[3], date[11];
    books_t * book;
    FILE *    file = fopen(path, "r");
    if(file != NULL)
    {
        fscanf(file, "%d %s %s %s", &number, annee, mois, jour);

        while(!feof(file))
        {

            book = existBook(number, lib);
            if(book != NULL)
            {
                book->isTaken = true;
                strcpy(date, annee);
                strcat(date, strcat(mois, jour));
                bow = AddBorrow(bow, atoi(date), number);
            }
            else
            {
                printf("le livre n'existe pas\n");
            }
            fscanf(file, "%d %s %s %s", &number, annee, mois, jour);
        }
        fclose(file);
    }
}
borrow_t * AddBorrow(borrow_t * bow, int date, int number)
{

    if(bow->date == 0)
    {
        bow->date   = date;
        bow->number = number;
        return bow;
    }
    else
    {
        borrow_t * borrow = malloc(sizeof(*borrow));
        borrow->number    = number;
        borrow->date      = date;
        borrow->next      = NULL;
        if(bow->date > date)
        {
            borrow->next = bow;
            return borrow;
        }
        else
        {

            borrow_t * prec = bow;

            while(prec->next != NULL && prec->next->date < date)
            {
                prec = prec->next;
            }
            if(prec->next == NULL)
            {
                prec->next = borrow;
                return bow;
            }
            else
            {
                borrow->next = prec->next;
                prec->next   = borrow;
                return bow;
            }
        }
    }
}
void AfficheBorrow(borrow_t * bow)
{
    borrow_t * cour = bow;
    while(cour != NULL)
    {
        printf(" \n numero livre : %d \n  ", cour->number);
        printf("date de retour : %d ", cour->date);
        cour = cour->next;
    }
}

int main(int argc, char ** argv)
{ /*
        books_t *livre = CreateBook(1, "Harie Pôteure");
        categories_t *library = CreateCategorie("FAN", livre);
        books_t *livre2 = CreateBook(3, "BO2LR");
        AddCategorie(library, "ROM", livre2);
        categories_t *TES = CreateCategorie("LOL", livre);
        AddBook(TES, 15, "Maxime");
        */

    categories_t * library = CreateCategorie("FAN", NULL);
    AddBook(library, 3, "La vie de Louis");
    AddBook(library, 1, "la vie de Lucas");
    AddBook(library, 2, "la vie de Max");
    AddBook(library, 4, "la vie de Etiene");
    AddCategorie(library, "ROM", NULL);
    AddBookWithCategoryName(library, "ROM", 18, "Language C");
    AddBookWithCategoryName(library, "ROM", 13, "Language Java");
    AddBookWithCategoryName(library, "ROM", 25, "Language JS");
    // AfficheBibli(library);
    // printf("\nexist book : %d", existBook(25, library));

    // categories_t * library = CreateCategorie("FAN", NULL);
    borrow_t * bow = initBorrow();
    AddBorrowFromFile(bow, argv[1], library);

    AfficheBorrow(bow);

    // AddBorrowFromFile(bow, argv[1], library);
    // AddFichier(argv[1], library);
    // AfficheBibli(library);

    return 0;
}
