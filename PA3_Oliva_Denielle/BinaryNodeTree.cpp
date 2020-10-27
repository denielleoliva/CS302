#include "BinaryNodeTree.h"
#include "BinaryTreeInterface.h"
#include "BinaryNode.h"

#include <iostream>

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree() : rootPtr(nullptr){

}

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem) :
            rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem, nullptr, nullptr)){

}


template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem,
                        const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr,
                        const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr):
                rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem,
                                copyTree(leftTreePtr->rootPtr),
                                copyTree(rightTreePtr->rootPtr))){

}

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const std::shared_ptr<BinaryNodeTree<ItemType>>& tree){

}


