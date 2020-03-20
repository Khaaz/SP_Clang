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
    category_t *lib = createLib();
    loadLib(argv[1], &lib);

    displayLib(lib);

    borrow_t * borrow = initBorrow();
    loadBorrow("test", &borrow);
    displayBorrow(borrow);

    addBorrowFromFile(argv[2], &borrow, lib);
    displayBorrow(borrow);
    freeBorrow(borrow);
    //removeBorrowFromFile(argv[3], &borrow, lib);
    return 0;
}