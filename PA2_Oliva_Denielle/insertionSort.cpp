#include <iostream>
#include <string>
#include <fstream>

#include "insertionSort.h"


using namespace std;

InsertionSort::InsertionSort(const int maxSize):size(maxSize),
    max(maxSize){
        index = new int[maxSize];
}

int InsertionSort::readFile(const string &filename){
    std::ifstream file;
    string line;
    int cnt = 0;

    file.open(filename);

    while(file && cnt<size){
        file>>index[cnt];
        cnt++;
    }

    return cnt;
}

bool InsertionSort::writeToFile(const string &filename) const{
    ofstream resultFile;

    resultFile.open(filename);

    for(int i = 0; i<size;i++){
        resultFile<<index[i];
        resultFile<<endl;
    }

    return false;
}

void InsertionSort::sort(int &comparisons, int &swaps){
    int base, cnt;

    for(int i = 1; i<size; i++){
        base = index[i];
        cnt = i - 1;

        while(cnt>=0 && index[cnt]>base){
            comparisons++;
            swap(index[cnt+1],index[cnt]);
            swaps++;
        }

        index[cnt+1] = base;
    }

}

void InsertionSort::show() const{
    for(int i = 0; i<size; i++){
        cout<<index[i]<<" ";
    }
    cout<<endl;
}