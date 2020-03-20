#include "borrow_file.h"

/**
 * @brief Charge tous les emprunts depuis un ficher
 *
 * @param path char* - Le chemin d'acces de ce fichier
 * @param list borrow_t** - La liste des emprunts ou serong charger les emprunts
 * @param lib category_t* - La bibliotheque
 * @return int - Si la fonction a et execute avec succes ou pas
 */
int loadBorrow(char * path, borrow_t ** list, category_t * lib)
{
    return addBorrowFromFile(path, list, lib);
}

/**
 * @brief Sauvegarde la liste d'emprunt dans le fichier passe en parametre
 *
 * @param path char* - path - Le chemin d'acces du fichier
 * @param list borrow_t* - La liste d'emprunt a sauvegarder
 * @return int
 */
int saveBorrow(char * path, borrow_t * list)
{
    borrow_t * borrow = list;

    int success = 1;

    FILE * file = fopen(path, "w");
    if(file != NULL)
    {
        while(borrow->next != NULL)
        {
            fprintf(file, "%d %d\n", borrow->number, borrow->date);
            borrow = borrow->next;
        }
        fprintf(file, "%d %d", borrow->number, borrow->date);

        fclose(file);
    }
    else
    {
        printf("[ERREUR: fichier] <saveBorrow>.\n");
        success = 0;
    }
    return success;
}

/**
 * @brief Ajoute des emprunts depuis un fichier.
 *
 * @param path char* - Le chemin du fichier qui possede la liste des emprunts a
 * ajouter
 * @param borrow borrow_t** - La liste des emprunts
 * @param lib category_t* - La bibliotheque
 * @return int - Si la fonction a et execute avec succes ou pas
 */
int addBorrowFromFile(char * path, borrow_t ** borrow, category_t * lib)
{
    book_t *   book = NULL;
    borrow_t * b    = NULL;

    int success = 1;
    int number  = 0;
    int date    = 0;

    FILE * file = fopen(path, "r");
    if(file != NULL)
    {
        while(!feof(file))
        {
            fscanf(file, "%d %d", &number, &date);
            book = findBookInLib(lib, number);

            if(book != NULL)
            {
                if(!isBookTaken(book))
                {
                    b = createBorrow(date, number);
                    addBorrow(borrow, b);
                    book->isTaken = true;
                }
                else
                {
                    printf("Le livre N:%d est deja emprunte.\n", number);
                }
            }
            else
            {
                printf("Le livre N:%d n'existe pas.\n", number);
            }
        }
        fclose(file);
    }
    else
    {
        printf("[ERREUR: fichier] <addBorrowFromFile>.\n");
        success = 0;
    }
    return success;
}

/**
 * @brief Supprime des emprunts depuis un fichier.
 *
 * @param path char* - Le chemin du fichier qui possede la liste des emprunts a
 * supprimer
 * @param borrow borrow_t - La liste des emprunts
 * @param lib category_t* - La bibliotheque
 * @return int - Si la fonction a et execute avec succes ou pas
 */
int removeBorrowFromFile(char * path, borrow_t ** borrow, category_t * lib)
{
    book_t * book = NULL;

    int success = 1;
    int number  = 0;

    FILE * file = fopen(path, "r");
    if(file != NULL)
    {
        while(!feof(file))
        {
            fscanf(file, "%d", &number);

            book = findBookInLib(lib, number);
            if(book != NULL)
            {
                printf("Numero a supprime: %d\n", number);
                removeBorrow(borrow, number);
                book->isTaken = false;
            }
            else
            {
                printf("Le livre N:%d n'existe pas.\n", number);
            }
        }
        fclose(file);
    }
    else
    {
        printf("[ERREUR: fichier] <removeBorrowFromFile>.\n");
        success = 0;
    }

    return success;
}