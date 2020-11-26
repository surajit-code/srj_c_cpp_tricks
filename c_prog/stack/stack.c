#include <stdio.h>
#include <stdlib.h>

typedef struct NodeS NodeT;

typedef struct NodeS {
    int data;
    NodeT* next;
} NodeT;

typedef struct StackS {
    NodeT* head;
}StackT;

StackT* initializeStack(int value)
{
    NodeT* thisNode = (NodeT*) malloc(sizeof(NodeT));
    thisNode->data = value;
    thisNode->next = NULL;

    StackT* result = (StackT*) malloc(sizeof(StackT));
    result->head = thisNode;
    return result;
}

void push(StackT* myStack, int value)
{
    NodeT* current  = myStack->head;
    NodeT* thisNode = (NodeT*) malloc(sizeof(NodeT));
    thisNode->data  = value;
    thisNode->next  = current;
    myStack->head   = thisNode;
}

int peek(StackT* myStack)
{
    return myStack->head->data;
}

int pop(StackT* myStack)
{
    NodeT* current = myStack->head;
    int result     = current->data;

    myStack->head = myStack->head->next;
    free(current);
    return result;
}

int main()
{
    StackT* myStack = initializeStack(1);
    push(myStack, 2);
    push(myStack, 3);
    push(myStack, 4);
    push(myStack, 5);
    push(myStack, 6);
    printf( "Peek at stack: %d\n", peek(myStack));
    printf( "Pop the stack: %d\n", pop(myStack));
    printf( "Peek at stack: %d\n", peek(myStack));
    return 0;
}
