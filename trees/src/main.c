#include "tree.h"

void readFile(char * path, char* string)
{
    FILE * f = fopen(path, "r");

    if(f != NULL)
    {
        fgets(string, 100, f);
        fclose(f);
    }
    else
    {
        printf("ERROR: ouverture fichier\n");
    }
}

int main(int argc, char ** argv)
{
    int size = 0;
    char list[100];
    char treeString[100];
    
    if(argc < 2)
    {
        printf("Nombre d'argument non suffisant: 1 minimum.\n");
        exit(1);
    }
    printf("src: %s\n", argv[1]);
    readFile(argv[1], treeString);

    printf("Chaine a trandformer en arbre: %s\n", treeString);

    node_t * tree = createTree(treeString);

    insertion(tree, 'm', 'Z');

    getPostfix(tree, list, &size);
    displayPostfix(list, size);


    freeTree(tree);
    printf("FINI\n");
    return 0;
}
