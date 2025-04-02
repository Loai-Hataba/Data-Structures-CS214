#include <iostream>

#include "SortingSystem.h"
using namespace  std ;

int main () {
    cout << "Welcome to Sorting System app " <<endl <<endl ;

    SortingSystem<string> s (9) ;
    //s.measureSortTime(&SortingSystem<int> :: radixSort) ;
    s.measureSortTime(&SortingSystem<string> :: insertionSort) ;
    return 0;
}