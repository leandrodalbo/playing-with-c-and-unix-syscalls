#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>
#include <mqueue.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void send(mqd_t queue);
void receive(mqd_t queue, long msgSize);

/*
    gcc msgq.c -lrt -o msgq
*/
int main()
{
    struct mq_attr attrs;
    mqd_t queue = mq_open("/testqueue", O_RDWR | O_CREAT, 0660, NULL);

    if (mq_getattr(queue, &attrs) != -1)
    {
        printf("message queue props, max_msg: %d message_size: %d \n", (int)attrs.mq_maxmsg, (int)attrs.mq_msgsize);
    }
    else
    {
        exit(EXIT_FAILURE);
    }

    switch (fork())
    {
    case -1:
        exit(EXIT_FAILURE);
        break;
    case 0:
        receive(queue, attrs.mq_msgsize);
        break;

    default:
        send(queue);
        wait(NULL);
        mq_close(queue);
        break;
    }
    exit(EXIT_SUCCESS);
}

void send(mqd_t queue)
{
    int i = 0;
    char msg[10];
    while (1)
    {

        sleep(3);
        snprintf(msg, sizeof(msg), "msg_%d", ++i);
        mq_send(queue, msg, sizeof(msg), 0);
    }
}
void receive(mqd_t queue, long msgSize)
{
    while (1)
    {
        sleep(3);
        char *msg_ptr = calloc(1, msgSize);

        if (mq_receive(queue, msg_ptr, msgSize, NULL) != -1)
        {
            printf("msg from the queue, %s \n", msg_ptr);
        }

        free(msg_ptr);
    }
}