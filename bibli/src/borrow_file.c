#include "borrow_file.h"

/**
 * @brief Charge tous les emprunts depuis un ficher
 * 
 * @param path char* - Le chemin d'acces de ce fichier
 * @param list borrow_t** - La liste des emprunts ou serong charger les emprunts
 * @param lib category_t* - La bibliotheque
 * @return int - Si la fonction a et execute avec succes ou pas
 */
int loadBorrow(char * path, borrow_t** list, category_t * lib)
{
    return addBorrowFromFile(path, list, lib);
}

void saveBorrow()
{}

/**
 * @brief Ajoute des emprunts depuis un fichier.
 * 
 * @param path char* - Le chemin du fichier qui possede la liste des emprunts a ajouter
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

    FILE *     file = fopen(path, "r");
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

// TODO: devrait remettre livre a isTaken = false
/**
 * @brief Supprime des emprunts depuis un fichier.
 * 
 * @param path char* - Le chemin du fichier qui possede la liste des emprunts a supprimer
 * @param borrow borrow_t - La liste des emprunts
 * @param lib category_t* - La bibliotheque
 * @return int - Si la fonction a et execute avec succes ou pas 
 */
int removeBorrowFromFile(char * path, borrow_t ** borrow, category_t * lib)
{
    int    success = 1;
    int    number = 0;
    FILE * file = fopen(path, "r");
    if(file != NULL)
    {
        while(!feof(file))
        {
            fscanf(file, "%d", &number);
            printf("\n numero a supprime : %d", number);
            removeBorrow(borrow, number);
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

void saveBooks()
{}