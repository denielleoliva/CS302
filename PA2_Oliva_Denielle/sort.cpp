#include <iostream>
#include <chrono>

#include "config.h"

#if SORT_TEST
#  include "insertionSort.h"
#else
#  include "mergeSort.h"
#endif

int main(){
    #if SORT_TEST
        int comparisons = 0;
        int swaps = 0;

        InsertionSort is(10);
        cout<<is.readFile("testFile_1000.txt");

        auto start = std::chrono::high_resolution_clock::now();

        is.sort(comparisons, swaps);

        auto end = std::chrono::high_resolution_clock::now();

        is.show();

        is.writeToFile("resultFile_1000.txt");

    #else

    #endif

}