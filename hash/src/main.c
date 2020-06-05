#include "hash_table.h"

/**
 * @brief Initialise la table a partir d'un fichier texte.
 *
 * @param hashTable  node_t** - La hashtable
 * @param path char* - Le chemin du fichier
 */
void initTable(node_t * hashTable[], char * path)
{
    char word[50];
    char currentChar;
    int  i = 0;

    FILE * file = fopen(path, "r");

    if(file != NULL)
    {
        currentChar = fgetc(file);

        while(currentChar != EOF)
        {
            while(currentChar != ' ' && currentChar != '.')
            {
                word[i] = currentChar;
                i++;
                currentChar = fgetc(file);
            }
            word[i] = '\0';
            incrementOrSet(hashTable, word);
            i           = 0;
            currentChar = fgetc(file);
        }
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
int main()
{
    node_t ** hashTable = initHashTable();
    node_t *  node      = NULL;
    initTable(hashTable, "data.txt");
    displayTable(hashTable);

    node = get(hashTable, "maxime");
    printf("MOT: %s compte %d fois\n", node->word, node->count);

    freeHashTable(hashTable);
    return 0;
}