#ifndef INSERTIONSORTER_H_
#define INSERTIONSORTER_H_

using namespace std;

class InsertionSort{

public:

    InsertionSort(const int maxSize);

    int readFile(const string &filename);
    bool writeToFile(const string &filename) const;

    
    void sort(int &comparisons, int &swaps);

    void show() const;


private:

    int *index;
    int size;
    int max;

    //largest value

};


#endif