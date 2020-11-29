#ifndef __create_bst_h__
#define __create_bst_h__

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

BinarySearchTreeT* intializeBinarySearchTree (int rootValue);
void insertNode(NodeT* previousNode, NodeT* thisNode, int input, LeftOrRightT lr_indicator);
void insertToBinarySearchTree(BinarySearchTreeT* bt, int input);
void printBinarySearchTree (BinarySearchTreeT* bt);
void printNode(NodeT* thisNode);
void printBinarySearchTree (BinarySearchTreeT* bt);
NodeT* lookInNode(NodeT* thisNode, int value);
NodeT* searchBinarySearchTree(BinarySearchTreeT* bt, int value);
void deleteFromBinarySearchTree(BinarySearchTreeT* bt, int value);
void printInOrder(NodeT* thisNode);
void inOrderTraversal(BinarySearchTreeT* bst);
void printPreOrder(NodeT* thisNode);
void preOrderTraversal(BinarySearchTreeT* bst);
void printPostOrder(NodeT* thisNode);
void postOrderTraversal(BinarySearchTreeT* bst);
#endif
