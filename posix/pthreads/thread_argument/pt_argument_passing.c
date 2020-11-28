#include <stdio.h>
#include <string.h> //strncpy
#include <unistd.h> //for sleep
#include <pthread.h>
#include <stdlib.h> //malloc free

#define MAX_THREADS   (5)

typedef struct ThreadDataS {
    int thread_id;
    char message[50];
} ThreadDataT;


void* PrintThreadDetail(void* my_input)
{
    ThreadDataT* this_thread_info = (ThreadDataT*) my_input;
    int i = 0;
    while(i<14)
    {
        i++;
        sleep(1);
        printf("%s %d\n",
                this_thread_info->message,
                this_thread_info->thread_id);
    }
    //pthread_t pthread_self(void);
    pthread_t my_threadid = pthread_self();
    printf("My thread_id before exiting the thread: %lu\n", my_threadid);

    unsigned long int* data_to_send_to_parent = (unsigned long int*) malloc(sizeof(unsigned long int));
    *data_to_send_to_parent = my_threadid;
    //pthread_exit(NULL);
    pthread_exit((void*) data_to_send_to_parent);
}

int main ()
{
    pthread_t      my_threads[MAX_THREADS];
    pthread_attr_t my_thread_attributes[MAX_THREADS];

    ThreadDataT my_thread_data[MAX_THREADS];

    int return_code, i;

    for (i = 0; i< MAX_THREADS ; i++)
    {
        printf("Main thread creating thread number: %d\n", i+1);
        my_thread_data[i].thread_id = i+1;
        strncpy(my_thread_data[i].message, "This is a child Thread with thread id: ",
                strlen("This is a child Thread with thread id: "));

        pthread_attr_init(&my_thread_attributes[i]);
        //pthread_attr_setdetachstate(&my_thread_attributes[i], PTHREAD_CREATE_DETACHED);
        pthread_attr_setdetachstate(&my_thread_attributes[i], PTHREAD_CREATE_JOINABLE);
        return_code = pthread_create( &my_threads[i],
                                      &my_thread_attributes[i],
                                      PrintThreadDetail,
                                      (void*)&my_thread_data[i]);
        if(return_code)
        {
            printf("Pthread creation failed for some reason\n");
            return 1;
        }
    }
    sleep(20);

    void* reply_from_thread[MAX_THREADS];
    for(i = 0; i< MAX_THREADS ; i++)
    {
        //pthread_join(pthread_t, void **);
        pthread_join(my_threads[i], &reply_from_thread[i]);
        printf("In main thread, reply from child thread is: %lu\n", *(unsigned long int*)reply_from_thread[i]);
        free(reply_from_thread[i]);
    }

    return 0;
}
