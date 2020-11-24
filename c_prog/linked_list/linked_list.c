#include <stdio.h>
#include "create_ll.h"

int main()
{
    LinkedListT* myLL =  intializeLinkedList(1);
    printLinkedList(myLL);
    appendToLinkedList(myLL, 2);
    appendToLinkedList(myLL, 3);
    appendToLinkedList(myLL, 4);
    appendToLinkedList(myLL, 5);
    appendToLinkedList(myLL, 6);
    appendToLinkedList(myLL, 7);
    appendToLinkedList(myLL, 8);
    appendToLinkedList(myLL, 9);
    appendToLinkedList(myLL, 10);
    appendToLinkedList(myLL, 11);
    appendToLinkedList(myLL, 12);
    appendToLinkedList(myLL, 13);
    appendToLinkedList(myLL, 14);
    appendToLinkedList(myLL, 15);
    printLinkedList(myLL);
    deleteFromLinkedListByValue(myLL, 1);
    printLinkedList(myLL);
    deleteFromLinkedListByValue(myLL, 15);
    printLinkedList(myLL);
    deleteFromLinkedListByValue(myLL, 4);
    printLinkedList(myLL);
    deleteFromLinkedListByValue(myLL, 17);
    printLinkedList(myLL);
    return 0;
}
