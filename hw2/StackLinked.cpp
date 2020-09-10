#include <stdexcept>
#include <iostream>

#include "Stack.h"
#include "StackLinked.h"

using namespace std;

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