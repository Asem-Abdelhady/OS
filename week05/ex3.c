#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_MAX 100000

int buffer = 0;
bool producer_sleep = 0;
bool consumer_sleep = 0;


void *consumer()
{
    printf("This is Consumer: \n");

    while(1)
    {

        if(producer_sleep && consumer_sleep)
        {
            printf("race condition\n");
            exit(1);
        }

        if(!buffer)
        {
            consumer_sleep = 1;
            producer_sleep = 0;
        }

        if(!consumer_sleep)
        {
            buffer--;
            if(buffer == rand() % BUFFER_MAX)
                printf("Consuming...\n");
        }
    }
}

void *producer()
{
    printf("This is Producer: \n");

    while(1)
    {

        if(producer_sleep && consumer_sleep)
        {
            printf("race condition\n");
            exit(1);
        }

        if(buffer == BUFFER_MAX)
        {
            producer_sleep = 1;
            consumer_sleep = 0;
        }

        if(!producer_sleep)
        {
            buffer++;
            if(buffer == rand() % BUFFER_MAX)
                printf("Producing...\n");
        }
    }
}


int main()
{
    pthread_t p, c;

    pthread_create(&p, NULL, producer, &p);
    pthread_create(&c, NULL, consumer, &c);

    pthread_join(p, NULL);
    pthread_join(c, NULL);
}
