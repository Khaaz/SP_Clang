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
    node_t * node = createTree("a*(b*(k*(h+u)+z)+f*m+x*(p+v+w))");
    getPostfix(node, &taille, liste);
    displayPostfix(liste, taille);

    //test de la fonction search
    //recherche du noeud a, f, u, w
    searched = search(node, "a");
    printf("recherche du noeud a: %c ", searched->value);
    searched = search(node, "f");
    printf("recherche du noeud f: %c ", searched->value);
    searched = search(node, "u");
    printf("recherche du noeud u: %c ", searched->value);
    searched = search(node, "w");
    printf("recherche du noeud w: %c ", searched->value);

    //test de la fonction insertion.
    //insertion a la racine
    insertion("a", "l", node );
    taille = 0;
    getPostfix(node, &taille, liste);
    displayPostfix(liste, taille);

    //insertion au milieu
    insertion("b", "s", node);
    taille = 0;
    getPostfix(node, &taille, liste);
    displayPostfix(liste, taille);
    
    //insertion sur une feuille
    insertion("h", "i", node);
    taille = 0;
    getPostfix(node, &taille, liste);
    displayPostfix(liste, taille);

    //insertion sur un noeud qui n'existe pas
    insertion("r", "e", node);
    

    //insertion devant la fratrie lors du tri par ordre alphabétique
    insertion("x", "j", node);
    taille = 0;
    getPostfix(node, &taille, liste);
    displayPostfix(liste, taille);

    //insertion au milieu de la fratrie lors du tri par ordre alphabétique
    insertion("x", "q", node);
    taille = 0;
    getPostfix(node, &taille, liste);
    displayPostfix(liste, taille);

    //insertion  la fin de la fratrie lors du tri par ordre alphabétique
    insertion("x", "y", node);
    taille = 0;
    getPostfix(node, &taille, liste);
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

    insertion(tree, 'm', 'Z');

    getPostfix(tree, list, &size);
    displayPostfix(list, size);


    freeTree(tree);
    printf("FINI\n");
    return 0;
}


