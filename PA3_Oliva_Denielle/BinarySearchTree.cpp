#include "BinarySearchTree.h"
#include "BinaryNode.h"

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(){
    rootPtr=NULL;
}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem): rootPtr(rootItem){

}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& tree){
    rootPtr=tree.rootPtr;
}

template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree(){
    rootPtr=NULL;
}

template<class ItemType>
BinaryNode<ItemType> BinarySearchTree<ItemType>::placeNode(BinaryNode<ItemType> subTreePtr, BinaryNode<ItemType> newNode){
    BinaryNode<ItemType> tmp;

    if(subTreePtr.getNode()==NULL){
        return newNode;
    }else if(subTreePtr.getNode()>newNode.getNode()){
        //tmp.setNode(placeNode(subTreePtr.getLeftChild(), newNode).getNode());
        subTreePtr.setLeftChild(&tmp);
    }else{
        tmp = placeNode(subTreePtr.getRightChild(), newNode);
        subTreePtr.setRightChild(&tmp);
    }

    return subTreePtr;
}

template<class ItemType>
int BinarySearchTree<ItemType>::getHeightHelper(BinaryNode<ItemType> subTreePtr) const{
        if(subTreePtr==nullptr){
                return 0;
        }else{
                return 1+std::max(getHeightHelper(subTreePtr->getLeftChild()), getHeightHelper(subTreePtr->getRightChild()));
        }
}

template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodesHelper(BinaryNode<ItemType> subTreePtr) const{
        if(subTreePtr==nullptr){
                return 0;
        }else{
                return 1+getNumberOfNodesHelper(subTreePtr->getLeftChild())+getNumberOfNodesHelper(subTreePtr->getRightChild());
        }
}

template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const{
    return rootPtr==nullptr;
}


template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const{
    return this->getHeightHelper(rootPtr);
}

template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const{
    return getNumberOfNodesHelper(rootPtr);
}

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const throw(PrecondViolatedExcept){
    return rootPtr->getNode();
}

template<class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType& newData){
    rootPtr.setNode(newData);
}

template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newEntry){
    BinaryNode<ItemType> newDat;
    newDat.setNode(newEntry);
    rootPtr = placeNode(rootPtr, newDat);

    return true;
}

template<class ItemType>
void BinarySearchTree<ItemType>::clear(){
    rootPtr=nullptr;
}

template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse() const{
    preorder(rootPtr);
}

template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse() const{
    inorder(rootPtr);
}

template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse() const{
    postorder(rootPtr);
}