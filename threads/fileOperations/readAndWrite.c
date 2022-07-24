#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){
      int fileDescriptor = open("./input",  O_RDWR);

      if(fileDescriptor < 0)
      {
        perror("Error:");
        exit(1);
      }
      else
      {
            int bufferSize = 20;
            char buffer[bufferSize];
            while(read(fileDescriptor, buffer, bufferSize)>0)
            {
               write(1, buffer, strlen(buffer));
            }
      }

      exit(0);
}

