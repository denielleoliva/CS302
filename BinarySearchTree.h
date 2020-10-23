/** Link-based implementation of the ADT binary search tree.@file BinarySearchTree.h */
#ifndef BINARY_SEARCH_TREE_
#define BINARY_SEARCH_TREE_
#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "BinaryNodeTree.h"
#include "NotFoundException.h"
#include "PrecondViolatedExcept.h"
#include <memory>

template<classItemType>
classBinarySearchTree : publicBinaryNodeTree<ItemType>{
    
    private:std::shared_ptr<BinaryNode<ItemType>> rootPtr;
    protected:
    //------------------------------------------------------------
    //    Protected Utility Methods Section:
    //    Recursive helper methods for the public methods.
    //------------------------------------------------------------
    // Places a given new node at its proper position in this binary
    // search tree.
    autoplaceNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                  std::shared_ptr<BinaryNode<ItemType>> newNode);
    
    // Removes the given target value from the tree whilemaintaining a
    // binary search tree.
    autoremoveValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                    constItemType target,
                    bool& isSuccessful) override;
    // Removes a given node from a tree while maintaining a binary search tree.
    autoremoveNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr);
    // Removes the leftmost node in the left subtree of the node
    // pointed to by nodePtr.
    // Sets inorderSuccessor to the value in this node.
    // Returns a pointer to the revised subtree.
    autoremoveLeftmostNode(std::shared_ptr<BinaryNode<ItemType>>subTreePtr,
                           ItemType& inorderSuccessor);
    
    // Returns a pointer to the node containing the given value,
    // or nullptr if not found.
    autofindNode(std::shared_ptr<BinaryNode<ItemType>> treePtr,
                constItemType& target) const;

    public:
    //------------------------------------------------------------
    // Constructor and Destructor Section.
    //------------------------------------------------------------
    BinarySearchTree();
    BinarySearchTree(constItemType& rootItem);
    BinarySearchTree(constBinarySearchTree<ItemType>& tree);
    virtual~BinarySearchTree();
    //------------------------------------------------------------
    // Public Methods Section.
    //------------------------------------------------------------
    boolisEmpty() const;
    intgetHeight() const;
    intgetNumberOfNodes() const;
    ItemType getRootData() const throw(PrecondViolatedExcept);
    voidsetRootData(constItemType& newData);
    
    booladd(constItemType& newEntry);

    boolremove(constItemType& target);
    voidclear();
    ItemType getEntry(constItemType& anEntry) const throw(NotFoundException);
    bool contains(constItemType& anEntry) const;
    //------------------------------------------------------------
    // Public Traversals Section.
    //------------------------------------------------------------
    void preorderTraverse(voidvisit(ItemType&)) const;
    voidinorderTraverse(voidvisit(ItemType&)) const;
    voidpostorderTraverse(voidvisit(ItemType&)) const;
    //------------------------------------------------------------
    // Overloaded Operator Section.
    //------------------------------------------------------------
    BinarySearchTree<ItemType>&
    operator=(constBinarySearchTree<ItemType>& rightHandSide);
    }; // end BinarySearchTree
    
    
#include "BinarySearchTree.cpp"
#endif