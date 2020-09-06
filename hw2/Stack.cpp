//--------------------------------------------------------------------
//
//   Stack.cpp
// 
//  Class implementation of the abstract class interface.
//
//--------------------------------------------------------------------

#include <stdexcept>
#include <iostream>

#include "Stack.h"

template <typename DataType>
Stack<DataType>::Stack(){
  top = NULL;
}

template <typename DataType>
Stack<DataType>::Stack(const Stack& other){
  Node* ptr = other.top;

  while(ptr != NULL){
    push(ptr->dat);
    ptr = ptr->next;
  }
}

template <typename DataType>
void Stack<DataType>::push(const DataType& newDataItem) throw (logic_error){
  
  Node* current = new Node;

  current->dat = newDataItem;
  cnt++;
  current->next = top;

  current = top;
}

template<typename DataType>
DataType Stack<DataType>::pop() throw(logic_error){
    Node* current = new Node;

    if(top!=NULL){
        top->dat = NULL;
        top->next = NULL;
        cnt--;
    }
}

template<typename DataType>
void Stack<DataType>::clear(){
    Node* current = new Node;
    Node* tmp = new Node;

    while(current != NULL){
        tmp = current->next;
        delete[] current;
        current = tmp;
        cnt--;
    }

}

template<typename DataType>
bool Stack<DataType>::isEmpty() const{
    if(top->dat == NULL && cnt==0){
        return true;
    }

    return false;
}

template<typename DataType>
bool Stack<DataType>::isFull() const{
    if(cnt==MAX_STACK_SIZE){
        return true;
    }
    return false;
}

template<typename DataType>
void Stack<DataType>::showStructure() const{
    Node* current = new Node;
    current = top;
    for(int i = 0; i<cnt; i++){
        cout<<cnt<<" "<<current->dat<<endl;
        current = current->next;
    }
}

