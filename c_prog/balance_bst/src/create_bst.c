#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_bst.h"

BinarySearchTreeT* intializeBinarySearchTree (int rootValue)
{
    NodeT* rootNode  = (NodeT*) malloc(sizeof(NodeT));
    rootNode->parent = NULL;
    rootNode->value  = rootValue;
    rootNode->left   = NULL;
    rootNode->right  = NULL;

    BinarySearchTreeT* myTree = (BinarySearchTreeT*) malloc(sizeof(BinarySearchTreeT));
    myTree->root              = rootNode;

    return myTree;
}

void insertNode(NodeT* previousNode, NodeT* thisNode, int input, LeftOrRightT lr_indicator)
{
    if (thisNode == NULL)
    {
        thisNode = (NodeT*) malloc (sizeof(NodeT));
        thisNode->value  = input;
        thisNode->parent = previousNode;
        thisNode->left   = NULL;
        thisNode->right  = NULL;
        if(lr_indicator == left)
            previousNode->left = thisNode;
        else
            previousNode->right = thisNode;
        return;
    }

    if (input == thisNode->value)
        return;
    if(input < thisNode->value)
    {
        insertNode(thisNode, thisNode->left, input, left);
    }
    else
    {
        insertNode(thisNode, thisNode->right, input, right);
    }
}

void insertToBinarySearchTree(BinarySearchTreeT* bt, int input)
{
    LeftOrRightT lr_indicator;
    NodeT* current = bt->root;
    if (input == current->value)
        return;
    if (input < current->value)
    {
        lr_indicator = left;
        insertNode(current, current->left, input, lr_indicator);
    }
    else
    {
        lr_indicator = right;
        insertNode(current, current->right, input, lr_indicator);
    }
}

void printNode(NodeT* thisNode)
{
    printf("Value: %d\n", thisNode->value);
    if(thisNode->left)
        printNode(thisNode->left);
    if(thisNode->right)
        printNode(thisNode->right);
}

void printBinarySearchTree (BinarySearchTreeT* bt)
{
    printf("\n");
    NodeT* current = bt->root;
    printf("Value: %d\n", current->value);
    if(current->left)
    {
        printNode(current->left);
    }
    if(current->right)
    {
        printNode(current->right);
    }
}

NodeT* lookInNode(NodeT* thisNode, int value)
{
    if(thisNode->value == value)
    {
        printf("Value %d found\n", thisNode->value);
        return thisNode;
    }

    if (value < thisNode->value)
    {
        if (thisNode->left == NULL)
        {
            printf("Value %d not found\n", value);
            return NULL;
        }
        else
        {
            return lookInNode(thisNode->left, value);
        }
    }
    else
    {
        if (thisNode->right == NULL)
        {
            printf("Value %d not found\n", value);
            return NULL;
        }
        else
        {
            return lookInNode(thisNode->right, value);
        }
    }
}

NodeT* searchBinarySearchTree(BinarySearchTreeT* bt, int value)
{
   if (bt->root->value == value)
   {
       printf("Value %d found\n", bt->root->value);
       return bt->root;
   }

   NodeT* thisNode = bt->root;
   if (value < thisNode->value)
   {
       if (thisNode->left == NULL)
       {
           printf("Value %d not found\n", value);
           return NULL;
       }
       else
       {
           return lookInNode(thisNode->left, value);
       }
   }
   else
   {
       if (thisNode->right == NULL)
       {
           printf("Value %d not found\n", value);
           return NULL;
       }
       else
       {
           return lookInNode(thisNode->right, value);
       }
   }
}

void populateArrayInOrder(SortedArrayT* sortedArray, int value)
{
   sortedArray->array[sortedArray->index] = value;
   sortedArray->index = sortedArray->index + 1;
}

void printInOrder(NodeT* thisNode, SortedArrayT* sortedArray) //left->root->right
{
    if(thisNode->left!=NULL)
    {
        printInOrder(thisNode->left, sortedArray);
    }
    printf("In order value: %d\n", thisNode->value);
    populateArrayInOrder(sortedArray, thisNode->value);
    if(thisNode->right)
    {
        printInOrder(thisNode->right, sortedArray);
    }
}

SortedArrayT* inOrderTraversal(BinarySearchTreeT* bst)
{
    SortedArrayT* sortedArray = (SortedArrayT*) malloc(sizeof(SortedArrayT));
    memset(sortedArray, 0, sizeof(SortedArrayT));
    printf("Begin In order traversal\n");
    NodeT* current = bst->root;
    printInOrder(current, sortedArray);
    printf("End In order traversal\n");
    return sortedArray;
}

void printPreOrder(NodeT* thisNode) //root->left->right
{
    printf("Pre order value: %d\n", thisNode->value);
    if(thisNode->left != NULL)
    {
        printPreOrder(thisNode->left);
    }
    if(thisNode->right != NULL)
    {
        printPreOrder(thisNode->right);
    }
}
void preOrderTraversal(BinarySearchTreeT* bst)
{
    printf("Begin Pre order traversal\n");
    NodeT* current = bst->root;
    printPreOrder(current);
    printf("End Pre order traversal\n");

}

void printPostOrder(NodeT* thisNode) //left->right->root
{
    if(thisNode->left)
    {
        printPostOrder(thisNode->left);
    }
    if(thisNode->right)
    {
        printPostOrder(thisNode->right);
    }
    printf("Post order value: %d\n", thisNode->value);
}

void postOrderTraversal(BinarySearchTreeT* bst)
{
    printf("Begin Post order traversal\n");
    NodeT* current = bst->root;
    printPostOrder(current);
    printf("End Post order traversal\n");
}

void insertToBalancedBST ( BinarySearchTreeT* myBalancedBST, int* arrayStartIndex, int length)
{
    printf("Enter %s() length: %d, startIndexValue: %d\n", __FUNCTION__ , length, *arrayStartIndex);
    insertToBinarySearchTree(myBalancedBST, *arrayStartIndex);
    if(length==1)
        return;
    insertToBalancedBST(myBalancedBST, arrayStartIndex, length/2);
    insertToBalancedBST(myBalancedBST, arrayStartIndex + (length/2), length - length/2);
}

BinarySearchTreeT* getBalancedBinarySearchTree(SortedArrayT* mySortedArray)
{
    BinarySearchTreeT* myBalancedBST = intializeBinarySearchTree(mySortedArray->array[mySortedArray->index / 2]);
    insertToBalancedBST(myBalancedBST, mySortedArray->array, mySortedArray->index/2);
    insertToBalancedBST(myBalancedBST, mySortedArray->array + (mySortedArray->index/2), mySortedArray->index - mySortedArray->index/2);
    return myBalancedBST;
}
