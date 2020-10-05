#include <iostream>
#include <chrono>

#include "config.h"

#if SORT_TEST
#  include "insertionSort.cpp"
#else
#  include "mergeSort.cpp"
#endif

int main(){
    #if SORT_TEST
        InsertionSort is(1000);
        is.readFile("testFile_1000.txt");

        auto start = std::chrono::high_resolution_clock::now();

        is.sort(is.getArr(), is.getSize());

    #else

    #endif

}