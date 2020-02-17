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

void AddCategorie(categories_t * lib, char name[3], books_t * book)
{
    categories_t * cat = CreateCategorie(name, book);
    lib->next          = cat;
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

void AddFichier(char *path, categories_t *lib)
{
    char chaine[50];
    char category[4];
    char title[11];
    int nbrLivres = 0;
    int number = 0;
    int i;
    FILE *file = fopen(path, "r");
    if (file != NULL)
    {
        while (!feof(file)){
            fread(&category, sizeof(category), 1, file);
            fscanf(file, "%d", &nbrLivres);
            printf("category : %s \n", category);

            printf("nb livres  : %d \n", nbrLivres);
            AddCategorie(lib, category, NULL);
            
            for (i = 0 ;nbrLivres+1; i++)
            {
            printf("passage N %d \n", i);
            fscanf(file, "%d", &number);
            printf("number :   : %d \n", number);
            fgets(title, 12, file);
            printf(" name category : %s\n ", category);
            printf("title  : %s \n", title);
            AddBookWithCategoryName(lib, category, number, title);
            printf("ok \n");
            }



        }
        /*while (!feof(file))
        {
        fgets(category, 4, file);
        fscanf(file, "%d", &nbrLivres);
        printf("categorie : %s \n", category);
        printf("nbr de livres  : %d \n", nbrLivres);
        AddCategorie(lib, category, NULL);
        for (int i = 0; i < nbrLivres; i++)
        {
            fscanf(file, "%d", &number);
            fgets(title, 12, file);
            AddBookWithCategoryName(lib, category, number, title);
        }
        }*/
    }
    else
    {

        printf("erreur");
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
    /*
    categories_t *library = CreateCategorie("FAN", NULL);
    AddBook(library, 3, "La vie de Louis");
    AddBook(library, 1, "la vie de Lucas");
    AddBook(library, 2, "la vie de Max");
    AddBook(library, 4, "la vie de Etiene");
    AddCategorie(library, "ROM", NULL);
    AddBookWithCategoryName(library, "ROM", 2, "Language C");
    AddBookWithCategoryName(library, "ROM", 1, "Language Java");
    AddBookWithCategoryName(library, "ROM", 3, "Language JS");
    */
    categories_t *library = CreateCategorie("FAN", NULL);
    AddFichier(argv[1], library);
    // AfficheBibli(library);

    return 0;
}
