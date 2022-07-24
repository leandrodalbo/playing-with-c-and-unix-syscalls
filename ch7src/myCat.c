#include <stdio.h>
#include <stdlib.h>

void setOutPut(FILE *from, FILE *to);

/*
$ echo someinput | ./myCat 
./myCat filename
*/
int main(int argc, char *argv[])
{
    FILE *readingFile;

    if (argc == 1)
    {
        setOutPut(stdin, stdout);
    }
    else
    {
        while (--argc > 0)
        {
            if ((readingFile = fopen(*++argv, "r")) == NULL)
            {
                fprintf(stderr, "can't open %s", *argv);
                exit(1);
            }
            else
            {
                setOutPut(readingFile, stdout);
                fclose(readingFile);
            }
        }

        exit(0);
    }
}

void setOutPut(FILE *from, FILE *to)
{
    int c;

    while ((c = getc(from)) != EOF)
    {
        putc(c, to);
    }
}