#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/*
write a program in 'C' to change only the Name present in file from 'Rohan' to 'Mohan'
*/
int main()
{
    int fileDescriptor = open("./input", O_RDWR);

    if (fileDescriptor < 0)
    {
        perror("Error:");
        exit(1);
    }
    else
    {
        char word[5];
        int movingCount = 0;

        while (read(fileDescriptor, word, sizeof(word)) > 0)
        {

            if (strcmp(word, "Rohan") == 0)
            {
                lseek(fileDescriptor, (movingCount - sizeof(word)), SEEK_SET);
                write(fileDescriptor, "Mohan", sizeof(word));
            }
            lseek(fileDescriptor, movingCount, SEEK_SET);
            movingCount += sizeof(word);
        }
    }

    exit(0);
}
