#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static int globalInt = 0;
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

static void *tRunner(void *arg)
{
    printf("updating global... \n");

    for (int i = 0; i < 5000; i++)
    {

        if (pthread_mutex_lock(&mtx) == 0)
        {
           
           globalInt++;
        }

        pthread_mutex_unlock(&mtx);
    }
}

int main()
{
    pthread_t t0, t1;
    void *res;

    if (pthread_create(&t0, NULL, tRunner, NULL) != 0)
    {
        perror("error creating new thread \n");
    }

    if (pthread_create(&t1, NULL, tRunner, NULL) != 0)
    {
        perror("error creating new thread \n");
    }

    if (pthread_join(t0, &res) != 0)
    {
        perror("error joining thread \n");
    }

    if (pthread_join(t1, &res) != 0)
    {
        perror("error joining thread \n");
    }

    printf("global value = %d \n ", globalInt);
    pthread_exit(NULL);
}