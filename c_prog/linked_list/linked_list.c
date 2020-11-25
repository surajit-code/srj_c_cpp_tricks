#include <stdio.h>
#include "create_ll.h"

/*
 * I found the only complicated operation to be
 * singly linked LinkedList reversal
 * I used GDB to debug my way into solving it
 * Not sure if I can repeat that from the top of my
 * head on some web based coding enviornment
 *
 * Takeaway: GDB is your friend
 */

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
    appendToLinkedList(myLL, 16);
    appendToLinkedList(myLL, 17);
    appendToLinkedList(myLL, 18);
    appendToLinkedList(myLL, 19);
    appendToLinkedList(myLL, 20);
    printLinkedList(myLL);

    deleteFromLinkedListByValue(myLL, 1);
    printLinkedList(myLL);
    deleteFromLinkedListByValue(myLL, 20);
    printLinkedList(myLL);
    deleteFromLinkedListByValue(myLL, 4);
    printLinkedList(myLL);
    deleteFromLinkedListByValue(myLL, 27);
    printLinkedList(myLL);

    reverseLinkedList(myLL);
    printLinkedList(myLL);
    return 0;
}
