#ifndef __create_bst_h__
#define __create_bst_h__

#define SORT_CAPACITY    (1000)
typedef struct NodeS NodeT;
typedef struct NodeS {
    NodeT* parent;
    int value;
    NodeT* left;
    NodeT* right;
} NodeT;

typedef struct BinarySearchTreeS {
    NodeT* root;
} BinarySearchTreeT;

typedef enum LeftOrRightE {
    left,
    right
} LeftOrRightT;

typedef struct SortedArrayS {
    int array[ SORT_CAPACITY ];
    int index;
} SortedArrayT;

BinarySearchTreeT* intializeBinarySearchTree (int rootValue);
void insertNode(NodeT* previousNode, NodeT* thisNode, int input, LeftOrRightT lr_indicator);
void insertToBinarySearchTree(BinarySearchTreeT* bt, int input);
void printBinarySearchTree (BinarySearchTreeT* bt);
void printNode(NodeT* thisNode);
void printBinarySearchTree (BinarySearchTreeT* bt);
NodeT* lookInNode(NodeT* thisNode, int value);
NodeT* searchBinarySearchTree(BinarySearchTreeT* bt, int value);
void populateArrayInOrder(SortedArrayT* sortedArray, int value);
void printInOrder(NodeT* thisNode, SortedArrayT* sortedArray);
SortedArrayT* inOrderTraversal(BinarySearchTreeT* bst);
void printPreOrder(NodeT* thisNode);
void preOrderTraversal(BinarySearchTreeT* bst);
void printPostOrder(NodeT* thisNode);
void postOrderTraversal(BinarySearchTreeT* bst);

void insertToBalancedBST ( BinarySearchTreeT* myBalancedBST, int* arrayStartIndex, int length);
BinarySearchTreeT* getBalancedBinarySearchTree(SortedArrayT* mySortedArray);
#endif
