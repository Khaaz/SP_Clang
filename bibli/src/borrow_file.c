#include "borrow_file.h"

/**
 * @brief 
 * 
 * @param path 
 * @param list 
 * @return int - Si la fonction a et execute avec succes ou pas
 */
int loadBorrow(char * path, borrow_t** list)
{
    borrow_t * borrow = createBorrow(20201111, 15);

    addBorrow(list, borrow);

    borrow_t * borrow2 = createBorrow(20191111, 13);
    addBorrow(list, borrow2);

    borrow_t * borrow3 = createBorrow(20211211, 20);
    addBorrow(list, borrow3);
    borrow_t * borrow4 = createBorrow(20151111, 23);
    addBorrow(list, borrow4);

    removeBorrow(list, 20);
    return 1;
    // int success = 1;
    // int number  = 0;
    // int date    = 0;

    // book_t *   book = NULL;
    // borrow_t * b    = NULL;
    // FILE *     file = fopen(path, "r");
    // if(file != NULL)
    // {
    //     while(!feof(file))
    //     {
    //         fscanf(file, "%d %d", &number, &date);
    //         book = findBookInLib(lib, number);

    //         if(book != NULL)
    //         {
    //             if(!isBookTaken(book))
    //             {
    //                 b = createBorrow(date, number);
    //                 addBorrow(&borrow, b);
    //                 book->isTaken = true;
    //             }
    //             else
    //             {
    //                 printf("le livre N %d est deja emprunte\n", number);
    //             }
    //         }
    //         else
    //         {
    //             printf("le livre N %d n'existe pas:  \n", number);
    //         }
    //     }
    //     fclose(file);
    // }
    // else
    // {
    //     printf("[ERREUR: fichier] <loadBorrow>.\n");
    //     success = 0;
    // }
    // return success;
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