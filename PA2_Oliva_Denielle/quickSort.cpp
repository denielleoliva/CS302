#include <iostream>
#include <string>
#include <fstream>

#include "quickSort.h"

using namespace std;

QuickSort::QuickSort(const int maxSize): max(maxSize){
    array = new int[maxSize];
}

void QuickSort::readFile(const string &filename){
    ifstream file;
    int cnt = 0;

    file.open(filename);

    while(file &&cnt<max){
        file>>array[cnt];
        cnt++;
    }

}

void QuickSort::writeFile(const string &filename)const{
    ofstream resultFile;

    resultFile.open(filename);

    for(int i = 0; i<max; i++){
        resultFile<<array[i];
        resultFile<<endl;
    }
}

int* QuickSort::getArr(){
    return array;
}

int QuickSort::getStart(){
    return start;
}

int QuickSort::getEnd(){
    return max-1;
}

int QuickSort::split(int arr[], int start, int end, 
    int &comparisons, int &swaps){
    int pivot = arr[end];

    int pivot_ind = start;


    for(int i  = start; i<end; i++){
        if(arr[i] <= pivot){
            comparisons++;
            swap(arr[i],arr[pivot_ind]);
            swaps++;
            pivot_ind++;
        }
    }

    swap(arr[end],arr[pivot_ind]);
    swaps++;


    return pivot_ind;
}

void QuickSort::sort(int arr[], int start, int end, 
        int &comparisons, int &swaps){
    int pivot_ind;

    if(start<end){
        pivot_ind = split(arr, start, end, comparisons, swaps);
        sort(arr, start, pivot_ind-1, comparisons, swaps);
        sort(arr,pivot_ind+1, end, comparisons, swaps);
    }
}



