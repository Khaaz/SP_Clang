#include "tree.h"
#include "queue/queue.h"
#include "stack/stack.h"

/**
 * @brief Cree un node (un noeud de notre arbre)
 *
 * @param value char - La valeur du noeud
 * @return node_t* - le moeud nouvellement cree
 */
node_t * createNode(char value)
{
    node_t * node = NULL;
    node          = malloc(sizeof(*node));
    if(node != NULL)
    {
        node->value   = value;
        node->son     = NULL;
        node->brother = NULL;
    }
    else
    {
        printf("ERROR: Allocation Node\n");
    }
    return node;
}

/**
 * @brief Cree un arbre a partir d'une notation algebrique
 *
 * @param treeString char* - la notation algebrique
 * @return node_t* - l'arbre nouvellement cree
 */
node_t * createTree(char * treeString)
{
    int       i = 0;
    char      e, c;
    stack_t * stack = NULL;
    stack           = createStack(50);

    node_t * tree    = NULL;
    tree             = createNode(treeString[i++]);
    node_t * element = NULL;
    node_t * cur     = tree;
    while(treeString[i] != '\0' && cur != NULL)
    {
        e = treeString[i];
        if(e == ')') // )
        {
            cur = peek(stack);
            pop(stack);
        }
        else // +, *, (
        {
            ++i;
            c = treeString[i];
            if(e == '+') // +
            {
                element = createNode(c);
                insertBrother(cur, element);
                cur = element;
            }
            else // *
            {
                if(c == '(') // (
                {
                    ++i;
                    element = createNode(treeString[i]);
                    insertSon(cur, element);

                    push(stack, cur);
                    cur = element;
                }
                else // char
                {
                    element = createNode(c);
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

    return tree;
}

/**
 * @brief Libere l'arbre (free tous les noeuds de note arbre)
 *
 * @param tree node_t* L'arbre a liberer
 */
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

/**
 * @brief Insert un frere sur un noeud donne.
 *
 * @param node node_t* - Le noeud dans lequel inserer un frere
 * @param element node_t* - Le frere a inserer
 */
void insertBrother(node_t * node, node_t * element)
{
    node->brother = element;
}

/**
 * @brief Insert un file sur un noeud donne.
 *
 * @param node node_t* - Le noeud dans lequel inserer un fils
 * @param element node_t* - Le fils a inserer
 */
void insertSon(node_t * node, node_t * element)
{
    node->son = element;
}

/**
 * @brief Donne la representation post fix de l'arbre. Donne cette
 * representation dans une list contigue de char donnee en parametre.
 *
 * @param node ndoe_t* - L'arbre duquel on veut obtenir la representation
 * postfix
 * @param list char* - la liste contigue contenant la representation postfix
 * @param size int* - la taille logique de note liste
 */
void getPostfix(node_t * node, char * list, int * size)
{
    node_t *  cour  = node;
    stack_t * stack = createStack(50);
    while(cour != NULL)
    {
        while(cour->son)
        {
            push(stack, cour);
            cour = cour->son;
        }
        list[*size] = cour->value;
        ++(*size);
        cour = cour->brother;
        while(cour == NULL && isEmptyStack(stack) == 0)
        {
            cour = peek(stack);
            pop(stack);
            list[*size] = cour->value;
            ++(*size);
            cour = cour->brother;
        }
    }
    freeStack(stack);
}

/**
 * @brief Affiche la notation postfix d'un arbre: Affiche le contenu d'une liste
 * contigue contenant la representation postfix d'un arbre
 *
 * @param list char* - la liste contigue contenant la representation postfix
 * @param taille int - la taille de la liste
 */
void displayPostfix(char * list, int taille)
{
    int i;
    printf("Ordre postfix:\n");

    for(i = 0; i < taille; i++)
    {
        printf("%c", list[i]);
    }
    printf("\n");
}

/**
 * @brief Cherche dans l'arbre le premier noeud de valeur donne.
 * La recherche est une recherche par parcours de premier ordre par niveau.
 * (parcours en largeur de premier ordre par niveau) On utilise une file.
 *
 * @param node node_t* - l'arbre dans lequel rechercher
 * @param value char - la valeur a recherche dans l'arbre
 * @return node_t* - le neoud trouve apres la recherche
 */
node_t * search(node_t * node, char value)
{
    node_t *  cour  = node;
    queue_t * queue = createQueue(50);
    while(cour != NULL && cour->value != value)
    {
        if(cour->son != NULL)
        {
            pushBack(queue, cour->son);
        }
        if(cour->brother != NULL)
        {
            cour = cour->brother;
        }
        else
        {
            cour = front(queue);
            popFront(queue);
        }
    }
    freeQueue(queue);
    return cour;
}

/**
 * @brief Creer et insert un noeud de valeur donnee dans l'arbre. Insert dans
 * les fils du noeud donne en parametre. Le noeud donne en parametre est donne
 * sous format de char, et est donc trouve en utilisant search. L'insertion dans
 * les fils se fait en suivant l'ordre alphabetique.
 *
 * @param node node_t* - l'arbre dans lequel inserer
 * @param noeud char - la valeur du noeud a trouver et dans lequel inserer
 * @param value char - la valeur du noeud a creer et inserer
 * @return int - Si la fonction a marche correctement
 */
int insertion(node_t * node, char noeud, char value)
{
    int       code    = 1;
    node_t *  cour    = search(node, noeud);
    node_t ** prec    = NULL;
    node_t *  newnode = NULL;
    if(cour != NULL)
    {
        prec    = &(cour->son);
        newnode = createNode(value);

        while(*prec != NULL && (*prec)->value < value)
        {
            prec = &((*prec)->brother);
        }
        newnode->brother = *prec;
        *prec            = newnode;
    }
    else
    {
        code = 0;
        printf("ERROR: Insertion dans un noeud inexistant\n");
    }
    return code;
}