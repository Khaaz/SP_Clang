#include "stack/stack.h"
#include "tree.h"
#include <stdio.h>

int main(int argc, char * argv)
{
    if(argc < 2)
    {
        printf("Nombre d'argument non suffisant: 1 minimum.\n");
        exit(1);
    }
    char * treeString = readFile(argv[1]);

    node_t * tree = createTree(treeString);
    return 0;
}

char * readFile(char * path)
{
    char buffer[100] = NULL;

    FILE * f = fopen(path, "r");

    if(f != NULL)
    {
        fgets(buffer, 100, f);
    }
    else
    {
        printf("ERROR: ouverture fichier\n");
    }

    fclose(f);

    return buffer;
}

node_t * createTree(char * treeString)
{
    stack_t * stack = createStack(10);

    node_t * tree = NULL;
    node_t * cur  = NULL;

    int i = 0;
    while(treeString[i] != '\0')
    {
        char e = treeString[i];
        if(e == ')') // )
        {
            cur = peek(stack);
            pop(stack);
        }
        else // +, *, (
        {
            ++i;
            char c = treeString[i];

            if(e == '+') // +
            {
                node_t * element = createNode(c);
                insertBrother(cur, element);
                cur = element;
            }
            else // *
            {
                if(c == '(') // (
                {
                    ++i;
                    node_t * element = createNode(treeString[i]);
                    insertSon(cur, element);

                    push(stack, cur);
                    cur = element;
                }
                else // char
                {
                    node_t * element = createNode(c);
                    insertSon(cur, element);
                    if(treeString[i + 1] == '*')
                    {
                        cur = element;
                    }
                }
            }
        }
        ++i;
    }

    freeStack(stack);
}

void freeTree(node_t * tree)
{
    stack_t * stack = createStack(50);
    node_t *  cour  = tree;
    node_t *  tmp   = NULL;

    while(cour != NULL)
    {
        if(cour->son != NULL)
        {
            tmp       = cour->son;
            cour->son = NULL;
            push(stack, cour);
            cour = tmp;
        }
        else
        {
            if(cour->brother != NULL)
            {
                tmp           = cour->brother;
                cour->brother = NULL;
                free(cour);
                cour = tmp;
            }
            else
            {
                free(cour);
                if(isEmptyStack(stack) == 0)
                {
                    cour = peek(stack);
                    pop(stack);
                }
                else
                {
                    cour = NULL;
                }
            }
        }
    }
    freeStack(stack);
}

void testTrees(){
    char liste[100];
    int taille = 0;
    //creation de l'arbre : a*(b*(k*(h+u)+z)+f*m+x*(p+v+w)).
    node_t * node = createTree("a*(b*(k*(h+u)+z)+f*m+x*(p+v+w))");
    getPostfix(node, &taille, liste);
    displayPostfix(liste, taille);

    //test de la fonction search
    //recherche du noeud a, f, u, w
    node_t * search = search(node, "a");
    printf("recherche du noeud a: %c ", search->value);
    node_t * search = search(node, "f");
    printf("recherche du noeud f: %c ", search->value);
    node_t * search = search(node, "u");
    printf("recherche du noeud u: %c ", search->value);
    node_t * search = search(node, "w");
    printf("recherche du noeud w: %c ", search->value);

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
