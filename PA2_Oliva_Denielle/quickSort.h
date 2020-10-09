#ifndef QUICKSORT_H_
#define QUICKSORT_H_

#include <string>
using namespace std;

class QuickSort{

public:
    QuickSort(const int maxSize);

    void readFile(const string &filename);
    void writeFile(const string &filename) const;
    int * getArr();
    int getStart();
    int getEnd();
    
    int split(int arr[], int start, int end, 
        int &comparisons, int &swaps);

    void sort(int arr[], int start, int end, 
        int &comparisons, int &swaps);


private:

    int *array;
    int start;
    int max;

};


#endif