#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void runner(char *str);

int main(int argc, char *argv[])
{
  int pid;
  
  switch ( pid = fork())
  {
  case -1:
    printf("error creating child process... \n");
    exit(-1);
    break;
  case 0:
    runner("child_boy");
    break;

  default:
    runner("dady");
    break;
  }

  exit(0);
}

void runner(char *name)
{
  printf("running %s, with pid %d, and parent %d \n", name, getpid(), getppid());
}