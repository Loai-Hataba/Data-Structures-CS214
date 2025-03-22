#include <iostream>

#include "SortingSystem.h"
using namespace  std ;

//
// Created by abdal on 15/03/2025.
//
int main () {
    cout << "Welcome to Sorting System app " <<endl <<endl ;

    SortingSystem<string> s (9) ;
    s.bubbleSort() ;
    return 0;
}