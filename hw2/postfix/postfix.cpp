#include <iostream>
#include <string>

#include "StackLinked.cpp"

using namespace std;



float applyOperand(const float operandOne, const float operandTwo, char operation){
    float total = 0;

    switch(operation){
        case '^': 
            for(int i = 0; i<operandTwo-1; i++){
                total = operandOne*operandOne;
            }

            return total;
        case '+': return operandTwo + operandOne;
        case '-': return operandTwo - operandOne;
        case '*': return operandOne * operandTwo;
        case '/': return operandTwo / operandOne;

        default: cout<<"Invalid operation."<<endl;
    }

}

float evaluate( string input){
    

    StackLinked<float> vals;
    StackLinked<char> trash;
    
    vals.clear();

    trash.clear();

    float total;

    for(int i = 0; i<input.length(); i++){

        if(input[i]!='+'&&
            input[i]!='-'&&
            input[i]!='/'&&
            input[i]!='*'&&
            input[i]!='^'&&
            input[i]!=' '){
            vals.push(input[i]-48);

        }else if(input[i]==' '){
            trash.push(input[i]);
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

    cout<<"Manual Test Cases: "<<endl;

    cout<<"Test case 1: "<<endl;
    cout<<"Postfix: 1 0 + "<<endl;
    cout<<"Infix: 1 + 0"<<endl;
    cout<<"Result: "<<evaluate("1 0 +")<<endl;

    cout<<endl<<endl;

    cout<<"Test case 2: "<<endl;
    cout<<"Postfix: 3 4 + 5 2 / * "<<endl;
    cout<<"Infix: (3 + 4)*(5 / 2)"<<endl;
    cout<<"Result: "<<evaluate("3 4 + 5 2 / *")<<endl;

    cout<<endl<<endl;

    cout<<"Test case 3: "<<endl;
    cout<<"Postfix: 2 2 ^"<<endl;
    cout<<"Infix: 2^2"<<endl;
    cout<<"Result: "<<evaluate("2 2 ^")<<endl;

    cout<<endl<<endl;

    cout<<"Test case 4: "<<endl;
    cout<<"Postfix: 1 3 - 4 5 + *"<<endl;
    cout<<"Infix: (1 - 3)*(4 + 5)"<<endl;
    cout<<"Result: "<<evaluate("1 3 - 4 5 + *")<<endl;

    cout<<endl<<endl;

    cout<<"Test case 5: "<<endl;
    cout<<"Postfix: 9 3 + 8 8 - /"<<endl;
    cout<<"Infix: (9 + 3)/(8 - 8)"<<endl;
    cout<<"Result: "<<evaluate("9 3 + 8 8 - /")<<endl;



    return 0;
}