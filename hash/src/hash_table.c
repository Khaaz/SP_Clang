#include "./hash_table.h"

unsigned int hash_string(const char * str)
{
    unsigned int hash = 5381; /*  fonction de hachage de D.J. Bernstein*/
    const char * s;
    for(s = str; *s; s++)
        hash = ((hash << 5) + hash) + tolower(*s);
    return (hash & 0x7FFFFFFF) % HASH_MAX;
}

/**
 * @brief Initialise la strcuture de hashtable. Creer une liste de taille
 * HASH_MAX et initalise toutes les valeurs a NULL.
 *
 * @return node_t** La HashTable creee
 */
node_t ** initHashTable()
{
    node_t ** hashTable = malloc(HASH_MAX * sizeof(node_t));
    if(hashTable == NULL)
    {
        printf("[ERREUR: malloc] <hash_table: init>.\n");
    }
    else
    {
        for(int i = 0; i < HASH_MAX; i++)
        {
            hashTable[i] = initList();
        }
    }
    return hashTable;
}

/**
 * @brief Affiche la table
 *
 * @param hashTable node_t** - La table a afficher
 */
void displayTable(node_t * hashTable[])
{
    for(int i = 0; i < HASH_MAX; i++)
    {
        displayList(hashTable[i]);
    }
}

/**
 * @brief Ajoute ou incremente le noeud (le mot) pour le mot passe en parametre.
 * Construit la table.
 *
 * @param hashTable node_t** - La table a construire, a incrementer
 * @param word char* - Le mot a ajouter
 */
void incrementOrSet(node_t * hashTable[], char * word)
{
    int      index = hash_string(word);
    node_t * list  = hashTable[index];
    node_t * node  = NULL;

    if(list == NULL)
    {
        hashTable[index] = createNode(word);
    }
    else
    {
        node = searchNode(list, word);
        if(node == NULL)
        {
            node = createNode(word);
            addNextNode(&(hashTable[index]), node);
        }
        else
        {
            incrementNode(node);
        }
    }
}

/**
 * @brief Recupere le noeud pour le mot passe en parametre.
 *
 * @param hashTable node_t** - La table a chercher
 * @param word - char* - Le mot a chercher dans la table
 * @return node_t* - Le noeud trouve pour le mot cherche
 */
node_t * get(node_t * hashTable[], char * word)
{
    int      index = hash_string(word);
    node_t * list  = hashTable[index];
    node_t * node  = NULL;

    if(list != NULL)
    {
        node = searchNode(list, word);
    }
    return node;
}

/**
 * @brief Libere la table
 *
 * @param hashTable node_t** - La table a liberer
 */
void freeHashTable(node_t * hashTable[])
{
    for(int i = 0; i < HASH_MAX; i++)
    {
        freeList(hashTable[i]);
    }
    free(hashTable);
}