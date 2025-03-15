#include <iostream>

#include "SortingSystem.h"
using namespace  std ;

//
// Created by abdal on 15/03/2025.
//
int main () {
    cout << "Welcome to Sorting System app " <<endl <<endl ;

    SortingSystem<int> s (7) ;
    s.mergeSort(0 , 6 ) ;
    return 0;
}