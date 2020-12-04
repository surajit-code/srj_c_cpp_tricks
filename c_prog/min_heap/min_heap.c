#include <stdio.h>
#include <stdlib.h>

#define HEAP_CAPACITY (100)

typedef struct HeapS {
    int elements[HEAP_CAPACITY];
    unsigned int max_index;
} HeapT;

int getLeftIndex(int i)
{
    return (i*2)+1;
}

int getRightIndex(int i)
{
    return (i*2)+2;
}

int getParentIndex(int i)
{
    if((i == 1) || (i==2) || (i==0))
        return 0;

    if ((i%2) == 0)
        return (i/2) + 1;
    else
        return (i/2);
}

HeapT* initializeHeap(int value)
{
    HeapT* myHeap = (HeapT*) malloc(sizeof(HeapT));
    myHeap->elements[0] = value;
    myHeap->max_index = 0;
    return myHeap;
}

void heapifyUp(HeapT* thisHeap, int currentIndex)
{
    printf("Entering %s() index: %d\n", __FUNCTION__ , currentIndex);
    int currentValue = thisHeap->elements[currentIndex];
    int parentIndex  = getParentIndex(currentIndex);
    if(currentIndex==parentIndex)
        return;
    int parentValue  = thisHeap->elements[parentIndex];
    if(currentValue>=parentValue)
        return;
    else
    {
        thisHeap->elements[currentIndex] = parentValue;
        thisHeap->elements[parentIndex]  = currentValue;
        heapifyUp(thisHeap, parentIndex);
    }
}

void insertHeap(HeapT* thisHeap, int value)
{
    printf("Entering: %s() value %d\n", __FUNCTION__ , value);
    if(thisHeap->max_index + 1 == HEAP_CAPACITY )
    {
        printf("Heap at capacity, cannot add anymore nodes\n");
        return;
    }
    thisHeap->elements[thisHeap->max_index + 1] = value;
    heapifyUp(thisHeap, thisHeap->max_index + 1);
    thisHeap->max_index = thisHeap->max_index+1;
}

void heapifyDown(HeapT* thisHeap, int currentIndex)
{
    int currentValue    = thisHeap->elements[currentIndex];
    int leftChildIndex  = getLeftIndex(currentIndex);
    int rightChildIndex = getRightIndex(currentIndex);
    int leftChild       = thisHeap->elements[leftChildIndex];
    int rightChild      = thisHeap->elements[rightChildIndex];
    if(rightChildIndex > thisHeap->max_index)
    {
        if(leftChildIndex > thisHeap->max_index)
            return;

        //compare only with left child and hapify down
        else if (leftChild<currentValue)
        {
            thisHeap->elements[currentIndex]   = leftChild;
            thisHeap->elements[leftChildIndex] = currentValue;
            heapifyDown(thisHeap, leftChildIndex);
        }
        else
            return;
    }
    else if( leftChildIndex > thisHeap->max_index)
    {
        return;
    }
    else
    {
        //find the smaller of the two children and heapifyDown with that
        if (leftChild < rightChild)
        {
            if (leftChild<currentValue)
            {
                thisHeap->elements[currentIndex]   = leftChild;
                thisHeap->elements[leftChildIndex] = currentValue;
                heapifyDown(thisHeap, leftChildIndex);
            }
            else
                return;
        }
        else if(rightChild < leftChild )
        {
            if (rightChild<currentValue)
            {
                thisHeap->elements[currentIndex]    = rightChild;
                thisHeap->elements[rightChildIndex] = currentValue;
                heapifyDown(thisHeap, rightChildIndex);
            }
            else
                return;
        }
        else
            return;
    }
}
int removeMinElement(HeapT* thisHeap)
{
    int result = thisHeap->elements[0];
    thisHeap->elements[0] = thisHeap->elements[thisHeap->max_index];
    thisHeap->max_index = thisHeap->max_index - 1;
    heapifyDown(thisHeap, 0);
    thisHeap->elements[thisHeap->max_index + 1] = 0;

    return result;
}

void printFullHeapData(HeapT* thisHeap)
{
    printf("Max Index: %3d\n", thisHeap->max_index);
    printf("Values: \n");
    int i = 0;
    for(i = 0; i < HEAP_CAPACITY ; i++)
    {
        printf("  %d", thisHeap->elements[i]);
    }
    printf("\n");
}
int main()
{
    HeapT* myHeap = initializeHeap(12);
    insertHeap(myHeap, 5);
    insertHeap(myHeap, 7);
    insertHeap(myHeap, 9);
    insertHeap(myHeap, 4);
    insertHeap(myHeap, 2);
    printFullHeapData(myHeap);
    printf("Called removeMinElement. min element: %d\n", removeMinElement(myHeap));
    printFullHeapData(myHeap);
    printf("Called removeMinElement. min element: %d\n", removeMinElement(myHeap));
    printFullHeapData(myHeap);
    printf("Called removeMinElement. min element: %d\n", removeMinElement(myHeap));
    printFullHeapData(myHeap);
    return 0;
}
