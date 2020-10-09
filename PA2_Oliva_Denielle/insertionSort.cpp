#include <iostream>
#include <string>
#include <fstream>

#include "insertionSort.h"


using namespace std;

InsertionSort::InsertionSort(const int maxSize): max(maxSize){
        index = new int[maxSize];
}

int InsertionSort::readFile(const string &filename){
    std::ifstream file;
    int cnt = 0;

    file.open(filename);

    while(file && cnt<max){
        file>>index[cnt];
        cnt++;
    }

    return cnt;
}

bool InsertionSort::writeToFile(const string &filename) const{
    ofstream resultFile;

    resultFile.open(filename);

    for(int i = 0; i<max;i++){
        resultFile<<index[i];
        resultFile<<endl;
    }

    return false;
}

void InsertionSort::sort(int &comparisons, int &swaps){
    int base, cnt;

    for(int i = 1; i<max; i++){
        base = index[i];
        cnt = i;

        comparisons++;

        while(cnt>0 && index[cnt-1]>base){
            comparisons++;
            swap(index[cnt-1],index[cnt]);
            cnt--;
            swaps++;
        }

        index[cnt] = base;
    }

}

void InsertionSort::show() const{
    for(int i = 0; i<max; i++){
        cout<<index[i]<<" ";
    }
    cout<<endl;
}