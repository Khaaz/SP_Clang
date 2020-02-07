typedef enum
{
    false,
    true
} boolean;

typedef struct books
{
    int number;
    char title[10];
    boolean isTaken;
    struct books *next;
} books_t;

typedef struct categories
{
    char name[3];
    books_t *books;
    struct categories *next;
} categories_t;

typedef struct borrow
{
    int number;
    int date;
} barrow_t;
