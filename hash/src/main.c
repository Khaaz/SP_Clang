#include <stdlib.h>
#include <stdio.h>

void initTable(char * path)
{
    char  mot[50];
    int currentChar = 0, i=0;
    FILE * file = fopen(path, "r");

    if ( file != NULL)
    {
        
        do
        {                   
            while(currentChar != ' ' && currentChar != '.')
            {
                currentChar = fgetc(file);
                mot[i] = currentChar;
                i++;
            }

        mot[i-1] = '\0';
        printf("mot : %s ", mot);
        currentChar = 0;
        i=0;

        }while (currentChar != EOF);
        fclose(file);
    }
    else
    {
        printf("ERROR");
    }

}

/**
 * @brief Main
 *
 * @param argc int
 * @param argv char**
 * @return int
 */
int main(int argc, char ** argv)
{
    initTable("test.txt");

    return 0;
}