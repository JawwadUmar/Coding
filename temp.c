#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#define NUM_THREADS 10

void *PrintHello(void *threadid)

{

    printf("\n%d: Hello World!\n", threadid);

    pthread_exit(NULL);
}

int main()

{

    pthread_t threads[NUM_THREADS];

    int rc, t;

    for (t = 0; t < NUM_THREADS; t++)
    {

        printf("Creating thread %d\n", t);

        rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);

        if (rc)

        {

            printf("ERROR; return code from pthread_create() is %d\n", rc);

            exit(-1);
        }
    }

    pthread_exit(NULL);
}

// smallest unit of execution in a process
// in C, thread is a light weight process

// The Pthread Library
//  pthread_create() --> start a new thread
//  pthread_join --> make the main program wait
//  pthread_exit --> explicitly used to terminate a thread