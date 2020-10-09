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

        cout<<"1000 SORT"<<endl<<endl;

        InsertionSort is(1000);
        is.readFile("testFile_1000.txt");

        auto start = std::chrono::high_resolution_clock::now();

        is.sort(comparisons, swaps);

        auto end = std::chrono::high_resolution_clock::now();
        chrono::duration<double> difference = end - start;

        //is.show();

        is.writeToFile("resultFile_1000.txt");

        cout<<"SECONDS: "<<difference.count()<<endl;
        cout<<"COMPARISONS: "<<comparisons<<endl;
        cout<<"SWAPS: "<<swaps<<endl;

        //10000 SORT

        cout<<endl<<endl;
        cout<<"10000 SORT"<<endl<<endl;

        InsertionSort isSecond(10000);
        isSecond.readFile("testFile_10000.txt");

        comparisons = 0;
        swaps = 0;

        start = std::chrono::high_resolution_clock::now();

        isSecond.sort(comparisons, swaps);

        end = std::chrono::high_resolution_clock::now();
        difference = end - start;

        //is.show();

        isSecond.writeToFile("resultFile_10000.txt");

        cout<<"SECONDS: "<<difference.count()<<endl;
        cout<<"COMPARISONS: "<<comparisons<<endl;
        cout<<"SWAPS: "<<swaps<<endl;

        //100000 SORT

        cout<<endl<<endl;
        cout<<"100000 SORT"<<endl<<endl;

        InsertionSort isThird(10000);
        isThird.readFile("testFile_100000.txt");

        comparisons = 0;
        swaps = 0;

        start = std::chrono::high_resolution_clock::now();

        isThird.sort(comparisons, swaps);

        end = std::chrono::high_resolution_clock::now();
        difference = end - start;

        //is.show();

        isThird.writeToFile("resultFile_10000.txt");

        cout<<"SECONDS: "<<difference.count()<<endl;
        cout<<"COMPARISONS: "<<comparisons<<endl;
        cout<<"SWAPS: "<<swaps<<endl;

    #else

    #endif

}