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

void testTrees(){
    char liste[100];
    int taille = 0;
    node_t * searched = NULL;
    //creation de l'arbre : a*(b*(k*(h+u)+z)+f*m+x*(p+v+w)).
    node_t * tree = createTree("a*(b*(k*(h+u)+z)+f*m+x*(p+v+w))");
    getPostfix(tree, liste, &taille);
    displayPostfix(liste, taille);

    //test de la fonction search
    //recherche du noeud a, f, u, w
    searched = search(tree, 'a');
    printf("recherche du noeud a: %c ", searched->value);
    searched = search(tree, 'f');
    printf("recherche du noeud f: %c ", searched->value);
    searched = search(tree, 'u');
    printf("recherche du noeud u: %c ", searched->value);
    searched = search(tree, 'w');
    printf("recherche du noeud w: %c ", searched->value);

    //test de la fonction insertion.
    //insertion a la racine
    insertion(tree, 'l', 'X' );
    taille = 0;
    getPostfix(tree, liste, &taille);
    displayPostfix(liste, taille);

    //insertion au milieu
    insertion(tree, 's', 'X');
    taille = 0;
    getPostfix(tree, liste, &taille);
    displayPostfix(liste, taille);
    
    //insertion sur une feuille
    insertion(tree, 'i', 'X');
    taille = 0;
    getPostfix(tree, liste, &taille);
    displayPostfix(liste, taille);

    //insertion sur un noeud qui n'existe pas
    insertion(tree, 'e', 'X');
    

    //insertion devant la fratrie lors du tri par ordre alphabétique
    insertion(tree, 'j', 'X');
    taille = 0;
    getPostfix(tree, liste, &taille);
    displayPostfix(liste, taille);

    //insertion au milieu de la fratrie lors du tri par ordre alphabétique
    insertion(tree, 'q', 'X');
    taille = 0;
    getPostfix(tree, liste, &taille);
    displayPostfix(liste, taille);

    //insertion  la fin de la fratrie lors du tri par ordre alphabétique
    insertion(tree, 'y', 'X');
    taille = 0;
    getPostfix(tree, liste, &taille);
    displayPostfix(liste, taille);
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

    insertion(tree, 'u', 'Z');

    getPostfix(tree, list, &size);
    displayPostfix(list, size);


    freeTree(tree);
    printf("FINI\n");
    return 0;
}


