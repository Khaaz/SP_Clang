#include "./linked_list/linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define HASH_MAX 29

node_t** initHashTable();
void displayTable(node_t**);
void incrementOrSet(node_t **, char *);
node_t* get(node_t **, char *);
void freeHashTable(node_t**);
