#include <stdio.h>
#include "create_bst.h"

int main()
{
    BinarySearchTreeT* myBst = intializeBinarySearchTree (400);
    insertToBinarySearchTree(myBst, 500);
    insertToBinarySearchTree(myBst, 300);
    insertToBinarySearchTree(myBst, 600);
    insertToBinarySearchTree(myBst, 700);
    insertToBinarySearchTree(myBst, 800);
    insertToBinarySearchTree(myBst, 900);
    insertToBinarySearchTree(myBst, 1000);
    insertToBinarySearchTree(myBst, 1100);
    insertToBinarySearchTree(myBst, 1200);
    printBinarySearchTree(myBst);
    SortedArrayT* mySortedArray = inOrderTraversal(myBst);
    for (int i = 0; i < mySortedArray->index; i++)
    {
        printf("Sorted array values: %d at index: %d \n", mySortedArray->array[i], i);
    }

    BinarySearchTreeT*  myBalancedBST = getBalancedBinarySearchTree(mySortedArray);

    printBinarySearchTree(myBalancedBST);
    inOrderTraversal(myBalancedBST);

    return 0;
}
