#include "BinarySearchTree.h"
//#include "BinaryNode.h"


template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(): rootPtr(nullptr){

}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem): rootPtr(rootItem){

}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& tree) :
                                                                        rootPtr(tree->rootPtr){

}

template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree(){
    rootPtr=nullptr;
}

template<class ItemType>
auto BinarySearchTree<ItemType>::placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                  std::shared_ptr<BinaryNode<ItemType>> newNode){
    std::shared_ptr<BinaryNode<ItemType>>*tmp;
    BinaryNode<ItemType>* nd;

    if(subTreePtr==nullptr){
        return newNode;
    }else if(subTreePtr->getNode()>newNode->getNode()){
        tmp = placeNode(subTreePtr->getLeftChild(), newNode);
        //nd->setNode(tmp->get());
        subTreePtr->setLeftChild(std::static_pointer_cast<BinaryNode<ItemType>>(tmp));
    }else{
        tmp = placeNode(subTreePtr->getRightChild(), newNode);
        subTreePtr->setRightChild(tmp);
    }

    return subTreePtr;
}


template<class ItemType>
auto BinarySearchTree<ItemType>::removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                    const ItemType target,
                    bool& isSuccessful){
    std::shared_ptr<BinaryNode<ItemType>>* tmp;

    if(subTreePtr==nullptr){
        isSuccessful=false;
    }else if(subTreePtr->getNode()==target){
        subTreePtr=removeNode(subTreePtr);
        isSuccessful=true;
    }else if(subTreePtr->getNode()>target){
        tmp = removeValue(subTreePtr->getLeftChild(), target, isSuccessful);
        subTreePtr->setLeftChild(tmp);
    }else{
        tmp = removeValue(subTreePtr->getRightChild(), target, isSuccessful);
        subTreePtr->setRightChild(tmp);
    }

    return subTreePtr;

}


template<class ItemType>
auto BinarySearchTree<ItemType>::removeNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr){
    std::shared_ptr<BinaryNode<ItemType>>* tmp;

    int newVal = 0;

    if(rootPtr.isLeaf()){
        rootPtr=nullptr;
        return rootPtr;
    }else if(rootPtr->getLeftChild()!=nullptr&&rootPtr->getRightChild()!=nullptr){
        return rootPtr->getLeftChild();
    }else if(rootPtr->getRightChild()!=nullptr&&rootPtr->getLeftChild()!=nullptr){
        return rootPtr->getRightChild();
    }else{
        tmp = removeLeftmostNode(rootPtr->getRightChild(), newVal);
        rootPtr->setRightChild(tmp);
        rootPtr->setNode(newVal);
        return rootPtr;
    }
}


template<class ItemType>
auto BinarySearchTree<ItemType>::removeLeftmostNode(std::shared_ptr<BinaryNode<ItemType>>subTreePtr,
                           ItemType& inorderSuccessor){
    std::shared_ptr<BinaryNode<ItemType>>* tmp;

    if(subTreePtr->getLeftChild()==nullptr){
        inorderSuccessor = subTreePtr->getItem();
        return removeNode(subTreePtr);
    }else{
        tmp = removeLeftmostNode(subTreePtr->getLeftChild(), inorderSuccessor);
        subTreePtr->setLeftChild(tmp);
        return subTreePtr;
    }
}

/*
template<class ItemType>
auto BinarySearchTree<ItemType>::findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr,
                const ItemType& target) const{

}*/

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
    std::shared_ptr<BinaryNode<ItemType>> newDat;
    newDat->setNode(newEntry);
    rootPtr = placeNode(rootPtr, newDat);

    return true;
}


template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType& target){
    bool isSuccessful = false;
    this->rootPtr=removeValue(this->rootPtr, target, isSuccessful);
    return isSuccessful;
}

template<class ItemType>
void BinarySearchTree<ItemType>::clear(){
    rootPtr=nullptr;
}

/*
template<class ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType& anEntry) const throw(NotFoundException){

}*/

/*
template<class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& anEntry) const{

}*/


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

template<class ItemType>
BinarySearchTree<ItemType>& BinarySearchTree<ItemType>::
    operator=(const BinarySearchTree<ItemType>& rightHandSide){
        BinaryNode<ItemType> tmp;
        tmp = rightHandSide;
        return tmp;
}

