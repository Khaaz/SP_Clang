#include "queue/queue.h"
#include "stack/stack.h"
#include "tree.h"
#include <stdlib.h>

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

                    push(cur);
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