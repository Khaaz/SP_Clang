typedef int T;

typedef struct queue
{
    int capacity;
    int size;
    T * head;
    T * tail;
    T * base;
} queue_t;

void create();
void pushBack();
void popFront();
void front();
void back();
void isEmpty();
void display();
