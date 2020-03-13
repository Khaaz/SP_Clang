typedef struct borrow
{
    int             number;
    int             date;
    struct borrow * next;
} borrow_t;

typedef struct tete
{
    borrow_t * first;

} tete_t;

void AfficheBorrow(borrow_t *);
// borrow_t * AddBorrowFromFile(borrow_t *, char *, categories_t *);
// borrow_t * RemoveBorrowFromFile(borrow_t *, char *);
void       AddBorrow(tete_t *, int, int);
borrow_t * initBorrow(int, int);
tete_t *   initTete();
borrow_t * removeBorrow(borrow_t *, int);
