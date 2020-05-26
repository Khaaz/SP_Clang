#include "tree.h"

/**
 * @brief Lis un fichier donner en parametre pour obtenir la notation algebrique
 * qu'il contient
 *
 * @param path char* - le chemin d'acces au fichier
 * @param string char* - la chaine lue dans le fichier
 */
void readFile(char * path, char * string)
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

/**
 * @brief Test no fonctions d'arbres
 *
 */
void testTrees()
{
    char     liste[100];
    int      taille   = 0;
    node_t * searched = NULL;
    printf("\n=== TEST: creation arbre ===\n");
    // creation de l'arbre : a*(b*(k*(h+u)+z)+f*m+x*(p+v+w)).
    node_t * tree = createTree("a*(b*(k*(h+u)+z)+f*m+x*(p+v+w))");
    printf("\n=== TEST: ordre postfix ===\n");
    getPostfix(tree, liste, &taille);
    displayPostfix(liste, taille);

    printf("\n=== TEST: fonction search ===\n");
    // test de la fonction search
    // recherche du noeud a, f, u, w
    searched = search(tree, 'a');
    printf("recherche du noeud a: %c\n", searched->value);
    searched = search(tree, 'f');
    printf("recherche du noeud f: %c\n", searched->value);
    searched = search(tree, 'u');
    printf("recherche du noeud u: %c\n", searched->value);
    searched = search(tree, 'w');
    printf("recherche du noeud w: %c\n", searched->value);

    printf("\n=== TEST: fonction insertion ===\n");
    // test de la fonction insertion.
    printf("insertion: racine\n");
    insertion(tree, 'a', 'l');
    taille = 0;
    getPostfix(tree, liste, &taille);
    displayPostfix(liste, taille);

    printf("insertion: milieu\n");
    insertion(tree, 'k', 's');
    taille = 0;
    getPostfix(tree, liste, &taille);
    displayPostfix(liste, taille);

    printf("insertion: feuille\n");
    insertion(tree, 'u', 'i');
    taille = 0;
    getPostfix(tree, liste, &taille);
    displayPostfix(liste, taille);

    printf("insertion: noeud inexistant\n");
    insertion(tree, 'j', 'e');

    // insertion devant la fratrie lors du tri par ordre alphabétique
    printf("insertion: devant la fratrie\n");
    insertion(tree, 'x', 'o');
    taille = 0;
    getPostfix(tree, liste, &taille);
    displayPostfix(liste, taille);

    // insertion au milieu de la fratrie lors du tri par ordre alphabétique
    printf("insertion: milieu de la fratrie\n");
    insertion(tree, 'x', 'r');
    taille = 0;
    getPostfix(tree, liste, &taille);
    displayPostfix(liste, taille);

    // insertion  la fin de la fratrie lors du tri par ordre alphabétique
    printf("insertion: fin de la fratrie\n");
    insertion(tree, 'x', 'y');
    taille = 0;
    getPostfix(tree, liste, &taille);
    displayPostfix(liste, taille);

    freeTree(tree);
}

/**
 * @brief Main
 * Prends un argument: le fichier a ouvrir.
 *
 * @param argc int
 * @param argv char**
 * @return int
 */
int main(int argc, char ** argv)
{
    int  size = 0;
    char list[100];
    char treeString[100];

    if(argc < 2)
    {
        printf("Nombre d'argument non suffisant: 1 minimum.\n");
        exit(1);
    }
    printf("src: %s\n", argv[1]);
    readFile(argv[1], treeString);

    printf("Chaine a transformer en arbre: %s\n", treeString);

    node_t * tree = createTree(treeString);
    insertion(tree, 'a', 'c');

    getPostfix(tree, list, &size);
    displayPostfix(list, size);

    freeTree(tree);
    printf("======TESTS======\n");
    testTrees();

    return 0;
}
