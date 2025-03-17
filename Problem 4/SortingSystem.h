//
// Created by abdal on 15/03/2025.
//

#ifndef SORTINGSYSTEM_H
#define SORTINGSYSTEM_H

#include <iostream>
#include <xmmintrin.h>

using namespace std;

template <typename T>
class SortingSystem
{
private:
    T *data;  // Dynamic array for storing input data
    int size; // Size of the array
    void merge(int left, int mid, int right); // Merge sort helper
    int partition(int low, int high);         // Quick sort helper
    void displayIteratedData (const int & i  ) ;

public:
    SortingSystem(const int & n);  // Constructor
    ~SortingSystem();      // Destructor
    void insertionSort();
    void selectionSort();
    void bubbleSort();
    void shellSort();
    void mergeSort(int left, int right);
    void quickSort(int left, int right);
    void countSort();
    void countSort(const int & bit );// helper function for the radix sort
    void radixSort();
    void bucketSort();




    void displayData(); // Print the current state of the array

    // Optional: Measure sorting time for performance analysis
    // void measureSortTime(void (*sortFunction)());

    void showMenu(); // Display menu for user interaction
};

//! May be removed
template<typename T>
void SortingSystem<T>::displayIteratedData(const int &   i ) {
    cout << "Iteration " << i << " : [ "  ;
    for (size_t j = 0; j < size  ; j++) {
        if ( j != size - 1 ) {
            cout << data[ j ] << ", ";
        }
        else {
            cout << data[ j ];
        }
    }
    cout << " ]" << endl;
}

template<typename T>
SortingSystem<T>::SortingSystem(const int &  n) {
    size = n;
    data = new T[size];
    int arr[] = {20, 80 , 30, 10 , 100, 20, 5 } ;
    for (int i = 0; i < size; i++) {
        data[i] =  arr[i] ;
    }
}

template<typename T>
SortingSystem<T>::~SortingSystem() {
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    delete[] data;
    data = nullptr; // Avoid dangling pointer
}



template <typename T>
void SortingSystem<T>::insertionSort()
{

}



template <typename T>
void SortingSystem<T>::bubbleSort()
{
    bool isSorted = true ;
    for (size_t i = 0; i < size - 1 ; i++)
    {
        for (size_t j = 0; j < size - i - 1 ; j++)
        {
            if(data[j ] > data[j + 1 ] ){
                swap(data[j] , data[j+ 1 ]) ;
                if (isSorted)
                {
                    isSorted = false ;
                }

            }
        }
        if (isSorted){
            break ;
        }

        displayIteratedData(i + 1 ) ;
    }

}

// Merge sort algorithm :

template <typename T>
void SortingSystem<T>::merge(int left, int mid, int right)
{
    int n1 = mid - left + 1 ;
    int n2 = right - mid ;

    T *L = new T [n1] , *R = new T [n2] ;

    //Coping the elements to L :
    for (size_t i = 0; i < n1; i++)
    {
        L[i] = data[left +  i] ;
    }
    //Coping the elements to R :
    for (size_t i = 0  ; i < n2 ; i++)
    {
        R[i] = data[mid + i + 1 ] ;
    }


    // Initialize the 3 pointers :

    int i = 0 , j = 0 , k = left ;

    while (i < n1 && j <n2)
    {
        if(L[i] < R[j]){
            data[k] = L [i];
            i ++ ;
        }
        else {
            data[k] = R[j] ;
            j++;
        }
        k ++;
    }

    //Checking if there is remaining elements :
    while (i< n1)
    {
        data[k] = L[i] ;
        i++ ;
        k++ ;

    }
    while (j < n2 )
    {
        data [k] = R[j] ;
        j ++ ;
        k++ ;
    }

    // Free allocated memory
    delete[] L;
    delete[] R;

}


template <typename T>
void SortingSystem<T>::mergeSort(int left, int right)
{
    static int iteration = 0 ;
    if(left < right ) {

        int middle =  left + (right- left ) / 2 ;
        mergeSort(left , middle) ;
        mergeSort(middle + 1 , right ) ;
        merge (left ,middle ,right ) ;
        displayIteratedData( ++iteration ) ;
    }
}

template<typename T>
void SortingSystem<T>::countSort() {

    // First find the max number :
    int max = data[0];
    for (int i = 1; i < size ; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }
    ++max ;
    // then making an array to store the occurrences of each number
    int *countArray = new int[max ] ;
    // Initialize it to be of zeros
    for (int i = 0; i < max ; i++) {
        countArray[i] = 0 ;
    }
    // then count occurrences :
    for (int i = 0; i < size; i++) {
        countArray[ data[i] ]  += 1  ;
    }
    // then convert the count array to a cumulative one :
    for (int i = 1; i < max  ; i++) {
        countArray[i] += countArray[i-1] ;
    }
    // the sorted array :
    int *sorted = new int[size] ;
    for (int i = size - 1 ; i >=0 ; i--) {
        sorted[countArray[data[i]] - 1 ] = data[i];
        countArray[data[i]] -- ;
    }
    //finally copying the elements to the data var :
    for (int i = 0; i < size; i++) {
        data[i] = sorted[i];
    }
    delete[] sorted ;
    delete[] countArray;
    countArray = nullptr;
    sorted = nullptr ;

}

template<typename T>
void SortingSystem<T>::countSort(const int &bit) {
    const int digitsRange = 10 ;
    int count [digitsRange]  ={ 0 }; // the array that we will count number of occurrences in it
    int * output = new int [this->size ] ;//The sorted array
    // count number of occurrences :
    for (int i = 0; i < this->size ; i++) {

        // extract the digit :
        int digit = (data[i] /bit ) % 10;
         ++count[ digit ] ;
    }
    // convert the count array to cumulative one :
    for (int i = 1 ; i < digitsRange; i++) {
        count [i] += count [i -1 ] ;
    }
    //Sort the elements from the left :
    for (int i = this->size -  1  ; i >=0 ; i--) {
        int digit = (data[i] /bit ) % 10;
        output [count [ digit ] - 1 ] = data[i];
        --count [digit ] ;
    }
    // copy the elements to the data array :
    for (int i = 0; i < this->size ; i++) {
        data[i] = output [i];

    }
    delete[] output ;
    output = nullptr ;

}

template<typename T>
void SortingSystem<T>::radixSort() {
    // find the max ele :
    int max = data[0];
    for (int i = 1; i < this->size ; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }
    // Doing count sort from the LSB :
    for (int i = 1 ;  max / i > 0 ; i *= 10) {
        countSort(i) ;
    }
}

template<typename T>
void SortingSystem<T>::displayData() {
    for (size_t j = 0; j < size  ; j++) {
        if ( j != size - 1 ) {
            cout << data[ j ] << ", ";
        }
        else {
            cout << data[ j ];
        }
    }
    cout << " ]" << endl;
}

template<typename T>
void SortingSystem<T>::showMenu() {
    cout << "1. Insertion Sort" << endl
    << "2. Selection Sort" << endl
    << "3. Bubble Sort" << endl
    << "4. Shell Sort" << endl
    << "5. Merge Sort" << endl
    << "6. Quick Sort" << endl
    << "7. Count Sort (Only for integers)" << endl
    << "8. Radix Sort (Only for integers)" << endl
    << "9. Bucket Sort " << endl;

    int choice = 0 ;
     while (true) {
         cout << "Enter your choice : ";
         cin >> choice ;
         if(choice >= 1 && choice <= 9) {
             break ;
         }
     }

}


#endif //SORTINGSYSTEM_H
