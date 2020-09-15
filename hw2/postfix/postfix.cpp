#include <iostream>
#include <string>

#include "StackLinked.cpp"

using namespace std;

float applyOperand(const float operandOne, const float operandTwo, char operation){

    switch(operation){
        case '+': return operandTwo + operandOne;
        case '-': return operandTwo - operandOne;
        case '*': return operandOne * operandTwo;
        case '/': return operandTwo / operandOne;

        default: cout<<"Invalid operation."<<endl;
    }

}

float evaluate(const string input){


    StackLinked<int> vals;
    
    vals.clear();

    float total;

    for(int i = 0; i<input.length(); i++){

        if(input[i]!='+'&&
            input[i]!='-'&&
            input[i]!='/'&&
            input[i]!='*'){
            vals.push(input[i]-48);

        }else if(input[i]==' '){
            break;
        }else{

            float first = vals.pop();
            float second = vals.pop();

            total = applyOperand(first, second, input[i]);

            vals.push(total);
        }

        vals.showStructure();
    }

    return total;
}




int main(){

    cout<<evaluate("1 0 +")<<endl;

    cout<<evaluate("10+42-*")<<endl;

    return 0;
}