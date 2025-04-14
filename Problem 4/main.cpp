#include <iostream>
#include <cstdlib>
#include <thread>
#include "SortingSystem.h"
#include "Methods.h"
using namespace  std ;

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"
#define BOLD "\033[1m"

int menu(){
    //system("cls"); //clearing screen...
    cout << GREEN << "           /////////////////////////////////////////////////////////////////////////////////\n";
    cout <<  "           //" << RESET <<"    _____            __  _              _       ___                      __  " << GREEN << "//\n";
    cout <<  "           //" << RESET <<"   / ___/____  _____/ /_(_)___  ____ _ | |     / (_)___  ____ __________/ /  " << GREEN << "//\n";
    cout <<  "           //" << RESET <<R"(   \__ \/ __ \/ ___/ __/ / __ \/ __ `/ | | /| / / /_  / / __ `/ ___/ __  /   )" << GREEN << "//\n";
    cout <<  "           //" << RESET <<"  ___/ / /_/ / /  / /_/ / / / / /_/ /  | |/ |/ / / / /_/ /_/ / /  / /_/ /    " << GREEN << "//\n";
    cout <<  "           //" << RESET <<R"(  ____/\____/_/   \__/_/_/ /_/\__, /   |__/|__/_/ /___/\__,_/_/   \__,_/     )" << GREEN << "//\n";
    cout <<  "           //" << RESET <<"                             /____/                                          " << GREEN << "//\n";
    cout <<  "           // ////////////////////////////////////////////////////////////////////////////" << GREEN << "//\n" << RESET;
    cout << endl << endl << endl;
    cout << "                           "<< BOLD << "Welcome" << RESET <<" please choose the desired Sort: \n";
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
    while (true){
        cout << "Choice: ";
        int ans = getValidNum<int>();
        if (ans > 10 || ans < 1){
            cout << "Please choose a number between 1-10\n";
            continue;
        }
        return ans;
    }
}


int dataMenu(int sortType) {
    if (sortType < 7){ // any data type is ok
        cout << "                           Please choose the desired data type: \n";
        cout << "1) int\n";
        cout << "2) float\n";
        cout << "3) double\n";
        cout << "4) string\n";
        cout << "5) exit\n";
        while (true){
            cout << "Choice: ";
            int ans = getValidNum<int>();
            if (ans == 5) {
                cout << "GoodBye!";
                exit(0);
            }
            if (ans > 5 || ans < 1){
                cout << "Please choose a number between 1-5\n";
                continue;
            }
            cout << ans << endl;
            return ans;
        }
    }
    return 1; // int data type
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

void inputArrayString(string* arr, int size){
    cout << "Please enter " << size << " elements:" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < size; i++) {
        getline(cin, arr[i]);
    }
    cout << "Array input complete! string " << endl;
    for (int k = 0 ; k < size;k++){
        cout << arr[k] << " ,";
    }
}

template <typename T>
void callSort(SortingSystem<T> sortObject, int sortType){
    switch(sortType){
        case 1:
            sortObject.measureSortTime(&SortingSystem<T> :: insertionSort);
            break;
        case 2:
            sortObject.measureSortTime(&SortingSystem<T> :: selectionSort);
            break;
        case 3:
            sortObject.measureSortTime(&SortingSystem<T> :: bubbleSort);
            break;
        case 4:
            sortObject.measureSortTime(&SortingSystem<T> :: shellSort);
            break;
        case 5:
            sortObject.measureSortTime(&SortingSystem<T> :: mergeSort);
            break;
        case 6:
            sortObject.measureSortTime(&SortingSystem<T> :: quickSort);
            break;
            case 7:
            case 8:
            case 9:
                if constexpr (std::is_integral<T>::value) {
                    if (sortType == 7) sortObject.measureSortTime(&SortingSystem<T>::countSort);
                    else if (sortType == 8) sortObject.measureSortTime(&SortingSystem<T>::radixSort);
                    else if (sortType == 9) sortObject.measureSortTime(&SortingSystem<T>::bucketSort);
                }
                break;
        default: cout << "Invalid sorting type!" << endl;
        
    }
}

//FIXME:
// add colors to menu

int main () {
    while (true){
        int menuAns = menu(); // select sort
        int dataType = dataMenu(menuAns); // 1)int 2)float 3)double 4)string 5)exit
        int size;
        while (true){
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
                auto* arr = new int[size];
                inputArrayNum(arr, size);
                SortingSystem sortObject(size, arr);
                callSort(sortObject, menuAns);
                delete[] arr;
                break;
            }
            case 2:{
                auto* arr = new float[size];
                inputArrayNum(arr, size);                
                SortingSystem sortObject(size, arr);
                callSort(sortObject, menuAns);
                delete[] arr;
                break;
            }
            case 3:{
                auto* arr = new double[size];
                inputArrayNum(arr, size);
                SortingSystem sortObject(size, arr);
                callSort(sortObject, menuAns);
                delete[] arr;
                break;
            }
            case 4:{
                auto* arr = new string[size];
                inputArrayString(arr, size);
                SortingSystem sortObject(size, arr);
                callSort(sortObject, menuAns);
                delete[] arr;
                break;
            }
            case 5:{
                cout << "Goodbye!!\n";
                cout << "exiting... \n";
                exit(0);
            }
            default:
                cout << "Invalid choice !\n";
        }

    }
}