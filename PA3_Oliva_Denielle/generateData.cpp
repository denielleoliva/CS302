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

    min = 0;
    max= 1000000;

    
    ofstream outFile;

    outFile.open("data/testFile_1000.txt");

    cnt = 1000;

    cout<<"***Random Number Generator***"<<endl<<endl;

    /*cout<<"Min Value: ";
    cin>>min;

    cout<<"Max Value: ";
    cin>>max;

    cout<<"How many values? ";
    cin>>cnt;*/

    for(int i = 0; i<cnt; i++){
        outFile<<randomVal(min, max);
        outFile<<endl;
    }

    outFile.close();

    outFile.open("data/testFile_10000.txt");

    cnt = 10000;

    /*cout<<"Min Value: ";
    cin>>min;

    cout<<"Max Value: ";
    cin>>max;

    cout<<"How many values? ";
    cin>>cnt;*/

    for(int i = 0; i<cnt; i++){
        outFile<<randomVal(min, max);
        outFile<<endl;
    }

    outFile.close();


    outFile.open("data/testFile_100000.txt");

    cnt = 100000;

    /*cout<<"Min Value: ";
    cin>>min;

    cout<<"Max Value: ";
    cin>>max;

    cout<<"How many values? ";
    cin>>cnt;*/

    for(int i = 0; i<cnt; i++){
        outFile<<randomVal(min, max);
        outFile<<endl;
    }

    outFile.close();

    cout<<"TEXT FILES GENERATED"<<endl;

}