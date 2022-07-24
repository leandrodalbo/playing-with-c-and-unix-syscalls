#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static void *tRunner(void *arg)
{
    printf("thread running on process: %d \n", getpid());
    (void)sleep(2);
    printf("out of the thread... \n");
    pthread_exit(NULL);
}

int main()
{
    pthread_t t0;
    void *res;

    if (pthread_create(&t0, NULL, tRunner, NULL) != 0)
    {
        perror("error creating new thread \n");
    }

    printf("waiting for T0  MAIN--> %d \n", getpid());
    
    if (pthread_join(t0, &res) != 0)
    {
        perror("error joining thread \n");
    }

    printf("good bye!");
    pthread_exit(NULL);
}