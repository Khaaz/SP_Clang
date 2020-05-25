#include "../tree.h"

typedef node_t * T;

/**
 * @brief Structure Stack. La pile
 *
 */
typedef struct stack
{
    int capacity; // La capacite maximum de cette pile (nombre d'elements
                  // maximum dans cette pile)
    int top;      // L'index de l'element du dessus de la pile
    T * base;     // Le tableau d'elements de la pile
} stack_t;

stack_t * createStack(int);
int       push(stack_t *, T);
int       pop(stack_t *);
T         peek(stack_t *); // affiche dernier elmt
int       isEmptyStack(stack_t *);
void      displayStack(stack_t *);
void      freeStack(stack_t *);
