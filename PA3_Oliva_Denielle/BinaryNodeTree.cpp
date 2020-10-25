#include "BinaryNodeTree.h"
#include "BinaryNode.h"
#include "PrecondViolatedExcept.h"
#include "NotFoundException.h"


template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree() : rootPtr(nullptr){

} // end default constructor

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem): 
                            rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem, nullptr, nullptr)){

} // end constructor


template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem, 
                                            const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr,
                                            const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr): 
                                rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem, 
                                                                                copyTree(leftTreePtr->rootPtr),
                                                                                copyTree(rightTreePtr->rootPtr)){
                        
} // end constructor


