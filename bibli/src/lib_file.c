#include "lib_file.h"

/**
 * @brief Charge la biblotheque dans la structure depuis un fichier
 * 
 * @param path char* - Le chemin d'acces au fichier
 * @param lib category_t** - La structure ou charger la bibliotheque
 * @return int - Si la fonction a et execute avec succes ou pas
 */
int loadLib(char * path, category_t** lib)
{
    category_t ** categoryPrev = lib;
    category_t *  category = NULL;
    book_t **     bookPrev = NULL;
    book_t *      book = NULL;
    
    int success = 1;
    char categoryName[4];
    char title[11];
    int  nbrLivres = 0;
    int  number    = 0;

    FILE * file = fopen(path, "r");
    if(file != NULL)
    {

        while(!feof(file))
        {
            fscanf(file, "%s %d", categoryName, &nbrLivres);
            category = createCategory(categoryName, NULL);
            addNextCategory(categoryPrev, category);

            bookPrev = &(category->books);

            for(int i = 0; i < nbrLivres; i++)
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

        printf("[ERREUR: fichier] <loadLib>.\n");
        success = 0;
    }

    return success;
}