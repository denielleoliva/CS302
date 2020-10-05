#include <iostream>
#include <string>
#include <fstream>

#include "insertionSort.h"


using namespace std;

InsertionSort::InsertionSort(const int maxSize):size(0),
    max(maxSize){
        index = new int[maxSize];
}

int InsertionSort::readFile(const string &filename){
    ifstream file;

    file.open(filename);

    int cnt = 0;
    while(file && cnt<size){
        file>>index[cnt];
        cnt++;
        size++;
    }

    return cnt;
}

bool InsertionSort::writeToFile(const string &filename) const{
    return false;
}

void InsertionSort::sort(int *arr, int maxSize){
    int compare;
    int temp;

    for(int i = 1; i<maxSize; i++){
        compare = arr[i];
        temp = i;

        while(temp>0 && arr[temp-1]>compare){
            arr[temp] = arr[temp-1];
            temp--;
        }

        arr[temp] = compare;
    }

}

int * InsertionSort::getArr(){
    return index;
}

int getSize(){
    return size;
}

void InsertionSort::show() const{
    for(int i = 0; i<size; i++){
        cout<<index[i]<<" ";
    }
    cout<<endl;
}