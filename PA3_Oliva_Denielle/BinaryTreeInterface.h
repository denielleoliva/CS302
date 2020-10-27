#ifndef BINARY_TREE_INTERFACE_H_
#define BINARY_TREE_INTERFACE_H_

#include "NotFoundException.h"

template<class ItemType>
class BinaryTreeInterface{

    public:
        //Tests whether binary tree is empty
        //@return True if the binary tree is empty, or false if not
        virtual bool isEmpty() const = 0;

        //Gets the height of this binary tree
        //@return the height of the binary tree
        virtual int getHeight() const = 0;

        //Gets the number of nodes in binary tree
        //@return the number nodes in the binary tree
        virtual int getNumberOfNodes() const = 0;

        //Gets the data in the roor of the binary tree
        //@pre: the binary tree is not empty
        //@post: the root's data has been returned, the binary tree is unchanged
        //@return: the data n the root of the binary tree
        virtual ItemType getRootData() const = 0;

        //Replaces the data in the root of this binary tree with the given data,
        //if the tree is not empty. If the tree is empty, inserts a new
        //root node containing the given data into the tree
        //@pre: none
        //@post: the data in the root of the binary tree is as given
        //@param: newData, the data for the root
        virtual bool setRootData(const ItemType& newData) = 0;

        //Adds the given data to this binary tree
        //@param: newData, the data to add to the binary tree
        //@post: the new binary tree contains new data
        //@return: True if the addition is successful
        virtual bool add(const ItemType& newData) = 0;

        //Removes the specified data from this binary tree
        //@param: target, the data to remove from the binary tree
        //@return: True, if the remove is successful
        virtual bool remove(const ItemType& target) = 0;

        //Removes all the data from binary tree
        virtual void clear() = 0;

        //Retrieves the specified data from this binary tree
        //@post: the desired data has been return, the binary tree is unchanged
        //          if no such data was found, exception is thrown
        //@param: target, the data to locate
        //@return: the data in the binary tree that matches the given data
        virtual ItemType getEntry(const ItemType& target) const = 0;

        //Tests whether the specified data occurs in this binary tree
        //@post the binary tree is unchanged
        //@param: target, the data to find
        //@return: True, if data matching the target occurs in the tree
        virtual bool contains(const ItemType& target) const = 0;

        //Traverse this binary tree in preorder (inorder, postorder) and
        //calls the function visit once for each node
        //@param: visit, a client defined function that performs an operation on either visited node or its data
        virtual void preorderTraverse(void visit(ItemType&)) const = 0;
        virtual void inorderTraverse(void visit(ItemType&)) const = 0;
        virtual void postorderTraverse(void visit(ItemType&)) const = 0;

        //Destroys the tree and frees its assigned memory
        virtual ~BinaryTreeInterface(){}


};

#endif