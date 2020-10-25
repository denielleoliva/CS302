#ifndef BINARY_NODE_H_
#define BINARY_NODE_H_

#include "NotFoundException.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class BinaryNode: public BinaryTreeInterface<itemType>{
    public:
        BinaryNode(); 
        BinaryNode(const ItemType &source);
        BinaryNode(const ItemType &copy, BinaryNode *left, BinaryNode *right);

        void setNode(const ItemType &nd);
        ItemType getNode() const;

        bool ifLeaf() const;

        BinaryNode* getLeftChild() const;
        BinaryNode* getRightChild() const;

        void setLeftChild(BinaryNode* leftPtr);
        void setRightChild(BinaryNode* rightPtr);

    private:
        ItemType node;
        BinaryNode* leftChild;
        BinaryNode* rightChild;

};

#endif