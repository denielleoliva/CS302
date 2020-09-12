//--------------------------------------------------------------------
//
//  StackArray.h
// 
//  Class declaration for the array implementation of the Stack ADT
//
//--------------------------------------------------------------------

#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <stdexcept>
#include <iostream>

using namespace std;

#include "Stack.h"

template <typename DataType>
class StackLinked : public Stack<DataType> {

  public:

    StackLinked(int maxNumber = Stack<DataType>::MAX_STACK_SIZE);
    StackLinked(const StackLinked& other);
    StackLinked& operator=(const StackLinked& other);
    ~StackLinked();

    void push(const DataType& newDataItem) throw (logic_error);
    DataType pop() throw (logic_error);

    void clear();

    bool isEmpty() const;
    bool isFull() const;

    void showStructure() const;

  private:

    class StackNode {
      public:
	      StackNode(const DataType& nodeData, StackNode* nextPtr);

	      DataType dataItem;
	      StackNode* next;
    };

    StackNode* top;
};

template <typename DataType>
StackLinked<DataType>::StackNode::StackNode(const DataType& nodeData, StackNode* nextPtr) :
  dataItem(nodeData), next(nextPtr){

}

template <typename DataType>
StackLinked<DataType>::StackLinked(int maxNumber){
    top = NULL;

    for(int i = 0; i<maxNumber; i++){
        push(NULL);
    }
}

template <typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other){
    DataType *placeholder;

    top = NULL;

    while(top != NULL){
        placeholder = other.top;

        for(int i = 0; i<other.maxSize-1; i++){
            placeholder = placeholder->next;
        }

        push(placeholder->dataItem);
    }
}

template <typename DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked& other){
  if(this != &other){

    clear();

    StackNode *placeholder;

    top = NULL;

    while(top!=NULL){
      placeholder = other.top;

      for(int i = 0; i<other.maxSize; i++){
        placeholder = placeholder->next;
      }

      push(placeholder->dataItem);

    }

  }

  return *this;
}

template <typename DataType>
StackLinked<DataType>::~StackLinked(){
    clear();
}

template <typename DataType>
void StackLinked<DataType>:: push(const DataType& newDataItem) throw(logic_error){
    top = new StackNode(newDataItem, top);
}

template <typename DataType>
DataType StackLinked<DataType>:: pop() throw (logic_error){
    if(isEmpty()){
        throw logic_error("Stack is empty. Cannot pop() from stack.");
    }

    DataType tmp = top->dataItem;
    top = top->next;

    return tmp;
}

template <typename DataType>
void StackLinked<DataType>:: clear(){
    while(top!=NULL){
        pop();
    }
}


template <typename DataType>
bool StackLinked<DataType>:: isEmpty() const{
    return top==NULL;
}

template <typename DataType>
bool StackLinked<DataType>:: isFull() const{
    return !(top==NULL);
}

template <typename DataType>
void StackLinked<DataType>::showStructure() const 

// Linked list implementation. Outputs the data elements in a stack.
// If the stack is empty, outputs "Empty stack". This operation is
// intended for testing and debugging purposes only.

{
    if( isEmpty() )
    {
	cout << "Empty stack" << endl;
    }
    else
    {
        cout << "Top\t";
	for (StackNode* temp = top; temp != 0; temp = temp->next) {
	    if( temp == top ) {
		cout << '[' << temp->dataItem << "]\t";
	    }
	    else {
		cout << temp->dataItem << "\t";
	    }
	}
        cout << "Bottom" << endl;
    }

}

#endif		//#ifndef STACKARRAY_H