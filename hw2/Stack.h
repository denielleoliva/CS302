//--------------------------------------------------------------------
//
//   Stack.h
// 
//  Class declaration of the abstract class interface to be used as
//  the basis for implementations of the Stack ADT.
//
//--------------------------------------------------------------------

#ifndef STACK_H
#define STACK_H

#include <stdexcept>
#include <iostream>

using namespace std;

template <typename DataType>
class Stack {

  public:
    int cnt = 0;

    struct Node{
      DataType dat;
      Node *next;
    };

    Node* top = NULL;

    static const int MAX_STACK_SIZE = 8;

    //Pre: none
    //Post: constructor; creates empty stack (enough memory for maxNumber)
    virtual Stack();

    //Pre: none
    //Post: copy constructor; initializes stack to be equivalent to the other
    //      Stack object parameter
    virtual Stack(const Stack& other);

    virtual Stack& operator= (const Stack& other);

    virtual ~Stack();

    //Pre: the stack is not full
    //Post: inserts a new DataType object at the top of the stack
    virtual void push(const DataType& newDataItem) throw (logic_error) = 0;

    //Pre: the stack is not empty
    //Post: removes the most recently added item (item at the top of the stack)
    virtual DataType pop() throw (logic_error) = 0;

    //Pre: none
    //Post: removes all data in the stack
    virtual void clear() = 0;

    //Pre: none
    //Post: returns true if the stack is empty
    virtual bool isEmpty() const = 0;

    //Pre: none
    //Post: returns true if the stack is full
    virtual bool isFull() const = 0;

    //Pre: none
    //Post: outputs the data in the stack; if empty it outputs "empty stack"
    //      mainly for debugging; only supports predefined datatypes
    virtual void showStructure() const = 0;


  

};

template <typename DataType>
Stack<DataType>::~Stack() 
// Not worth having a separate class implementation file for the destuctor
{}

#endif		// #ifndef STACK_H
