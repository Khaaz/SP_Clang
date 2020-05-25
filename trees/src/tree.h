typedef char T;

/**
 * @brief Structure Tree. Le maillon qui compose notre arbre
 *
 */
typedef struct node
{
    char          value;   // valeur du neud (une lettre)
    struct node * son;     // pointeur vers l'element file (lien vertical)
    struct node * brother; // pointeur vers l'element frere (lien horizontal)
} node_t;

node_t * createNode(char);
void     insertBrother(node_t *, node_t *);
void     insertSon(node_t *, node_t *);
void     getPostfix(node_t *, int *, char *);
void     displayPostfix(char *, int);
node_t * search(node_t *, char valeur);
