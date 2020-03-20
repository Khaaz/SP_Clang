#include "borrow_file.h"

borrow_t * loadBorrow(char * file)
{
    borrow_t * list   = initBorrow();
    borrow_t * borrow = createBorrow(20201111, 15);

    addBorrow(&list, borrow);

    borrow_t * borrow2 = createBorrow(20191111, 13);
    addBorrow(&list, borrow2);

    borrow_t * borrow3 = createBorrow(20211211, 20);
    addBorrow(&list, borrow3);
    borrow_t * borrow4 = createBorrow(20151111, 23);
    addBorrow(&list, borrow4);

    removeBorrow(&list, 20);
    return list;
}

void saveBorrow()
{}

int addBorrowFromFile(char * path, borrow_t * borrow, category_t * lib)
{
    int success = 1;
    int number  = 0;
    int date    = 0;

    book_t *   book = NULL;
    borrow_t * b    = NULL;
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
                    addBorrow(&borrow, b);
                    book->isTaken = true;
                }
                else
                {
                    printf("le livre N %d est deja emprunte\n", number);
                }
            }
            else
            {
                printf("le livre N %d n'existe pas:  \n", number);
            }
        }
        fclose(file);
    }
    else
    {
        printf("ERREUR ouverture fichier");
        success = 0;
    }
    return success;
}

// TODO: devrait remettre livre a isTaken = false
int removeBorrowFromFile(char * path, borrow_t * borrow, category_t * lib)
{
    int    success = 1;
    int    number;
    FILE * file = fopen(path, "r");
    if(file != NULL)
    {
        while(!feof(file))
        {
            fscanf(file, "%d", &number);
            printf("\n numero a supprime : %d", number);
            removeBorrow(&borrow, number);
        }
        fclose(file);
    }
    else
    {
        printf("ERREUR ouverture fichier");
        success = 0;
    }

    return success;
}

void saveBooks()
{}