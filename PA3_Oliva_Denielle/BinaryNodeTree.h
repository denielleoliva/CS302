#ifndef BINARY_NODE_TREE_
#define BINARY_NODE_TREE_

#include "BinaryNode.h"
#include "PrecondViolatedExcept.h"
#include "NotFoundException.h"

template<class ItemType>
class BinaryNodeTree: public BinaryTreeInterface<ItemType>{
    
    private:
        std::share_ptr<BinaryNode<ItemType>> rootPtr;

    protected:
        //Protected Utility Methods: Recursive helper methods for the public methods
        int getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
        int getNumberOfNodesHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;

        auto balanceAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                            std::shared_ptr<BinaryNode<ItemType>> newNodePtr);

        virtual auto removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                            const ItemType target, bool& isSuccessful);
        
        // Copies values up the tree to overwrite value in current node until a leaf is reached.
        // the leaf is then removed, since its value is stored in the parent.
        auto moveValuesUpTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr);
        
        // Recursively searches for target value.
        virtualautofindNode(std::shared_ptr<BinaryNode<ItemType>> treePtr,
                            const ItemType& target, bool& isSuccessful) const;
        // Copies the tree rooted at treePtrand returns a pointer to the root of the copy
        auto copyTree(conststd::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const;
        
        // Recursively deletes all nodes from the tree
        void destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr);

        // Recursive traversal helper methods
        void preorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
        void inorder(voidvisit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
        void postorder(voidvisit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
        
    
    public: 
        // CONSTRUCTOR AND DESTRUCTOR SECTION
        BinaryNodeTree();
        BinaryNodeTree(const ItemType& rootItem);
        BinaryNodeTree(const ItemType& rootItem,
                        const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr,
                        const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr);
        BinaryNodeTree(const std::shared_ptr<BinaryNodeTree<ItemType>>& tree);
        virtual~BinaryNodeTree();

        // PUBLIC BINARY_TREE_INTERFACE METHODS SECTION
        bool isEmpty() const;
        int getHeight() const;
        int getNumberOfNodes() const;
        ItemType getRootData() const throw(PrecondViolatedExcept);
        bool add(constItemType& newData); // Adds an item to the tree
        bool remove(constItemType& data); // Removes specified item from the tree
        void clear();
        ItemType getEntry(constItemType& anEntry) const throw(NotFoundException);
        bool contains(constItemType& anEntry) const; 

        // PUBLIC TRAVERSAL SECTION
        void preorderTraverse(voidvisit(ItemType&)) const;
        void inorderTraverse(voidvisit(ItemType&)) const;
        void postorderTraverse(voidvisit(ItemType&)) const;
        
        // OVERLOADED OPERATOR SECTION
        BinaryNodeTree& operator= (constBinaryNodeTree& rightHandSide);
}; // end BinaryNodeTree



#include “BinaryNodeTree.cpp”
#endif


