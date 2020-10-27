#ifndef BINARY_NODE_TREE_H_
#define BINARY_NODE_TREE_H_

#include "BinaryNode.h"
#include "BinaryTreeInterface.h"
#include "PrecondViolatedExcept.h"
#include "NotFoundException.h"

#include <iostream>
#include <memory>

template<class ItemType>
class BinaryNodeTree : public BinaryTreeInterface<ItemType>{
    private:
        std::shared_ptr<BinaryNode<ItemType>> rootPtr;

    protected:
        //RECURSIVE HELPER METHODS FOR PUBLIC METHODS
        int getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
        int getNumberOfNodesHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;

        //just to keep things *balanced*
        auto balanceAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                            std::shared_ptr<BinaryNode<ItemType>> newNodePtr);
        
        virtual void removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                                    const ItemType target, bool& isSuccessful);

        //why do i need this
        auto moveValuesUpTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr);

        virtual void findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr,
                                const ItemType& target, bool& isSuccessful) const;
        
        auto copyTree(const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const;

        void destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr);

        void preorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
        void inorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
        void postorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const;

    public:
        //constructors
        BinaryNodeTree();
        BinaryNodeTree(const ItemType& rootItem);
        BinaryNodeTree(const ItemType& rootItem,
                        const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr,
                        const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr);
        BinaryNodeTree(const std::shared_ptr<BinaryNodeTree<ItemType>>& tree);
        virtual ~BinaryNodeTree();

        bool isEmpty() const;
        int getHeight() const;
        int getNumberOfNodes() const;
        ItemType getRootData() const throw(PrecondViolatedExcept);
        bool add(const ItemType& newData);
        bool remove(const ItemType& data);
        void clear();
        ItemType getEntry(const ItemType& anEntry) const throw(NotFoundException);
        bool contains(const ItemType& anEntry) const;

        void preorderTraverse(void visit(ItemType&)) const;
        void inorderTraverse(void visit(ItemType&)) const;
        void postorderTraverse(void visit(ItemType&)) const;

        BinaryNodeTree& operator=(const BinaryNodeTree& rightHandSide);
};

//#include "BinaryNodeTree.cpp"
#endif 


