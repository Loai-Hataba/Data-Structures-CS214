#include <iostream>

#include "SortingSystem.h"
using namespace  std ;

int main () {
    cout << "Welcome to Sorting System app " <<endl <<endl ;

    SortingSystem<int> s (15) ;
    s.measureSortTime(&SortingSystem<int> :: radixSort) ;
    return 0;
}