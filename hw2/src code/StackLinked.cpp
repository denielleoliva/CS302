#include <iostream>

#include "StackLinked.h"


template <typename DataType>
StackLinked<DataType>::StackNode::StackNode(const DataType& nodeData, StackNode* nextPtr) :
  dataItem(nodeData), next(nextPtr){

}

template <typename DataType>
StackLinked<DataType>::StackLinked(int maxNumber){
    top = nullptr;

}

template <typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other){
    DataType *placeholder;

    top = nullptr;

    while(top != nullptr){
        placeholder = other.top;

        for(int i = 0; i<other.maxNumber-1; i++){
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

    while(top!=nullptr){
      placeholder = other.top;

      for(int i = 0; i<this.maxNumber; i++){
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
    cnt++;
    
}

template <typename DataType>
DataType StackLinked<DataType>:: pop() throw (logic_error){
    if(isEmpty()){
        throw logic_error("Stack is empty. Cannot pop to empty stack.");
    }

    DataType tmp = top->dataItem;
    top = top->next;

    cnt--;

    return tmp;
}

template <typename DataType>
void StackLinked<DataType>:: clear(){
    while(top!=nullptr){
        pop();
    }
}


template <typename DataType>
bool StackLinked<DataType>:: isEmpty() const{
    return top==nullptr;
}

template <typename DataType>
bool StackLinked<DataType>:: isFull() const{
    return cnt==max;
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