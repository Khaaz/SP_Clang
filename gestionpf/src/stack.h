typedef int T;

typedef struct stack
{
    int capacity;
    int top;
    T * base;
} stack_t;

stack_t * createStack(int);
int       push(stack_t *, T);
int       pop(stack_t *);
T         peek(stack_t *); // affiche dernier elmt
int       isEmptyStack(stack_t *);
void      displayStack(stack_t *);
void      freeStack(stack_t *);
