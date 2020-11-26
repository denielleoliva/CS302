#include <iostream>

#include "BinaryNode.h"

template<class ItemType>
BinaryNode<ItemType>::BinaryNode(): node(nullptr), 
                                    leftChild(nullptr), 
                                    rightChild(nullptr){
    
}

template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType &source): node(source),
                                                            leftChild(nullptr),
                                                            rightChild(nullptr){

}

template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType &source, BinaryNode* left, BinaryNode* right): 
                        node(source),
                        leftChild(left),
                        rightChild(right){

}

template<class ItemType>
void BinaryNode<ItemType>::setNode(const ItemType &nd){
    node = nd;
}

template<class ItemType>
ItemType BinaryNode<ItemType>::getNode() const{
    return node;
}

template<class ItemType>
bool BinaryNode<ItemType>::ifLeaf() const{
    return ((this->getLeftChild()==nullptr)&&(this->getRightChild()==nullptr));
}

template<class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getLeftChild() const{
    return this->leftChild;
}

template<class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getRightChild() const{
    return this->rightChild;
}

template<class ItemType>
void BinaryNode<ItemType>::setLeftChild(BinaryNode* leftPtr){
    this->leftChild=leftPtr;
}

template<class ItemType>
void BinaryNode<ItemType>::setRightChild(BinaryNode* rightPtr){
    this->rightChild=rightPtr;
}