#include <stdio.h>
#include <stdlib.h>

typedef struct NodeS NodeT;
typedef struct NodeS {
    int value;
    NodeT* next;
} NodeT;

typedef struct QueueS {
    NodeT* front;
    NodeT* back;
} QueueT;

QueueT* intializeQueue(int value)
{
    QueueT* myQueue  = (QueueT*) malloc(sizeof(QueueT));
    NodeT*  thisNode = (NodeT*) malloc(sizeof(NodeT));

    thisNode->value  = value;
    thisNode->next   = NULL;

    myQueue->front = thisNode;
    myQueue->back  = thisNode;

    return myQueue;
}

void enque(QueueT* myQ, int value)
{
    NodeT* thisNode = (NodeT*) malloc(sizeof(NodeT));
    thisNode->value = value;
    thisNode->next  = NULL;
    NodeT* currentNode = myQ->back;
    currentNode->next  = thisNode;
    myQ->back          = thisNode;

}

int peek(QueueT* myQ)
{
    if(myQ->front == NULL)
        return -1000;
    return myQ->front->value;
}

int deque(QueueT* myQ)
{
    //printf("%s: myQ->front->value %d myQ->front %p\n", __FUNCTION__, myQ->front->value, myQ->front);
    if(myQ->front==NULL)
    {
        return -1000;
    }
    int result = myQ->front->value;
    NodeT* nodeToDelete = myQ->front;
    myQ->front = myQ->front->next;
    free(nodeToDelete);
    return result;
}

int main()
{
    QueueT* myQ = intializeQueue(1);
    printf("Peek queue: %d\n", peek(myQ));
    enque(myQ,2);
    enque(myQ,3);
    enque(myQ,4);
    enque(myQ,5);
    enque(myQ,6);
    printf("Peek queue: %d\n", peek(myQ));
    printf("Deque: %d\n", deque(myQ));
    printf("Peek queue: %d\n", peek(myQ));
    printf("Deque: %d\n", deque(myQ));
    printf("Peek queue: %d\n", peek(myQ));
    enque(myQ,7);
    enque(myQ,8);
    enque(myQ,9);
    enque(myQ,10);
    enque(myQ,11);
    enque(myQ,12);
    printf("Deque: %d\n", deque(myQ));
    printf("Peek queue: %d\n", peek(myQ));
    printf("Deque: %d\n", deque(myQ));
    printf("Peek queue: %d\n", peek(myQ));
    printf("Deque: %d\n", deque(myQ));
    printf("Peek queue: %d\n", peek(myQ));
    printf("Deque: %d\n", deque(myQ));
    printf("Peek queue: %d\n", peek(myQ));
    printf("Deque: %d\n", deque(myQ));
    printf("Peek queue: %d\n", peek(myQ));
    printf("Deque: %d\n", deque(myQ));
    printf("Peek queue: %d\n", peek(myQ));
    printf("Deque: %d\n", deque(myQ));
    printf("Peek queue: %d\n", peek(myQ));
    printf("Deque: %d\n", deque(myQ));
    printf("Peek queue: %d\n", peek(myQ));
    printf("Deque: %d\n", deque(myQ));
    printf("Peek queue: %d\n", peek(myQ));
    
    printf("Deque: %d\n", deque(myQ));
    printf("Peek queue: %d\n", peek(myQ));
    
    printf("Deque: %d\n", deque(myQ));
    printf("Peek queue: %d\n", peek(myQ));


    return 0;
}
