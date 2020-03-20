#include "main.h"
#include "borrow_file.h"
#include "lib_file.h"

void testLib(){
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
    printf("Test fonction findBook : avec le livre numéro 12 :\n");
    book_t * Fbook = findBook(book, 12);
    printf("On obtient le livre : %s  : \n\n", Fbook->title);
    printf("Test fonction finBookInlib : avec le livre numéro 5:\n");
    book_t * Fbook2 = findBookInLib(POL, 5);
    printf("On obtient le livre %s : \n \n", Fbook2->title);
    printf("On recherche la categorie POL avec la fonction findCategory:\n");
    category_t * FPOL = findCategory(POL, "POL");
    printf("On obtient la categorie : %s \n \n", FPOL->name);
    printf("Test de la fonction isBookTaken avec le livre N°6:\n");
    printf("La fonction retourne %d car le livre n'est pas emprunté.\n", isBookTaken(book));
    freeLib(lib);
}

void testBorrow() {
    borrow_t * bow = initBorrow();
    borrow_t * borrow = createBorrow(20201112, 15);
    borrow_t * borrow1 = createBorrow(20221112, 17); //insertion en fin
    borrow_t * borrow2 = createBorrow(20211112, 16); //insertion  au milieu
    borrow_t * borrow3 = createBorrow(20191112, 14); //insertion au début
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

/**
 * @brief Main.
 * S'appelle avec 3 arguments:
 * 1 - Le chemin pour le fichier de lib (data/lib.txt)
 * 2 - Le chemin pour le fichier de borrow (data/borrow.txt)
 * 3 - Le chemin pour le fichier de add_borrow (data/add_borrow.txt)
 * 4 - Le chemin pour le fichier de remove_borrow (data/remove_borrow.txt)
 * 
 * Dans le repertoire courant (root)
 * `make clean && make`
 * `./build/prog ./data/lib.txt ./data/borrow.txt ./data/add_borrow.txt ./data/remove_borrow.txt`
 * 
 * @param argc int - Le nombre d'argument
 * @param argv char** - Les arguments
 * @return int 
 */
int main(int argc, char ** argv)
{
    if (argc < 5) {
        printf("Nombre d'argument non suffisant: 4 minimum.\n");
        exit(1);
    }

    printf("==========loadLib==========\n"); // Load library depuis le fichier
    category_t *lib = createLib();
    loadLib(argv[1], &lib);
    displayLib(lib);

    printf("==========loadBorrow==========\n"); // Load les emprunts depuis le fichier
    borrow_t * borrow = initBorrow();
    loadBorrow(argv[2], &borrow, lib);
    displayBorrow(borrow);

    printf("==========addBorrowFromFile==========\n");
    addBorrowFromFile(argv[3], &borrow, lib);
    displayBorrow(borrow);

    printf("==========removeBorrowFromFile==========\n");
    //removeBorrowFromFile(argv[4], &borrow, lib);
    displayBorrow(borrow);
    
    printf("==========saveBorrowFromFile==========\n");
    saveBorrow(argv[2], &borrow, lib);
    
    freeBorrow(borrow);
    freeLib(lib);

    printf("\n\n=========TEST==========\n\n");
    printf("==========TEST_LIB==========\n");
    testLib();
    printf("\n==========TEST_BORROW==========\n");
    testBorrow();

    return 0;
}