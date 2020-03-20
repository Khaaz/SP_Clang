#include "main.h"
#include "borrow_file.h"
#include "lib_file.h"

#include "borrow/borrow.h"
#include "lib/lib.h"

int main(int argc, char ** argv)
{
    category_t * lib = loadLib(argv[1]);

    // displayLib(library);

    borrow_t * borrow = loadBorrow("test");
    displayBorrow(borrow);
    addBorrowFromFile(argv[2], borrow, lib);
    displayBorrow(borrow);
    freeBorrow(borrow);
    //removeBorrowFromFile(argv[3], borrow, lib);

    // borrow_t * list = initBorrow();
    // borrow_t * borrow = createBorrow(20201111, 15);

    // addBorrow(&list, borrow);

    // borrow_t * borrow2 = createBorrow(20191111, 13);
    // addBorrow(&list, borrow2);

    // borrow_t * borrow3 = createBorrow(20211211, 20);
    // addBorrow(&list, borrow3);
    // borrow_t * borrow4 = createBorrow(20151111, 23);
    // addBorrow(&list, borrow4);

    // removeBorrow(&list, 20);

    // displayBorrow(list);
    // printf("ok");

    // init bibli from file (file via argv)
    // init borrow from file
    // save borrow in file
    // remove borrow from file
    // add borrow from file
    // save borrow in file
    // save book return date < date given

    /*
        book_t *livre = CreateBook(1, "Harie Pôteure");
        category_t *library = CreateCategorie("FAN", livre);
        book_t *livre2 = CreateBook(3, "BO2LR");
        AddCategorie(library, "ROM", livre2);
        category_t *TES = CreateCategorie("LOL", livre);
        AddBook(TES, 15, "Maxime");
        */

    // category_t * library = CreateCategorie("FAN", NULL);

    // AddBook(library, 3, "La vie de Louis");
    // AddBook(library, 1, "la vie de Lucas");
    // AddBook(library, 2, "la vie de Max");
    // AddBook(library, 4, "la vie de Etiene");
    // AddCategorie(library, "ROM", NULL);
    // AddBookWithCategoryName(library, "ROM", 18, "Language C");
    // AddBookWithCategoryName(library, "ROM", 13, "Language Java");
    // AddBookWithCategoryName(library, "ROM", 25, "Language JS");
    // AfficheBibli(library);
    // printf("\nexist book : %d", existBook(25, library));

    // category_t * library = CreateCategorie("FAN", NULL);
    // borrow_t * bow = initBorrow();
    // bow            = AddBorrowFromFile(bow, argv[1], library);

    // AfficheBorrow(bow);

    // bow = removeBorrowFromFile(bow, argv[2]);
    // printf("\n ok \n");
    // AfficheBorrow(bow);
    // AddBorrowFromFile(bow, argv[1], library);
    // AddFichier(argv[1], library);
    // AfficheBibli(library);
    return 0;
}