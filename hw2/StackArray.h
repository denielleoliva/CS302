//--------------------------------------------------------------------
//
//  StackLinked.h
// 
//  Class declaration for the linked implementation of the Stack ADT
//
//--------------------------------------------------------------------

#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <stdexcept>
#include <iostream>

using namespace std;

#include "Stack.h"

template <typename DataType>
class StackArray : public Stack<DataType> {
  public:
    StackArray(int maxNumber = Stack<DataType>::MAX_STACK_SIZE);
    StackArray(const StackArray& other);
    StackArray& operator=(const StackArray& other);
    ~StackArray();

    void push(const DataType& newDataItem) throw (logic_error);
    DataType pop() throw (logic_error);

    void clear();

    bool isEmpty() const;
    bool isFull() const;

    void showStructure() const;

  private:
    int maxSize;
    int top;
    DataType* dataItems;
};

template <typename DataType>
StackArray<DataType>::StackArray(int maxNumber): maxSize(maxNumber), top(-1){
  dataItems = new DataType[maxSize];
}

template <typename DataType>
StackArray<DataType>::StackArray(const StackArray &other) : maxSize(other.maxSize), top(other.top){
  dataItems new DataType[maxSize];

  for(int i = 0; i<top; i++){
    dataItems[i] = other.dataItems[i];
  }

}

template <typename DataType>
StackArray<DataType>& StackArray<DataType>:: operator=(const StackArray& other){
  if(this!=other){
    maxSize = other.maxSize;

    delete dataItems;

    top = other.top;

    dataItems = new dataItems[maxSize];

    for(int i = 0; i<top; i++){
      dataItems[i]=other.dataItems[i];
    }
  }

  return this;
}

template <typename DataType>
StackArray<DataType>::~StackArray(){
  delete dataItems;
}

template <typename DataType>
void StackArray<DataType>:: push(const DataType& newDataItem) throw (logic_error){
  if(isFull){
    throw logic_error("Stack is full. Cannot push() to stack.");
  }

  dataItems[++top] = newDataItem;
}

template <typename DataType>
DataType StackArray<DataType>::pop() throw(logic_error){
  if(isEmpty()){
    throw logic_error("Stack is empty. Cannot pop() from stack.");
  }

  top--;
  return dataItems[top+1];
}

template <typename DataType>
void StackArray<DataType>::clear(){
  top = -1;
}

template <typename DataType>
bool StackArray<DataType>::isEmpty() const{
  return top == -1;
}

template <typename DataType>
bool StackArray<DataType>::isFull() const{
  return top == maxSize -1;
}



#endif		//#ifndef STACKARRAY_H
