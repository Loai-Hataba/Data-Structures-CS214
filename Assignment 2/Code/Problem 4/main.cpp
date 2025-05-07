#include <iostream>
using namespace std ;

struct Patient {
    string name ;
    int severity  ;
    int arrival_time;
    // Empty constructor  :
    Patient() {
        this->name = "" ;
        this->severity =this->arrival_time=0  ;
    }
    // Parameterized constructor
    Patient(const string & name, const int & severity, const int& arrival_time) {
        this->name = name ;
        this->severity = severity ;
        this->arrival_time = arrival_time ;
    }
};

/// The Max heap Class
class MaxHeap {
    Patient * arr ;
    int size ;
    int capacity ;

    // The Max Heapify function
    void max_heapify( const int & i , const int&  n  ) {
        int left = 2* i  + 1 ;
        int right = left + 1;
        int largest = i ;
        // finding the max between the left & i element
        if (left < n ) {
            if (arr [left ].severity > arr[largest].severity)  largest = left ;
            else if (arr [left ].severity == arr[largest].severity) {
                if (arr [left ].arrival_time > arr[largest].arrival_time) {
                    largest = left ;
                }
            }
        }
        // finding the max between the right & the largest element
        if (right < n ) {
            if (arr [right ].severity > arr[largest].severity)  largest = right ;
            else if (arr [right ].severity == arr[largest].severity) {
                if (arr [right ].arrival_time > arr[largest].arrival_time) {
                    largest = right ;
                }
            }
        }
        // then check if the largest is the i element
        if (largest == i ) {
            // the heap is correct
            return ;
        }
        swap(arr[i] , arr[largest] ) ;
        max_heapify (largest , n );
    }

    // function to build the heap
    void build_max_heap ( const int& n ) {
        // iterate starting from the last level with full elements
        for (int  i = (n / 2 ) - 1 ; i >=0 ; i -- ) {
            // do max-heapify
            max_heapify(i , n);
        }
    }
    // function for applying heap sort algo on the heap
    void heap_sort (const int& n ) {
        //1- build the max heap
        build_max_heap(n ) ;
        cout << "In the heap sort algo : " << endl;
        for (int i = 0;  i < n ; i ++) {
            cout << arr[i].name << " " ;
        }
        cout << endl ;
        // Making a loop to sub the array size to keep the sorting in place
        for (int i = n -1 ; i > 0  ; i --) {
            // Step 3: Swap root (largest) with the last element
            swap(arr[0], arr[i]);
            // Step 4: Heapify the reduced heap (size i)
            max_heapify(0, i); // The
        }
        // swap the elements to be in a dec order
        for (int i= 0 ; i < n/2 ; i ++ ) {
            swap(arr[i] , arr[n-i-1] ) ;
        }
    }
    void resize (const int & newCapacity ) {
        auto  newArr = new Patient[newCapacity] ;
        for (int i = 0 ; i <this->capacity ; i ++) {
            newArr [i] = arr [i] ;
        }
        delete [] arr ;
        arr = newArr ;
        capacity = newCapacity ;
    }
public :
    MaxHeap() {
        // Assign the vars into default values
        this -> size = 0 ;
        this->capacity = 4 ;
        this->arr = new Patient[this->capacity] ;
    }
    void insert(const Patient & p) {
        if (size == this -> capacity) {
            resize (2 * this -> capacity) ;
        }
        // adding the patient into the array
        arr[size] = p ;
        size++ ;
        heap_sort (size ) ;
    }
    Patient extract_max() {
        if (size == 0) return {} ;
        //1- store the max value
        Patient max = arr[0] ;
        // 2- swap the last element with the max
        swap(arr[0] , arr[size-1] ) ;
        // 3- decrement the size
        size-- ;
        // 4- apply max_heapify
        max_heapify (0,size ) ;
        // 5- finally return the max
        return max ;

}
    Patient peek() const {
        if (size == 0) {
            return {} ;
        }
       return arr[0] ;
}
    // Function to print the heap as a list with the patients names
    void print_heap ()  const {
        cout << "Heap [" ;
    for (int i = 0 ; i < size ; i ++) {
        if (i != size - 1  ) {
            cout <<"'" <<arr[i].name << "'"  << ", ";
        }
        else {
            cout <<"'" <<arr[i].name << "'"  ;
        }
    }
    cout << "]"<< endl ;
}
    ~MaxHeap() {
        // Freeing up the allocated  memory
        delete [] arr ;
    }
};
int main () {
    MaxHeap maxHeap ;
    maxHeap.insert ( Patient ("Alice", 100, 10) ) ;
    cout << "In the main  : " ;
    maxHeap.print_heap() ;

    maxHeap.insert ( Patient ("Bob", 5 , 10) ) ;
    cout << "In the main  : " ;
    maxHeap.print_heap() ;
    maxHeap.insert ( Patient ("alex", 20  , 10) ) ;
    cout << "In the main  : " ;
    maxHeap.print_heap() ;
    maxHeap.insert ( Patient ("nek", 30  , 20) ) ;
    cout << "In the main  : " ;
    maxHeap.print_heap() ;
    maxHeap.insert ( Patient ("sam", 40  , 20) ) ;
    cout << "In the main  : " ;
    maxHeap.print_heap() ;
    maxHeap.insert ( Patient ("emma", 50  , 20) ) ;
    cout << "In the main  : " ;
    maxHeap.print_heap() ;


    return 0 ;
}