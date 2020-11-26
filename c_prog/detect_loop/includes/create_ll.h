#ifndef __create_ll__
#define __create_ll__

typedef struct NodeS NodeT;

typedef struct NodeS {
    int data;
    NodeT* next;
} NodeT;

typedef struct LinkedListS {
    NodeT* head;
} LinkedListT;

LinkedListT* intializeLinkedList(int firstData);
void printLinkedList(LinkedListT* ll);
void appendToLinkedList(LinkedListT* ll, int value);
void deleteLinkedListFromHead(LinkedListT* ll);
void deleteLinkedListFromTail(LinkedListT* ll);
void deleteFromLinkedListByValue(LinkedListT* ll, int value);
void reverseLinkedList(LinkedListT* ll);

#endif
