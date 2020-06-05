#include "./hash_table.h"

unsigned int hash_string(const char * str)
{
    unsigned int hash = 5381; /*  fonction de hachage de D.J. Bernstein*/
    const char * s;
    for(s = str; *s; s++)
        hash = ((hash << 5) + hash) + tolower(*s);
    return (hash & 0x7FFFFFFF) % HASH_MAX;
}

node_t** initHashTable() {
    node_t ** hashTable = malloc(HASH_MAX * sizeof(node_t));
    if (hashTable == NULL) {
        printf("[ERREUR: malloc] <hash_table: init>.\n");
    } else {
        for(int i = 0; i < HASH_MAX; i++)
        {
            hashTable[i] = initList();
        }
    }
    return hashTable;
}

void displayTable(node_t * hashTable[])
{
    for(int i = 0; i < HASH_MAX; i++)
    {
        displayList(hashTable[i]);
    }
}

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

void freeHashTable(node_t* hashTable[]) {
    for(int i = 0; i < HASH_MAX; i++)
    {
        freeList(hashTable[i]);
    }
    free(hashTable);
}