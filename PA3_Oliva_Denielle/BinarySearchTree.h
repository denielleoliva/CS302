#ifndef BINARY_SEARCH_TREE_
#define BINARY_SEARCH_TREE_

#include "BinaryNode.h"
#include "NotFoundException.h"
#include "PrecondViolatedExcept.h"
#include <memory>

template<class ItemType>
class BinarySearchTree
{
private:
    BinaryNode<ItemType> rootPtr;

protected:

BinaryNode<ItemType> placeNode(BinaryNode<ItemType> subTreePtr, BinaryNode<ItemType> newNode);

int getHeightHelper(BinaryNode<ItemType> subTreePtr) const;

int getNumberOfNodesHelper(BinaryNode<ItemType> subTreePtr) const;

auto removeValue(BinaryNode<ItemType> subTreePtr, const ItemType target,
                    bool& isSuccessful);

auto removeNode(BinaryNode<ItemType> nodePtr);

auto removeLeftMostNode(BinaryNode<ItemType> subTreePtr,
                            ItemType& inorderSuccessor);

auto findNode(BinaryNode<ItemType> treePtr);

public:
    BinarySearchTree();
    BinarySearchTree(const ItemType& rootItem);
    BinarySearchTree(const BinarySearchTree<ItemType>& tree);
    ~BinarySearchTree();

    bool isEmpty() const;
    int getHeight() const;
    int getNumberOfNodes() const;
    ItemType getRootData() const throw(PrecondViolatedExcept);
    void setRootData(const ItemType& newData);

    bool add(const ItemType& newEntry);

    bool remove(const ItemType& target);

    void clear();
    ItemType getEntry(const ItemType& anEntry) const throw(NotFoundException);
    
    void preorderTraverse() const;
    void inorderTraverse() const;
    void postorderTraverse() const;
};



#include "BinarySearchTree.cpp"
#endif