#include<stdio.h>
#include "create_bst.h"

int main()
{
    BinarySearchTreeT* myBT = intializeBinarySearchTree(1);
    insertToBinarySearchTree(myBT, 2);
    insertToBinarySearchTree(myBT, 3);
    insertToBinarySearchTree(myBT, 10);
    insertToBinarySearchTree(myBT, 7);
    printBinarySearchTree(myBT);
    insertToBinarySearchTree(myBT, 10);
    printBinarySearchTree(myBT);

    searchBinarySearchTree(myBT, 7);
    searchBinarySearchTree(myBT, 12);
    searchBinarySearchTree(myBT, 5);
    searchBinarySearchTree(myBT, -2);
    searchBinarySearchTree(myBT, 1);
    searchBinarySearchTree(myBT, 10);

    deleteFromBinarySearchTree(myBT, 1);
    deleteFromBinarySearchTree(myBT, 12);
    deleteFromBinarySearchTree(myBT, 5);
    deleteFromBinarySearchTree(myBT, 7);

    inOrderTraversal(myBT);   //Will print the values in ascending order
    preOrderTraversal(myBT);  //Will print the values in the order you inserted them
    postOrderTraversal(myBT); //Will print the values in reverse of order of insertion

    return 0;
}
