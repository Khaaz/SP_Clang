#include "borrow.h"
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

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

borrow_t * initBorrow(int date, int number)
{
    borrow_t * bow = malloc(sizeof(bow));
    bow->date      = date;
    bow->number    = number;
    bow->next      = NULL;
    return bow;
}

tete_t * initTete()
{
    tete_t * tete = malloc(sizeof(*tete));
    tete->first   = NULL;
    return tete;
}
/*
borrow_t * AddBorrowFromFile(borrow_t * bow, char * path, categories_t * lib)
{
    int       number = 0, date = 0;
    books_t * book;
    FILE *    file = fopen(path, "r");
    if(file != NULL)
    {

        while(!feof(file))
        {
            fscanf(file, "%d %d", &number, &date);
            book = existBook(number, lib);
            if(book != NULL)
            {
                if(isTaken(book) == 0)
                {

                    bow           = AddBorrow(bow, date, number);
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
    return bow;
}
*/
void AddBorrow(tete_t * tete, int date, int number)
{
    borrow_t *  borrow = initBorrow(date, number); // next à NULL
    borrow_t ** prec   = &(tete->first);
    printf("ok1");
    borrow_t * cour = tete->first;
    // printf("cour : %p\n", cour);

    while(cour != NULL && cour->date < date)
    {
        // prec = &(cour->next);
        cour = cour->next;
        prec = &((*prec)->next);
    }
    printf("issou\n%p\n%p\n%p\n%p\n", borrow, borrow->next, *prec, cour);

    borrow->next = cour;
    (*prec)      = borrow;
}

borrow_t * removeBorrow(borrow_t * bow, int num)
{
    if(bow->number == num)
    {

        borrow_t * cour = bow->next;
        borrow_t * prec = bow;
        free(prec);
        return cour;
    }
    else
    {
        borrow_t * prec = bow;
        while(prec->next->number != num)
        {
            prec = prec->next;
        }
        if(prec->next->next == NULL)
        {
            free(prec->next);
            prec->next = NULL;
            return bow;
        }
        else
        {
            borrow_t * cour = prec->next->next;
            free(prec->next);
            prec->next = cour;
            return bow;
        }
    }
}

borrow_t * removeBorrowFromFile(borrow_t * bow, char * path)
{
    int    number;
    FILE * file = fopen(path, "r");
    if(file != NULL)
    {
        fscanf(file, "%d", &number);

        while(!feof(file))
        {
            printf("\n numero a supprime : %d", number);
            bow = removeBorrow(bow, number);
            fscanf(file, "%d", &number);
        }
        fclose(file);
    }
    return bow;
}

int main()
{

    tete_t * tete = initTete();
    AddBorrow(tete, 20201111, 15);
    AfficheBorrow(tete->first);
    // printf("ok5");
    AddBorrow(tete, 20191111, 13);
    AfficheBorrow(tete->first);
    AddBorrow(tete, 20181211, 20);

    // borrow_t * borrow = initBorrow();
    // AddBorrow(borrow, 20201112, 15);
    // AddBorrow(borrow, 20181215, 13);
    // AddBorrow(borrow, 20191111, 16);
    AfficheBorrow(tete->first);
    return 0;
}
