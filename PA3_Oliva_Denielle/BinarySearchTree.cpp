#include "BinarySearchTree.h"
#include "BinaryNode.h"

#include <iostream>

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(): rootPtr(nullptr){

}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem): rootPtr(rootItem){

}

//maybe this works
template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& tree) :
                                                                        rootPtr(tree->rootPtr){

}

template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree(){

}

template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const{
    return rootPtr==nullptr;
}

template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const{

}

template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const{
    if(isEmpty()){
        return 0;
    }
}

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const throw(PrecondViolatedExcept){
    return rootPtr->node;
}

template<class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType& newData){
    rootPtr.setNode(newData);
}

template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newEntry){
    BinaryNode<ItemType> newDat = new BinaryNode<ItemType>(newEntry);
    rootPtr = placeNode(rootPtr, newDat);

    return true;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType& target){

}

//this is wrong come back to this when you know how to do thing
template<class ItemType>
void BinarySearchTree<ItemType>::clear(){
    while(rootPtr!=nullptr){
        delete rootPtr;
    }
}


template<class ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType& anEntry) const throw(NotFoundException){

}

template<class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& anEntry) const{

}

template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(void visit(ItemType&)) const{
    
}