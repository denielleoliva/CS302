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
	      StackNode(const DataType& nodeData, StackNode* nextPtr){
          dataItem = nodeData;
          next = nextPtr;
        }

	      DataType dataItem;
	      StackNode* next;
    };

    StackNode* top;
};


template <typename DataType>
StackLinked<DataType>::StackLinked(int maxNumber = Stack<DataType>::MAX_STACK_SIZE){
    top = NULL;

    for(int i = 0; i<MAX_STACK_SIZE; i++){
        push(NULL);
    }
}

template <typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other){
    DataType *placeholder;

    top = NULL;

    while(top!=NULL){
        placeholder = other.top;

        for(int i = 0; i<MAX_STACK_SIZE-1; i++){
            placeholder = placeholder->next;
        }

        push(placeholder->dataItem);
    }
}

template <typename DataType>
StackLinked& StackLinked<DataType>::operator=(const StackLinked& other){
  if(this != &other){

    clear();

    StackNode *placeholder;

    top = NULL;

    while(top!=NULL){
      placeholder = other.top;

      for(int i = 0; i<MAX_STACK_SIZE; i++){
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
    if(isEmpty()){
        top = newDataItem.next;
    }else{
        top = new StackNode(newDataItem);
    }
}

template <typename DataType>
DataType StackLinked<DataType>:: pop() throw (logic_error){
    if(isEmpty()){
        StackNode temp = top;
        top = top->next;
        delete temp;
    }
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

#endif		//#ifndef STACKARRAY_H