//Generate random int values when compiled

#include <iostream>
#include <fstream>

using namespace std;

int randomVal(int min, int max){
    int diff = max-min;

    //ensures that value is within limits
    return rand()%diff + min;

}


int main(){

    int min, max, cnt;
    
    ofstream outFile;

    outFile.open("testFile.txt");

    cout<<"***Random Number Generator***"<<endl<<endl;

    cout<<"Min Value: ";
    cin>>min;

    cout<<"Max Value: ";
    cin>>max;

    cout<<"How many values? ";
    cin>>cnt;


    for(int i = 0; i<cnt; i++){
        outFile<<randomVal(min, max);
        outFile<<endl;
    }

    outFile.close();

}