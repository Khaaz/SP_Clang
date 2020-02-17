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

categories_t *CreateCategorie(char[3], books_t *);
books_t *CreateBook(int, char[10]);
void AddBook(categories_t *, int, char[10]);
void AddCategorie(categories_t *, char[3], books_t *);
void AfficheBibli(categories_t *);
void AddBookWithCategoryName(categories_t *, char[3], int, char[15]);
void AddFichier(char *, categories_t *);
