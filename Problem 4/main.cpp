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
    cout << "                           Welcome please choose the desired Sort: \n";
    cout << "1) Insertion Sort\n";
    cout << "2) Selection Sort\n";
    cout << "3) Bubble Sort\n";
    cout << "4) Shell Sort\n";
    cout << "5) Merge Sort\n";
    cout << "6) Quick Sort\n";
    cout << "7) Count Sort (only for integers)\n";
    cout << "8) Radix Sort (only for integers)\n";
    cout << "9) Bucket Sort (only for integers)\n";
    cout << "10) exit\n";
    while (1){
        cout << "Choice: ";
        int ans = getValidNum<int>();
        if (ans == 10){
            cout << "Goodbye!";
            exit(0);
        }
        if (ans > 10 || ans < 1){
            cout << "Please choose a number between 1-10\n";
            continue;
        }
        return ans;
    }
}


int dataMenu(int sortType) {
    if (sortType < 7){ // any data type is ok
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
    else return 1; // int data type
    }
    

// input numbers
template <typename T>
void inputArrayNum(T* arr, int size) {
    cout << "Please enter " << size << " elements:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Element " << i + 1 << ": ";
        arr[i] = getValidNum<T>(); // Use getValidNum to validate input
    }
    cout << "Array input complete!" << endl;
}


//FIXME: add sorts menu
// add colors to menu

int main () {
    while (1){
        int menuAns = menu(); // select sort
        int dataType = dataMenu(menuAns); // 1)int 2)float 3)double 4)string 5)exit
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

        switch (dataType){   //initialize the proper object
            case 1:{
                int* arr = new int[size];
                //FIXME: add deallocation for array memory and apply for rest of datatype object initializations 
                // add a function for inputting strings
                inputArrayNum(arr, size);
                SortingSystem<int> sortObject(size, arr);
                cout << "Done int \n";
                break;
            }
            case 2:{
                float* arr = new float[size];
                SortingSystem<float> sortObject(size, arr);
                cout << "Done float \n";
                break;
            }
            case 3:{
                double* arr = new double[size];
                SortingSystem<double> sortObject(size, arr);
                cout << "Done Double  \n";
                break;
            }
            case 4:{
                string* arr = new string[size];
                SortingSystem<string> sortObject(size, arr);
                cout << "Done String \n";
                break;
            }
            case 5:{
                cout << "Goodbye!!\n";
                cout << "exiting... \n";
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