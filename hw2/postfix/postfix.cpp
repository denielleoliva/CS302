#include <iostream>
#include <string>

#include "StackLinked.h"

float applyOperand(const float operandOne, const float operandTwo, char operation){

    switch(operation){
        case '+': return operandTwo + operandOne;
        case '-': return operandTwo - operandOne;
        case '*': return operandOne * operandTwo;
        case '/': return operandTwo / operandOne;

        default: cout<<"Invalid operation."<<endl;
    }

}

float evaluate(string input){

    StackLinked<int> vals;
    
    vals.clear();


    float total;

    for(int i = 0; i<input.length(); i++){
        if(input[i]!='+'||input[i]!='-'||input[i]!='/'||input[i]!='*'){
            vals.push(input[i]);
        }else{

            float first = vals.pop();
            float second = vals.pop();

            total = applyOperand(first, second, input[i]);

            vals.push(total);
        }
    }

    return total;
}




int main(){

    cout<<evaluate("10+")<<endl;

    return 0;
}