#include <iostream>

#include "SortingSystem.h"
using namespace  std ;

int main () {
    cout << "Welcome to Sorting System app " <<endl <<endl ;

    SortingSystem<int> s (15) ;
    //s.measureSortTime(&SortingSystem<int> :: radixSort) ;
//    s.measureSortTime(&SortingSystem<int> :: shellSort) ;
    s.measureSortTime(&SortingSystem<int> :: quickSort) ;
    return 0;
}