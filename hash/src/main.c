#include "hash_table.h"

void initTable(node_t * hashTable[], char * path)
{
    char   word[50];
    int    currentChar = 0, i = 0;
    FILE * file = fopen(path, "r");

    if(file != NULL)
    {

        do
        {
            while(currentChar != ' ' && currentChar != '.')
            {
                currentChar = fgetc(file);
                word[i]     = currentChar;
                i++;
            }

            word[i - 1] = '\0';
            printf("mot : %s ", word);
            incrementOrSet(hashTable, word);
            currentChar = 0;
            i           = 0;

        } while(currentChar != EOF);
        fclose(file);
    }
    else
    {
        printf("[ERREUR: file] <main: initTable>.");
    }
}

/**
 * @brief Main
 *
 * @param argc int
 * @param argv char**
 * @return int
 */
int main(int argc, char ** argv)
{
    node_t * hashTable[HASH_MAX];
    initTable(hashTable, "test.txt");

    return 0;
}