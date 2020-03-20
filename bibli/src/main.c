#include "main.h"
#include "borrow_file.h"
#include "lib_file.h"

#include "borrow/borrow.h"
#include "lib/lib.h"
void test_lib(){
    
    category_t * lib =createLib ();
    book_t * book = createBook(6, "Harry Potter");
    book_t * book2 = createBook(12, "Le grand Bleu"); //insertion en fin
    book_t * book3 = createBook(5, "Face-BOOK");        //insertion au début
    book_t * book4 = createBook(10, "Le C pour les nuls");  //insertion au milieu
    category_t * POL = createCategory("POL", book);
    addNextCategory(&lib, POL);
    addNextBook(&(book->next), book2);
    addBookInCategory(POL, book3);
    addBookInCategory(POL, book4);
    displayLib(lib);
    printf("\ntest fonction finBook : avec le livre numéro 12 : \n");
    book_t * Fbook = findBook(book, 12);
    printf("on obtient le livre : %s  : \n\n", Fbook->title);
    printf("test fonction finBookInlib : avec le livre numéro 5 : \n");
    book_t * Fbook2 = findBookInLib(POL, 5);
    printf("on obtient le livre %s : \n \n", Fbook2->title);
    printf("On recherche la categorie POL avec la fonction findCategory : \n");
    category_t * FPOL = findCategory(POL, "POL");
    printf("On obtient la categorie : %s \n \n", FPOL->name);
    printf("test de la fonction isBookTaken avec le livre N°6 : \n");
    printf("la fonction retourne %d car le livre n'est pas emprunté \n", isBookTaken(book));

}

void test_borrow() {
     borrow_t * bow = initBorrow();
    borrow_t * borrow = createBorrow(20201112, 15);
    borrow_t * borrow1 = createBorrow(20221112, 17); //insertion en fin
    borrow_t * borrow2 = createBorrow(20211112, 16); //insertion  au milieu
    borrow_t * borrow3 = createBorrow(20191112, 14);    //insertion au début
    addBorrow(&bow, borrow);
    addBorrow(&bow, borrow1);
    addBorrow(&bow, borrow2);
    addBorrow(&bow, borrow3);
    displayBorrow(bow);
    removeBorrow(&bow,16);
    removeBorrow(&bow,17);
    removeBorrow(&bow,15);
    displayBorrow(bow);
    freeBorrow(bow);



}

int main(int argc, char ** argv)
{
    


    //category_t * lib = loadLib(argv[1]);

    // displayLib(library);

    /*borrow_t * borrow = loadBorrow("test");
    displayBorrow(borrow);
    addBorrowFromFile(argv[2], borrow, lib);
    displayBorrow(borrow);
    freeBorrow(borrow);*/
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