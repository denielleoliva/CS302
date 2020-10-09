#include <iostream>
#include <chrono>

#include "insertionSort.h"
#include "quickSort.h"

using namespace std;

int main(){
    
    int comparisons = 0;
    int swaps = 0;

    cout<<"**********1000 SORT**********"<<endl<<endl;

    cout<<"INSERTION SORT"<<endl<<endl;
    InsertionSort is(1000);
    is.readFile("data/testFile_1000.txt");

    auto start = std::chrono::high_resolution_clock::now();

    is.sort(comparisons, swaps);

    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> difference = end - start;

    is.writeToFile("data/[INSERTION]resultFile_1000.txt");

    cout<<"SECONDS: "<<difference.count()<<endl;
    cout<<"COMPARISONS: "<<comparisons<<endl;
    cout<<"SWAPS: "<<swaps<<endl;

    //--------------------------------------------------------

    cout<<endl<<"QUICK SORT"<<endl<<endl;

    comparisons = 0;
    swaps = 0;

    QuickSort qsFirst(1000);
    qsFirst.readFile("data/testFile_1000.txt");

    start = std::chrono::high_resolution_clock::now();

    qsFirst.sort(qsFirst.getArr(), 0,
        qsFirst.getEnd(), comparisons, swaps);

    end = std::chrono::high_resolution_clock::now();
    difference = end - start;

    qsFirst.writeFile("data/[QUICK]resultFile_1000.txt");

    cout<<"SECONDS: "<<difference.count()<<endl;
    cout<<"COMPARISONS: "<<comparisons<<endl;
    cout<<"SWAPS: "<<swaps<<endl;

    //10000 SORT-----------------------------------------------

    cout<<endl<<endl;
    cout<<"**********10000 SORT**********"<<endl<<endl;

    cout<<"INSERTION SORT"<<endl<<endl;

    InsertionSort isSecond(10000);
    isSecond.readFile("data/testFile_10000.txt");

    comparisons = 0;
    swaps = 0;

    start = std::chrono::high_resolution_clock::now();

    isSecond.sort(comparisons, swaps);

    end = std::chrono::high_resolution_clock::now();
    difference = end - start;

    isSecond.writeToFile("data/[INSERTION]resultFile_10000.txt");

    cout<<"SECONDS: "<<difference.count()<<endl;
    cout<<"COMPARISONS: "<<comparisons<<endl;
    cout<<"SWAPS: "<<swaps<<endl;

    //--------------------------------------------------------

    cout<<endl<<"QUICK SORT"<<endl<<endl;

    comparisons = 0;
    swaps = 0;

    QuickSort qsSecond(10000);
    qsSecond.readFile("data/testFile_10000.txt");

    start = std::chrono::high_resolution_clock::now();

    qsSecond.sort(qsSecond.getArr(), 0,
        qsSecond.getEnd(), comparisons, swaps);

    end = std::chrono::high_resolution_clock::now();
    difference = end - start;

    qsSecond.writeFile("data/[QUICK]resultFile_10000.txt");

    cout<<"SECONDS: "<<difference.count()<<endl;
    cout<<"COMPARISONS: "<<comparisons<<endl;
    cout<<"SWAPS: "<<swaps<<endl;

    //100000 SORT-------------------------------------------

    cout<<endl<<endl;
    cout<<"**********100000 SORT**********"<<endl<<endl;

    cout<<"INSERTION SORT"<<endl<<endl;
    InsertionSort isThird(10000);
    isThird.readFile("data/testFile_10000.txt");

    comparisons = 0;
    swaps = 0;

    start = std::chrono::high_resolution_clock::now();

    isThird.sort(comparisons, swaps);

    end = std::chrono::high_resolution_clock::now();
    difference = end - start;


    isThird.writeToFile("data/[INSERTION]resultFile_10000.txt");

    cout<<"SECONDS: "<<difference.count()<<endl;
    cout<<"COMPARISONS: "<<comparisons<<endl;
    cout<<"SWAPS: "<<swaps<<endl;

    //--------------------------------------------------------

    cout<<endl<<"QUICK SORT"<<endl<<endl;

    comparisons = 0;
    swaps = 0;

    QuickSort qsThird(100000);
    qsThird.readFile("data/testFile_100000.txt");

    start = std::chrono::high_resolution_clock::now();

    qsThird.sort(qsThird.getArr(), 0,
        qsThird.getEnd(), comparisons, swaps);

    end = std::chrono::high_resolution_clock::now();
    difference = end - start;

    qsThird.writeFile("data/[QUICK]resultFile_100000.txt");

    cout<<"SECONDS: "<<difference.count()<<endl;
    cout<<"COMPARISONS: "<<comparisons<<endl;
    cout<<"SWAPS: "<<swaps<<endl;

    

}