#include "lib_file.h"

category_t * loadLib(char * path) {
    
    category_t * lib = createLib();
    
    category_t * category;
    category_t **categoryPrev = &lib;
    book_t * book;
    book_t ** bookPrev;

    char           categoryName[4];
    char           title[11];
    int            nbrLivres = 0;
    int            number    = 0;
    int            i;
    
    FILE *         file = fopen(path, "r");
    if(file != NULL)
    {

        while(!feof(file))
        {
            fscanf(file, "%s %d", categoryName, &nbrLivres);
            category = createCategory(categoryName, NULL);
            addNextCategory(categoryPrev, category);
            
            bookPrev = &(category->books);
            
            for(i = 0; i < nbrLivres; i++)
            {
                fscanf(file, "%d", &number);
                fgets(title, 12, file);

                book = createBook(number, title);
                addNextBook(bookPrev, book);

                bookPrev = &(book->next);
            }

            categoryPrev = &(category->next);
        }
        fclose(file);
    }
    else
    {

        printf("Erreur ouverture fichier.");
    }

    return lib;
}