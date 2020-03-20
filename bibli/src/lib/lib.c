#include "lib.h"

//
// CREATE
//

/**
 * @brief Creer une bibliotheque
 * 
 * @return category_t* 
 */
category_t * createLib()
{
    return NULL;
}

/**
 * @brief Creer une categorie
 * 
 * @param name char[3] - Le nom de la categorie
 * @param books book_t* - La liste des livres pour cette categorie (peut etre NULL)
 * @return category_t* 
 */
category_t * createCategory(char name[3], book_t * books)
{
    category_t * cat = malloc(sizeof(*cat));
    if(cat != NULL)
    {
        strcpy(cat->name, name);
        cat->next  = NULL;
        cat->books = books;
    }
    else
    {
        printf("[ERREUR: malloc] <createCategory>.\n");
    }
    return cat;
}

/**
 * @brief Creer un livre
 * 
 * @param number int - Le numero du livre
 * @param title char[10] - Le titre du livre
 * @return book_t* 
 */
book_t * createBook(int number, char title[10])
{
    book_t * book = malloc(sizeof(book_t));
    if(book != NULL)
    {
        book->number = number;
        strcpy(book->title, title);
        book->next    = NULL;
        book->isTaken = false;
    }
    else
    {
        printf("[ERREUR: malloc] <createBook>.\n");
    }
    return book;
}

//
// ADD
//

/**
 * @brief Ajoute une categorie a la suite d'une categorie
 * 
 * @param prev category_t** - La categorie precedente
 * @param toAdd category_t* - La categorie a ajouter
 */
void addNextCategory(category_t ** prev, category_t * toAdd)
{
    toAdd->next = *prev;
    *prev       = toAdd;
}

/**
 * @brief Ajoute un livre a la suite d'un livre
 * 
 * @param prev book_t** - Le livre precedent
 * @param toAdd book_t* - Le livre a ajouter
 */
void addNextBook(book_t ** prev, book_t * toAdd)
{
    toAdd->next = *prev;
    *prev       = toAdd;
}

// TODO: refaire ca
/**
 * @brief Ajoute un livre dans une categorie. Trouve l'endroit ou ajouter le livre (liste triee)
 * 
 * @param category category_t* - La categorie dans laquelle on ajoute le livre
 * @param book category_t* - Le livre a ajouter
 */
void addBookInCategory(category_t * category, book_t * book)
{
    if(category->books == NULL)
    {
        category->books = book;
        book->next      = NULL;
    }
    else if(category->books->number > book->number)
    {
        book->next      = category->books;
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

/**
 * @brief Ajoute un libre dans la bibliotheque via le nom de la categorie dans laquelle l'ajouter
 * 
 * @param lib category_t* - La bibliotheque
 * @param book book_t* - Le livre a ajouter
 * @param categoryName char* - Le nom de la categorie dans laquelle on ajouter le livre
 */
void addBookInLib(category_t * lib, book_t * book, char * categoryName)
{
    category_t * category = findCategory(lib, categoryName);
    addBookInCategory(category, book);
}

// TODO remove
void removeBook()
{}

//
// find
//

/**
 * @brief Trouve un livre dans une liste de livre. Renvoie NULL si le livre n'existe pas
 * 
 * @param book book_t* - La liste de livre ou chercher
 * @param bookNumber int - Le numero du livre a chercher
 * @return book_t* 
 */
book_t * findBook(book_t * book, int bookNumber)
{
    book_t * cour = book;
    while(cour != NULL && cour->number != bookNumber)
    {
        cour = cour->next;
    }
    return cour;
}

/**
 * @brief Trouve un livre dans la bibliotheque. Cherche dans toutes les categories. Renvoie NULL si le livre n'existe pas
 * 
 * @param lib category_t* - La bibliotheque
 * @param bookNumber int - Le numero du livre
 * @return book_t* 
 */
book_t * findBookInLib(category_t * lib, int bookNumber)
{
    category_t * cour   = lib;
    book_t *     result = NULL;
    while(cour != NULL && result == NULL)
    {
        result = findBook(cour->books, bookNumber);
        cour   = cour->next;
    }
    return result;
}

/**
 * @brief Trouve une categorie avec son nom. Renvoie NULL si la categorie n'existe pas
 * 
 * @param lib category_t* - La bibliotheque
 * @param categoryName char* - Le nom de la categorie a trouver
 * @return category_t* 
 */
category_t * findCategory(category_t * lib, char * categoryName)
{
    category_t * cour = lib;

    while(cour != NULL && (strcmp(cour->name, categoryName) != 0))
    {
        cour = cour->next;
    }
    return cour;
}

/**
 * @brief Si un livre est emprunte ou pas
 * 
 * @param book book_t* - Le livre qu'on veut tester
 * @return boolean 
 */
boolean isBookTaken(book_t * book)
{
    return book->isTaken;
}

/**
 * @brief Affiche la bibliotheque
 * 
 * @param library category_t* - La bibliotheque 
 */
void displayLib(category_t * library)
{
    category_t * courLib = library;
    book_t * courBook = NULL;
    
    while(courLib != NULL)
    {
        printf("\nCategorie: %s\n", courLib->name);
        courBook = courLib->books;
        while(courBook != NULL)
        {
            printf("Livre num %d : %s\n", courBook->number, courBook->title);
            courBook = courBook->next;
        }
        courLib = courLib->next;
    }
}
