#ifndef METHODS_H
#define METHODS_H

#include <iostream>
#include <limits>

using namespace std;

template <typename T>
T getValidNum () {
    T num;
    while (1){
        cin >> num;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid number!\n";
        }
        else return num;
    }
}


string getValidString(){
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string input;
    getline(cin, input);
    return input;
}
#endif