#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS  (3)
#define COUNT_LIMIT  (12)
pthread_mutex_t count_mutex;        //Made Global as all thread stacks need access to it 
pthread_cond_t  count_threshold_cv; //Made Global as all thread stacks need access to it
int             count = 0;          //Made Global as all thread stacks need access to it

void* inc_count(void* t)
{
    int my_id = *((int*) t);

    while(1)
    {
        sleep(1);
        pthread_mutex_lock(&count_mutex);
        count++;
        /*
         * Check the value of count and signal waiting thread when condition is
         * reached.  Note that this occurs while mutex is locked. 
         */
        if (count == COUNT_LIMIT)
        {
            pthread_cond_signal(&count_threshold_cv);
            printf("%s(): thread %d, count = %d  Threshold reached.\n", 
                                  __FUNCTION__ , my_id, count);
            printf("%s(): thread %d, count = %d, unlocking mutex\n",
                    __FUNCTION__ , my_id, count);
            pthread_mutex_unlock(&count_mutex);
            pthread_exit(NULL);
        }
        if(count>COUNT_LIMIT)
        {
            //If we do not do this the 2nd thread that did not hit count == COUNT_LIMIT condition
            //will never break out of infinite while loop
            pthread_mutex_unlock(&count_mutex);
            pthread_exit(NULL);
        }
        printf("%s(): thread %d, count = %d, unlocking mutex\n", 
                        __FUNCTION__ , my_id, count);
        pthread_mutex_unlock(&count_mutex);
    }
    pthread_exit(NULL);
}

void* watch_count(void* t)
{
    int my_id = *((int*) t);
    printf("Starting %s(): thread %d\n", __FUNCTION__ , my_id);

    /*
     * Lock mutex and wait for signal.  Note that the pthread_cond_wait 
     * routine will automatically lock and atomically unlock mutex while it waits. 
     * Also, note that if COUNT_LIMIT is reached before this routine is run by
     * the waiting thread, the loop will be skipped to prevent pthread_cond_wait
     * from never returning. 
     */
    pthread_mutex_lock(&count_mutex);
    while (count<COUNT_LIMIT)
    {
        //int pthread_cond_wait(pthread_cond_t *restrict cond,
        //                      pthread_mutex_t *restrict mutex);
        pthread_cond_wait(&count_threshold_cv, &count_mutex);
        printf("%s(): thread %d Condition signal received.\n", __FUNCTION__ , my_id);
    }
    count = count + 100;
    printf("%s(): thread %d count now = %d.\n", __FUNCTION__ , my_id, count);
    pthread_mutex_unlock(&count_mutex);
    pthread_exit(NULL);
}


int main()
{
    int i;
    int* t1 = (int*) malloc(sizeof(int)); 
    int* t2 = (int*) malloc(sizeof(int));
    int* t3 = (int*) malloc(sizeof(int));
    *t1 = 1;
    *t2 = 2;
    *t3 = 3;

    pthread_t      my_threads[NUM_THREADS];
    pthread_attr_t my_th_attr[NUM_THREADS];

    //int pthread_mutex_init(pthread_mutex_t *restrict mutex,
    //              const pthread_mutexattr_t *restrict attr);
    pthread_mutex_init(&count_mutex, NULL);
    //int pthread_cond_init(pthread_cond_t *restrict cond,
    //              const pthread_condattr_t *restrict attr);
    pthread_cond_init (&count_threshold_cv, NULL);

    for (i = 0; i < NUM_THREADS ; i++)
    {
        pthread_attr_init(&my_th_attr[i]);
        pthread_attr_setdetachstate(&my_th_attr[i], PTHREAD_CREATE_JOINABLE);
    }

    pthread_create(&my_threads[0], &my_th_attr[0], watch_count, t1);
    pthread_create(&my_threads[1], &my_th_attr[1], inc_count, t2);
    pthread_create(&my_threads[2], &my_th_attr[2], inc_count, t3);

    /* Wait for all threads to complete */
    for (i=0; i<NUM_THREADS; i++) {
        //int   pthread_join(pthread_t, void **);
        pthread_join(my_threads[i], NULL);
    }

    printf ("Main(): Waited on %d  threads. Done.\n", NUM_THREADS);

    /* Clean up and exit */
    for (i=0; i<NUM_THREADS; i++) {
        pthread_attr_destroy(&my_th_attr[i]);
    }
    pthread_mutex_destroy(&count_mutex);
    pthread_cond_destroy(&count_threshold_cv);

    free(t1);
    free(t2);
    free(t3);
    return 0;
}
