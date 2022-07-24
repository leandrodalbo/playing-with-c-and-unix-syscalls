#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static int globalInt = 0;
sem_t semaphore;

static void *tRunner(void *arg)
{
    sem_wait(&semaphore);

    printf("%s is on the critical section waaaaaa... \n", (char *)arg);

    for (int i = 0; i < 10000; i++)
    {
        globalInt++;
    }

    sem_post(&semaphore);
}

int main()
{
    sem_init(&semaphore, 0, 1);

    pthread_t t0, t1, t2;
    void *res;

    if (pthread_create(&t0, NULL, tRunner, "t0") != 0)
    {
        perror("Thread Creation Error \n");
    }

    if (pthread_create(&t1, NULL, tRunner, "t1") != 0)
    {
        perror("Thread Creation Error  \n");
    }

    if (pthread_create(&t2, NULL, tRunner, "t2") != 0)
    {
        perror("Thread Creation Error  \n");
    }

    if (pthread_join(t0, &res) != 0)
    {
        perror("Thread Join Error  \n");
    }

    if (pthread_join(t1, &res) != 0)
    {
        perror("Thread Join Error  \n");
    }

    if (pthread_join(t2, &res) != 0)
    {
        perror("Thread Join Error  \n");
    }

    sem_destroy(&semaphore);
    printf("Global Value = %d \n ", globalInt);
    exit(EXIT_SUCCESS);
}