#include "hash_table.h"

void initTable(node_t * hashTable[], char * path)
{
    char   word[50];
    char    currentChar;
    int i = 0;
    
    FILE * file = fopen(path, "r");

    if(file != NULL)
    {
        do
        {
            do
            {
                currentChar = fgetc(file);
                word[i]     = currentChar;
                i++;
            } while(currentChar != ' ' && currentChar != '.'&& currentChar != EOF);

            if (currentChar != EOF) {
                word[i - 1] = '\0';
                incrementOrSet(hashTable, word);
                i           = 0;
            }
        } while(currentChar != EOF);
        fclose(file);
    }
    else
    {
        printf("[ERREUR: file] <main: initTable>.\n");
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
    node_t ** hashTable = initHashTable();
    initTable(hashTable, "data.txt");
    displayTable(hashTable);
    freeHashTable(hashTable);
    return 0;
}