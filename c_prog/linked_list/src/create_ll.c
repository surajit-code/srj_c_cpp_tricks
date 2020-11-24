#include <stdio.h>
#include <stdlib.h>
#include "create_ll.h"

LinkedListT* intializeLinkedList(int firstData)
{
    NodeT* thisNode = (NodeT*) malloc(sizeof(NodeT*));
    thisNode->data = firstData;
    thisNode->next = NULL;

    LinkedListT* llHead = (LinkedListT*) malloc(sizeof(LinkedListT));
    llHead->head = thisNode;

    return llHead;
}

void printLinkedList(LinkedListT* ll)
{
    printf("Printing my LinkedList's contents:\n");
    NodeT* current = ll->head;
    while(current)
    {
        printf("Value : %d\n", current->data);
        current = current->next;
    }
    printf("LinkedList's end\n");
}

void appendToLinkedList(LinkedListT* ll, int value)
{
    NodeT* current = ll->head;
    NodeT* previous;
    while(current)
    {
        previous = current;
        current = current->next;
    }

    NodeT* newNode = (NodeT*) malloc(sizeof(NodeT));
    newNode->data = value;
    newNode->next = NULL;
    previous->next = newNode;
}

void deleteLinkedListFromHead(LinkedListT* ll)
{
    NodeT* current = ll->head;
    NodeT* second  = ll->head->next;
    ll->head = second;
    free(current);
}

void deleteLinkedListFromTail(LinkedListT* ll)
{
    NodeT* p_previous = ll->head;
    NodeT* previous = p_previous->next;
    NodeT* current = p_previous->next->next;
    while(current)
    {
        p_previous = p_previous->next;
        previous = previous->next;
        current = current->next;
    }
    p_previous->next = NULL;
    free(previous);
}

void deleteFromLinkedListByValue(LinkedListT* ll, int value)
{
    NodeT* current = ll->head;
    if(current->data == value)
    {
        printf("Need to delete head of this ll\n");
        deleteLinkedListFromHead(ll);
        return;
    }

    NodeT* previous = ll->head;
    current = previous->next;
    while (current)
    {
        if(current->data == value)
        {
            if(current->next == NULL)
            {
                printf("Need to delete tail of this ll\n");
                deleteLinkedListFromTail(ll);
                return;
            }
            else
            {
                printf("Need to delete from middle of ll\n");
                printf("previous data: %d\n", previous->data);
                printf("current data: %d\n", current->data);
                previous->next = previous->next->next;
                free(current);
                return;
            }
        }
        previous = current;
        current = current->next;
    }
}
