//
// Created by abdal on 15/03/2025.
//

#ifndef SORTINGSYSTEM_H
#define SORTINGSYSTEM_H

#include <chrono>
#include <iostream>

using namespace std;

template <typename T>
class SortingSystem
{
    T *data;  // Dynamic array for storing input data
    int size; // Size of the array

public:
    SortingSystem(const int & n);  // Constructor
    ~SortingSystem();      // Destructor
    void insertionSort();
    void selectionSort();
    void bubbleSort();
    void shellSort();
    void mergeSort(const int & left,const  int &  right);
    void quickSort(const int &  left,const int& right);
    void countSort();
    void countSort(const int & bit );// helper function for the radix sort
    void radixSort();
    void bucketSort();
    
    void merge(const int &  left, const int&  mid,const  int&  right); // Merge sort helper
    int partition(const int &  low, const int & high);         // Quick sort helper



    void displayData(); // Print the current state of the array

    void measureSortTime(void (SortingSystem :: *sortFunc)());

    void showMenu(); // Display menu for user interaction
};


template<typename T>
SortingSystem<T>::SortingSystem(const int &  n) {
    size = n;
    data = new T[size];
    //string arr[] ={"Nablus" , "Gaza" , "Al-Khalil" , "Ramallah" , "Ariha", "Jenin","Tolkarem", "Al-Quds","Yafa"  ,} ;
    int arr [ ] = {10 , 2 , 8 , 4 ,1 ,20 , 13 , 100 , 50 } ;
    for (int i = 0; i < size; i++) {
        data[i] =  arr[i] ;
    }

}

template<typename T>
SortingSystem<T>::~SortingSystem() {
    delete[] data;
    data = nullptr;
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
            cout << "The data is already sorted " << endl;
            cout << "Pass " << i + 1 << " : ";
            displayData() ;
            break ;
        }
        cout << "Pass " << i + 1 << " : ";
        displayData() ;
    }

}

// Merge sort algorithm :

template <typename T>
void SortingSystem<T>::merge(const int &  left, const int&  mid,const  int&  right)
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
void SortingSystem<T>::mergeSort(const int &  left,const int&  right)
{
    static int iteration = 0 ;
    if(left < right ) {
        int middle = left + (right - left) / 2;
        mergeSort(left , middle) ;
        mergeSort(middle + 1 , right ) ;
        merge (left ,middle ,right ) ;
        cout <<"Iteration "<< ++iteration << " : " ;
        displayData() ;
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
    auto *countArray = new int[max ] ;
    // Initialize it to be of zeros
    for (int i = 0; i < max ; i++) {
        countArray[i] = 0 ;
    }
    // then count occurrences :
    for (int i = 0; i < size; i++) {
        countArray[ data[i] ]  += 1   ;
    }
    // cout << "The Count array : " <<endl  ;
    // for (int i = 0; i < max ; i++) {
    //   cout << countArray[i] << " " ;
    // }
    cout << endl;
    // then convert the count array to a cumulative one :
    for (int i = 1; i < max  ; i++) {
        countArray[i] += countArray[i-1] ;
    }
    // cout << "The cumulative array :  " << endl ;
    // for (int i = 0; i < max ; i++) {
    //     cout << countArray[i] << " " ;
    // }

    cout << endl;
    // the sorted array :
    auto sorted = new int[size] ;
    for (int i = size - 1 ; i >=0 ; i--) {
        sorted[countArray[data[i]] - 1 ] = data[i];
        --countArray[data[i]]  ;
    }
    //finally copying the elements to the data var :
    for (int i = 0; i < size; i++) {
        data[i] = sorted[i];
    }
    cout << "The sorted array : ";
    this->displayData();
    delete[] sorted ;
    delete[] countArray;

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
    for (int i = this->size -  1  ; i >=0 ; --i) {
        int digit = (data[i] /bit ) % 10;
        output [count [ digit ] - 1 ] = data[i];
        --count [digit ] ;
    }
    // copy the elements to the data array :
    for (int i = 0; i < this->size ; i++) {
        data[i] = output [i];

    }
    delete[] output ;

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
    cout << " [ " ;
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
void SortingSystem<T>::measureSortTime(void(SortingSystem::*sortFunc)()) {
    const clock_t start = clock() ; //Wall time in windows
    (this->*sortFunc)();
    const clock_t end = clock() ;
    const double elapsed = static_cast<double>(end - start)/ CLOCKS_PER_SEC ;
    cout << "Sorting Time : "<< elapsed << " seconds" << endl;

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
