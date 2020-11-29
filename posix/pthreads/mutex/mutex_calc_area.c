#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define NUM_THREADS      (4)
#define NUM_RECTANGLE    (1000000)
//#define NUM_RECTANGLE    (10)
typedef struct RectangleS {
    int length;
    int breadth;
    int area;
} RectangleT;

typedef struct SetOfRectanglesS {
    RectangleT* my_rectangles[NUM_RECTANGLE];
    int index;
    pthread_mutex_t rect_mutex;
} SetOfRectanglesT;

SetOfRectanglesT* initalizeRectangles()
{
    SetOfRectanglesT* my_rectangle_set = (SetOfRectanglesT*) malloc(sizeof(SetOfRectanglesT));
    my_rectangle_set->index = 0;

    RectangleT* tempRectangle;
    int i = 0;
    for (i = 0; i< NUM_RECTANGLE; i++)
    {
        tempRectangle = (RectangleT*) malloc(sizeof(RectangleT));
        tempRectangle->length  = 30;
        tempRectangle->breadth = 40;
        tempRectangle->area    = -1;
        my_rectangle_set->my_rectangles[i] = tempRectangle;
    }

    pthread_mutex_init(&(my_rectangle_set->rect_mutex), NULL);
    return my_rectangle_set;
}

void* asyncCalcArea(void* rectSet)
{
    //pthread_t pthread_self(void);
    pthread_t my_thread_id = pthread_self();
    int* num_rectangles_processed = (int*) malloc(sizeof(int));
    memset(num_rectangles_processed, 0, sizeof(int));

    SetOfRectanglesT*  threadLocalRectangleSet = (SetOfRectanglesT*) rectSet;
    pthread_mutex_t*   thread_local_mutex = &(threadLocalRectangleSet->rect_mutex);
    int i;
    RectangleT* local_rectangle;

    //int   pthread_mutex_lock(pthread_mutex_t *);
    //int   pthread_mutex_unlock(pthread_mutex_t *);
    pthread_mutex_lock(thread_local_mutex);
    i = threadLocalRectangleSet->index;
    pthread_mutex_unlock(thread_local_mutex);

    for ( ; i < NUM_RECTANGLE; i++)
    {
        pthread_mutex_lock(thread_local_mutex);
            i = threadLocalRectangleSet->index;
            threadLocalRectangleSet->index = threadLocalRectangleSet->index + 1;
        pthread_mutex_unlock(thread_local_mutex);
        if(i>=NUM_RECTANGLE)
            break;

        local_rectangle = threadLocalRectangleSet->my_rectangles[i];
        if(local_rectangle->area == -1)
        {
            printf("Found fresh uncalculated area struct. Mutex working. Thread id: %lu\n", (unsigned long int) my_thread_id);
            local_rectangle->area = local_rectangle->length * local_rectangle->breadth;
            *num_rectangles_processed  = *num_rectangles_processed + 1;
        }
        else{
            printf("Found stale calculated area struct. Mutex not working. Thread id: %lu\n", (unsigned long int) my_thread_id);
        }
    }
    //void  pthread_exit(void *);
    pthread_exit(num_rectangles_processed);
}

int main ()
{
    SetOfRectanglesT* my_rectangles = initalizeRectangles();

    pthread_t      my_threads[NUM_THREADS];
    pthread_attr_t my_thr_attr[NUM_THREADS];

    int i, return_code;
    for (i = 0; i < NUM_THREADS; i++)
    {
        //int   pthread_attr_init(pthread_attr_t *);
        pthread_attr_init(&my_thr_attr[i]);
        //int   pthread_attr_setdetachstate(pthread_attr_t *, int);
        pthread_attr_setdetachstate( &my_thr_attr[i], PTHREAD_CREATE_JOINABLE);
        //int   pthread_create(pthread_t *restrict, const pthread_attr_t *restrict,
        //                        void *(*)(void *), void *restrict);
        return_code = pthread_create( &my_threads[i],
                &my_thr_attr[i],
                asyncCalcArea,
                (void*) my_rectangles);
        if(return_code)
        {
            printf("Pthread creation failed for some reason\n");
            return 1;
        }
    }

    void* result;
    for(i = 0; i < NUM_THREADS; i++)
    {
        //int   pthread_join(pthread_t, void **);
        pthread_join(my_threads[i], &result);
        printf("Thread %d porcessed %d rectangles\n", i, *((int*) result));
    }

    return 0;
}
