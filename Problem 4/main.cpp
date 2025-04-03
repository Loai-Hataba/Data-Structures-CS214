#include <iostream>
#include <cstdlib>
#include "SortingSystem.h"
#include "Methods.h"
using namespace  std ;

int menu(){
    system("cls"); //clearing screen...

    cout << "           // //////////////////////////////////////////////////////////////////////////////\n";
    cout << "           //    _____            __  _              _       ___                      __  //\n";
    cout << "           //   / ___/____  _____/ /_(_)___  ____ _ | |     / (_)___  ____ __________/ /  //\n";
    cout << "           //   \\__ \\/ __ \\/ ___/ __/ / __ \\/ __ `/ | | /| / / /_  / / __ `/ ___/ __  /   //\n";
    cout << "           //  ___/ / /_/ / /  / /_/ / / / / /_/ /  | |/ |/ / / / /_/ /_/ / /  / /_/ /    //\n";
    cout << "           //  ____/\\____/_/   \\__/_/_/ /_/\\__, /   |__/|__/_/ /___/\\__,_/_/   \\__,_/     //\n";
    cout << "           //                             /____/                                          //\n";
    cout << "           // //////////////////////////////////////////////////////////////////////////////\n";
    cout << endl << endl << endl;
    cout << "                           Welcome please choose the desired data type: \n";
    cout << "1) int\n";
    cout << "2) float\n";
    cout << "3) double\n";
    cout << "4) string\n";
    cout << "5) exit\n";
    while (1){
        cout << "Choice: ";
        int ans = getValidNum<int>();
        if (ans > 5 || ans < 1){
            cout << "Please choose a number between 1-5\n";
            continue;
        }
        cout << ans << endl;
        return ans;
    }
}


//FIXME: add sorts menu
// bucket, count, radix sorts are int only
// add colors to menu
//
int main () {
    while (1){
        int menuAns = menu();
        int size;
        while (1){
            cout << "\nPlease enter number of elements in array: ";
            size = getValidNum<int>();
            if (size < 1){
                cout << "Please choose a positive number\n";
                continue;
            }
            break;
        }
        switch (menuAns){   //initialize the proper object
            case 1:{
                SortingSystem<int> sortObject(size);
                break;
            }
            case 2:{
                SortingSystem<float> sortObject(size);
                break;
            }
            case 3:{
                SortingSystem<double> sortObject(size);
                break;
            }
            case 4:{
                SortingSystem<string> sortObject(size);
                break;
            }
            case 5:{
                cout << "Goodbye!!\n";
                exit(0);
            }
            default:
                cout << "Something unexpected happened!\n";
        }




        SortingSystem<int> s (15) ;
        //s.measureSortTime(&SortingSystem<int> :: radixSort) ;
        s.measureSortTime(&SortingSystem<int> :: shellSort) ;
        cout << "Enter num: ";
        int test = getValidNum<int>();
        cout << endl << test <<endl;
        cout << "Enter string: ";
        string testt = getValidString();
        cout << testt << endl;
        cout << "Enter double: ";
        double testd = getValidNum<double>();
        cout << fixed << setprecision(15);
        cout << "Double: " << testd << endl;
        cout << "Enter float: ";
        float testf = getValidNum<float>();
        cout << fixed << setprecision(7);
        cout << "Float: " << testf << endl;
        return 0;
    }
}