#include <iostream>

#if !LAB6_TEST1
#include "StackLinked.h"  //broken config file
#else
#include "StackArray.h"
#endif

//--------------------------------------------------------------------

bool delimitersOk ( const string &expression );

//--------------------------------------------------------------------

int main()
{
    string inputLine;            // Input line
    char   ch;                   // Holding pen for input chars

    /*cout << "This program checks for properly matched delimiters."
         << endl;

    while( cin )
    {
        cout << "Enter delimited expression (<EOF> to quit) : "
             << endl;

        // Read in one line
        inputLine = "";
        cin.get(ch);
        while( cin && ch != '\n' )
        {
            inputLine = inputLine + ch;
            cin.get(ch);
        }

        if( ! cin )              // Reached EOF: stop processing
            break;
    
        if ( delimitersOk (inputLine) )
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;
    }*/

    std::cout<<"Test case 1: {} -";
    if(delimitersOk("{}")){
        cout<<" VALID CASE"<<endl;
    }else{
        cout<<" INVALID CASE"<<endl;
    }

    return 0;
}

//--------------------------------------------------------------------
// delimitersOk: the function that students must implement for 
//    Programming Exercise 3.
// Note: we used the term "braces" to describe '[' and ']'. It would
//    have been better to use the term "brackets". The program can be
//    easily modified to process any set of matching delimiters.
//--------------------------------------------------------------------

// Insert your delimitersOk function below

bool delimitersOk(const string &expression){
    //opening delimeters: [, {, <, (
    //closing delimeters: ], }, >, )

    StackLinked<char> inputStack;
    char temp;

    for(int i = 0; expression.length(); i++){
        switch(expression[i]){
            case '(': inputStack.push(expression[i]);
                        break;
            case '[': inputStack.push(expression[i]);
                        break;
            case '{': inputStack.push(expression[i]);
                        cout<<"here"<<endl;
                        break;

            case ')': 
                if(inputStack.pop()!= '('){
                    return false;
                }
                break;
            case '}': 
                if(inputStack.pop()!= '{'){
                    return false;
                }
                break;
            case ']':
                if(inputStack.pop()!= '['){
                    return false;
                }
                break;
        }
    }

    return (inputStack.isEmpty());

}