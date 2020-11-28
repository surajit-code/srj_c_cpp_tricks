#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS  (5)

void* PrintHello(void* thread_id)
{
    int t_id;
    t_id = *((int*)thread_id);
    printf("Hello World! It's me, thread #%d!\n", t_id); //value at address of t_id keeps getting changed by main
    //this will not give you accurate thread id
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int rc;
    int t;
    for(t=0; t<NUM_THREADS; t++)
    {
        printf("In main: creating thread %d\n", t);
        rc = pthread_create(&threads[t], NULL, PrintHello, (void *)&t);
        //   pthread_create(address_of_thread, 
        //   ATTRIBUTE_BITMASK, 
        //   new_stack's_first_function_pointer,
        //   address_of_data_structure_sent_to_thread_cast_as_void_pointer);
        if (rc)
        {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    pthread_exit(NULL);
}
