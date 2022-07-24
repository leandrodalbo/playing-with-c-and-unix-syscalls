#include "stdio.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "fcntl.h"
#include "errno.h"

/*
   Create/open a file only with read/write permission for owner and group
 */
int main()
{

        int fileDescriptor = open("createdFile", O_RDWR | O_CREAT, 0660);

        if (fileDescriptor > 0)
        {
                printf("FILE CREATED, fileDescriptor= %d \n", fileDescriptor);
        }
        else
        {
                printf("ERROR %d \n", errno);
        }

        return 0;
}
