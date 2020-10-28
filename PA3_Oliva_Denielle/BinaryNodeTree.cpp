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
	rootPtr = copyTree(tree.rootPtr);
}

template<class ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const{
        if(subTreePtr==nullptr){
                return 0;
        }else{
                return 1+std::max(getHeightHelper(subTreePtr->getLeftChild()), getHeightHelper(subTreePtr->getRightChild()));
        }
}

template<class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodesHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const{
        if(subTreePtr==nullptr){
                return 0;
        }else{
                return 1+getNumberOfNodesHelper(subTreePtr->getLeftChild())+getNumberOfNodesHelper(subTreePtr->getRightChild());
        }
}

template<class ItemType>
auto BinaryNodeTree<ItemType>::balanceAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                            std::shared_ptr<BinaryNode<ItemType>> newNodePtr){
	if(subTreePtr==nullptr){
		return newNodePtr;
	}else{
		auto leftPtr=subTreePtr->getLeftChild();
		auto rightPtr=subTreePtr->getRightChild();

		if(getHeightHelper(leftPtr)>getHeightHelper(rightPtr)){
			rightPtr=balanceAdd(rightPtr, newNodePtr);
			subTreePtr->setRightChild(rightPtr);
		}else{
			leftPtr=balanceAdd(leftPtr, newNodePtr);
			subTreePtr->setLeftChild(leftPtr);
		}

		return subTreePtr;
	}
}

template<class ItemType>
ItemType* BinaryNodeTree<ItemType>::removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                                    const ItemType target, bool& isSuccessful){
	std::shared_ptr<BinaryNode<ItemType>>* tmp;

	if(subTreePtr==nullptr){
		isSuccessful=false;
	}else if(subTreePtr->getNode()==target){
		subTreePtr = remove(subTreePtr);
		isSuccessful=true;
	}else if(subTreePtr->getNode()>target){
		tmp=removeValue(subTreePtr->getLeftChild(), target, isSuccessful);
		subTreePtr->setLeftChild(tmp);
	}else{
		tmp=removeValue(subTreePtr->getRightChild(), target, isSuccessful);
		subTreePtr->setRightChild(tmp);
	}

	return subTreePtr;
}   

template<class ItemType>
auto BinaryNodeTree<ItemType>::moveValuesUpTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr){
	
}

template<class ItemType>
auto BinaryNodeTree<ItemType>::copyTree(const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const{
	std::shared_ptr<BinaryNode<ItemType>> newPtr=nullptr;

	if(oldTreeRootPtr=nullptr){
		newPtr=new std::shared_ptr<BinaryNode<ItemType>>(oldTreeRootPtr->getNode(), nullptr, nullptr);

		newPtr->setLeftChild(copyTree(oldTreeRootPtr->getLeftChild()));
		newPtr->setRightChild(copyTree(oldTreeRootPtr->getRightChild()));
	}

	return newPtr;
}


template<class ItemType>
void BinaryNodeTree<ItemType>::destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr){
	if(subTreePtr!=nullptr){
		destroyTree(subTreePtr->getLeftChild());
		destroyTree(subTreePtr->getRightChild());
		subTreePtr.reset();
	}
}

template<class ItemType>
void BinaryNodeTree<ItemType>::inorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const{
	if(treePtr!=nullptr){
		inorder(visit, treePtr->getLeftChild());
		ItemType theItem = treePtr->getNode();
		visit(theItem);
		inorder(visit, treePtr->getRightChild());
	}
}

template<class ItemType>
bool BinaryNodeTree<ItemType>::add(const ItemType& newData){
	auto newPtr = std::make_shared<BinaryNode<ItemType>>(newData);
	rootPtr = balanceAdd(rootPtr, newPtr);
	return true;
}