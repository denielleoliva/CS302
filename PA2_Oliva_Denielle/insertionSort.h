#ifndef INSERTIONSORTER_H_
#define INSERTIONSORTER_H_

using namespace std;

class InsertionSort{

public:

    InsertionSort(const int maxSize);

    int readFile(const string &filename);
    bool writeToFile(const string &filename) const;

    int * getArr();
    int getSize();
    void sort(int *arr, int maxSize);

    void show() const;


private:

    int *index;
    int size;
    int max;

    //largest value

};


#endif