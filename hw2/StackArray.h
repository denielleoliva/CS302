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
  dataItems = new DataType[maxSize];

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

    dataItems = new DataType[maxSize];

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
  if(isFull()){
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

template <typename DataType>
void StackArray<DataType>::showStructure() const 

// Array implementation. Outputs the data items in a stack. If the
// stack is empty, outputs "Empty stack". This operation is intended
// for testing and debugging purposes only.

{
    if( isEmpty() ) {
	    cout << "Empty stack." << endl;
    }
    else {
	    int j;
	    cout << "Top = " << top << endl;
	  for ( j = 0 ; j < maxSize ; j++ )
	    cout << j << "\t";
	    cout << endl;
	  for ( j = 0 ; j <= top  ; j++ )
	  {
	    if( j == top )
	    {
	      cout << '[' << dataItems[j] << ']'<< "\t"; // Identify top
	    }
	    else
	    {
		    cout << dataItems[j] << "\t";
	    }
	}
	cout << endl;
    }
    cout << endl;
}

#endif		//#ifndef STACKARRAY_H
