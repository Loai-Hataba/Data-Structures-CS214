#ifndef SORTINGSYSTEM_H
#define SORTINGSYSTEM_H

#include <chrono>
#include <iomanip>
#include <iostream>

using namespace std;

template<typename T>
class SortingSystem {
    T *data;  // Dynamic array for storing input data
    int size; // Size of the array

public:
    SortingSystem(const int &n,  const T* array);  // Constructor
    ~SortingSystem();      // Destructor
    void insertionSort();   //insertion gamed
    void selectionSort();   //selection bardo gamed
    void bubbleSort();

    void shellSort();       //shell agmad menhom
    void mergeSort(const int &left, const int &right);

    void mergeSort();// for the measure function
    void quickSort(const int &left, const int &right);

    void quickSort();// for the measure function
    void countSort();

    void countSort(const int &bit);// helper function for the radix sort
    void radixSort();

    void bucketSort();

    void merge(const int &left, const int &mid, const int &right); // Merge sort helper
    int partition(const int &left, const int &right);         // Quick sort helper


    void displayData(); // Print the current state of the array

    void measureSortTime(void (SortingSystem::*sortFunc)());

    void showMenu(); // Display menu for user interaction
};


template<typename T>
SortingSystem<T>::SortingSystem(const int &n, const T* array) {
    size = n;
    data = new T[size];
    cout << "checking\n";
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;


}

template<typename T>
SortingSystem<T>::~SortingSystem() {
    delete[] data;
    data = nullptr;
}


template<typename T>
void SortingSystem<T>::insertionSort() {
    // main iteration
    for (int i = 1, j; i < this->size; i++) {
        T tempo = data[i];
        // reverse iteration (shift larger numbers to the right)
        for (j = i; j > 0 && tempo < data[j - 1]; j--) {
            data[j] = data[j - 1];
        }
        data[j] = tempo;
        cout << "after Iteration no.: " << i << "\n ";
        this->displayData();
    }
}

template<typename T>
void SortingSystem<T>::selectionSort() {
    int indexMin;
    cout << "wasa3 lel selection: \n";
    for (int i = 0; i < this->size; i++) {
        indexMin = i;   // keep track of who is the smallest element
        for (int j = i + 1; j < this->size; j++) {
            if (data[j] < data[indexMin]) indexMin = j;     // if found smaller element make it the new indexMin
        }
        if (indexMin != i)
            swap(data[i],
                 data[indexMin]); // only swaap if the smallest element isnt the current element (unecesary swap)
        cout << "after iteration: [";
        for (int k = 0; k < this->size; k++) {
            cout << data[k] << ", ";
        }
        cout << "]" << endl;

    }
}

template<typename T>
void SortingSystem<T>::bubbleSort() {
    bool isSorted = true;
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
                if (isSorted) {
                    isSorted = false;
                }
            }
        }
        if (isSorted) {
            cout << "The data is already sorted " << endl;
            cout << "Pass " << i + 1 << " : ";
            displayData();
            break;
        }
        cout << "Pass " << i + 1 << " : ";
        displayData();
    }
    cout << "\n\nThe Sorted Data : ";
    this->displayData();
}

template<typename T>
void SortingSystem<T>::shellSort() {
    for (int gap = this->size / 2; gap > 0; gap /= 2) {   // gap between compared elemeents
        for (int i = gap; i < this->size; i++) {
            T tempoo = data[i];
            int j = i;
            while (j >= gap && data[j - gap] > tempoo) {
                data[j] = data[j - gap];  //shifting larger numbers to the right
                j -= gap;    // keeping the loop if there can be another shifting
            }
            data[j] = tempoo;
        }
    }
    cout << "\nafter shellzz: ";
    for (int k = 0; k < this->size; k++) {
        cout << data[k] << " ";
    }
    cout << endl;
}


// Merge sort algorithm :

template<typename T>
void SortingSystem<T>::merge(const int &left, const int &mid, const int &right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    cout << "Left  = " << left << " , Right = " << right << endl;
    T *L = new T[n1], *R = new T[n2];

    cout << "The left array  : [";
    //Coping the elements to L :
    for (size_t i = 0; i < n1; i++) {
        L[i] = data[left + i];
        if (i != n1 - 1)cout << L[i] << ",";
        else cout << L[i];
    }
    cout << "] " << endl;
    cout << "The Right array  : [";
    //Coping the elements to R :
    for (size_t i = 0; i < n2; i++) {
        R[i] = data[mid + 1 + i];
        if (i != n2 - 1) cout << R[i] << ",";
        else cout << R[i];

    }
    cout << "] " << endl;


    // Initialize the 3 pointers :

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            data[k] = L[i];
            i++;
        } else {
            data[k] = R[j];
            j++;
        }
        k++;
    }

    //Checking if there is remaining elements :
    while (i < n1) {
        data[k] = L[i];
        i++;
        k++;

    }
    while (j < n2) {
        data[k] = R[j];
        j++;
        k++;
    }

    // Free allocated memory
    delete[] L;
    delete[] R;

}


template<typename T>
void SortingSystem<T>::mergeSort(const int &left, const int &right) {
    static int iteration = 0;
    if (left < right) { ;
        int middle = left + (right - left) / 2;
        mergeSort(left, middle);
        mergeSort(middle + 1, right);
        cout << "Iteration # " << iteration + 1 << " : " << endl;
        merge(left, middle, right);
        cout << "After merging  " << " : ";
        displayData();
        ++iteration;
        cout << endl;

    }
    // reset the counter
    if (iteration == size - 1) {
        iteration = 0;
    }

}

template<typename T>
void SortingSystem<T>::mergeSort() {

    mergeSort(0, size - 1);
    cout << "The Sorted Data  : ";
    this->displayData();
}

// Quick sort algorithm :

template<typename T>
void SortingSystem<T>::quickSort(const int &left, const int &right) {
    int pivot = left; //pivot is first element
    if (pivot < right) {
        int newPivot = partition(pivot, right); //pivot is now in right position
        cout << "Pivot: " << data[newPivot] << " --> [";
        for (int i = left; i < newPivot; ++i)
            cout << data[i] << (i < newPivot - 1 ? ", " : "");
        cout << "] " << data[newPivot] << " [";
        for (int i = newPivot + 1; i <= right; ++i)
            cout << data[i] << (i < right ? ", " : "");
        cout << "]\n";
        quickSort(left, newPivot - 1);
        quickSort(newPivot + 1, right);
    }
}


template<typename T>
int SortingSystem<T>::partition(const int &left, const int &right) {
    int i = left;
    int pivotVal = data[left];

    for (int j = left + 1; j <= right; ++j) {
        if (data[j] < pivotVal) {
            i++;
            swap(data[i], data[j]);
        }
    }
    swap(data[i], data[left]);
    return i;
}

template<typename T>
void SortingSystem<T>::quickSort() {
    quickSort(0, size - 1);
    cout << "\nThe Sorted Data  : ";
    this->displayData();
}

template<typename T>
void SortingSystem<T>::countSort() {

    // First find the max number :
    int max = data[0];
    int min = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] > max) {
            max = data[i];
        }
        if (data[i] < min) {
            min = data[i];
        }
    }
    // then making an array to store the occurrences of each number
    const int range = max - min + 1;
    int *countArray = new int[range]{0};
    // then count occurrences :
    for (int i = 0; i < size; i++) {
        ++countArray[data[i] - min];
    }
    // then convert the count array to a cumulative one :
    for (int i = 1; i < range; i++) {
        countArray[i] += countArray[i - 1];
    }
    // the sorted array :
    int *sorted = new int[size]{0};
    for (int i = size - 1; i >= 0; i--) {
        // the algorithm
        sorted[countArray[data[i] - min] - 1] = data[i];
        --countArray[data[i] - min];
        // For displaying the iterations
        // Printing the sorted array after every iteration
        cout << "Iteration # " << size - i << " : [ ";
        for (int i = 0; i < size; i++) {
            if (i != size - 1)
                cout << sorted[i] << ", ";
            else
                cout << sorted[i] << " ]" << endl;
        }
    }
    //finally copying the elements to the data var :
    for (int i = 0; i < size; i++) {
        data[i] = sorted[i];
    }
    delete[] sorted;
    delete[] countArray;

}

template<typename T>
void SortingSystem<T>::countSort(const int &bit) {
    const int digitsRange = 19; //from -9 to 9
    int count[digitsRange] = {0}; // the array that we will count number of occurrences in it
    int *output = new int[this->size];//The sorted array
    // count number of occurrences :
    for (int i = 0; i < this->size; i++) {

        // extract the digit :
        int digit = (data[i] / bit) % 10 + 9;
        ++count[digit];
    }
    // convert the count array to cumulative one :
    for (int i = 1; i < digitsRange; i++) {
        count[i] += count[i - 1];
    }
    //Sort the elements from the left :
    for (int i = this->size - 1; i >= 0; --i) {
        int digit = (data[i] / bit) % 10 + 9;
        output[count[digit] - 1] = data[i];
        --count[digit];
    }
    // copy the elements to the data array :

    for (int i = 0; i < this->size; i++) {
        data[i] = output[i];


    }
    delete[] output;

}

template<typename T>
void SortingSystem<T>::radixSort() {
    // find the max element :
    int max = data[0];
    for (int i = 1; i < this->size; i++) {
        if (abs(data[i]) > max) {
            max = data[i];
        }
    }
    // Doing count sort from the LSB :
    for (int i = 1; max / i > 0; i *= 10) {
        cout << "Applying Count Sort on the digit place: " << i << "'s place" << endl;
        countSort(i);
        this->displayData();
    }
}

template<typename T>
void SortingSystem<T>::bucketSort() {

    if (this->size == 1) {
        cout << "The sorted data : ";
        this->displayData();
        return;
    }
    // Determine min and max
    T min = data[0], max = data[0];
    for (int i = 0; i < this->size; i++) {
        if (min > data[i]) {
            min = data[i];
        }
        if (max < data[i]) {
            max = data[i];
        }
    }
    cout << "The Min value : " << min << "\nThe Max value : " << max << endl << endl;
    const int range = max - min;
    int numOfBuckets = 0;
    if (this->size <= 5) numOfBuckets = 2;
    else numOfBuckets = 5;
    // using the bucketSizes Array to avoid unnecessary zeros
    int *bucketSizes = new int[numOfBuckets]{};// Initialize all to 0

    for (int i = 0; i < size; i++) {
        const int index = (data[i] - min) * (numOfBuckets - 1) / range;
        ++bucketSizes[index];

    }
    // setting the number of buckets and the bucket width
    T **buckets = new T *[numOfBuckets];
    for (int i = 0; i < numOfBuckets; i++) {
        if (bucketSizes[i] == 0) {
            buckets[i] = new T[bucketSizes[i]];
        } else {
            buckets[i] = new T[bucketSizes[i]]{0};
        }

    }
    cout << "Insertion into the buckets : " << endl;
    // Insert the elements into the buckets
    for (int i = 0; i < size; ++i) {
        int index = (data[i] - min) * (numOfBuckets - 1) / range;
        cout << "Adding [ " << setw(2) << data[i] << setw(3) << " ] to index  : " << index << endl;
        for (int j = 0; j < bucketSizes[index]; j++) {
            if (buckets[index][j] == 0) {
                buckets[index][j] = data[i];
                break;
            }
        }
    }
    cout << "Buckets Before sorting: " << endl;
    for (int i = 0; i < numOfBuckets; i++) {
        cout << "Bucket " << i << ": ";
        for (int j = 0; j < bucketSizes[i]; j++) {
            cout << buckets[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    // Sorting each bucket and merging them back
    for (int k = 0; k < numOfBuckets; ++k) {
        // insertionSort(buckets[i], bucketSizes[i] );
        // var to store the key ( the element that we want to insert in the correct position)
        int key = 0;
        // the while loop iterator
        int j = 0;
        for (size_t i = 1; i < bucketSizes[k]; i++) {
            key = buckets[k][i];// key = 5
            j = i - 1; // j =  1
            // for ascending order
            while (j >= 0 && key < buckets[k][j]) {
                buckets[k][j + 1] = buckets[k][j];
                j--;
            }
            // we have found the correct position for the key
            buckets[k][j + 1] = key;
        }
    }
    cout << "Buckets After sorting : " << endl;
    for (int i = 0; i < numOfBuckets; i++) {
        cout << "Bucket " << i << ": ";

        for (int j = 0; j < bucketSizes[i]; j++) {
            cout << buckets[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    int data_index = 0;
    for (int i = 0; i < numOfBuckets; ++i) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            data[data_index++] = buckets[i][j];
        }
    }
    // Free allocated memory
    for (int i = 0; i < numOfBuckets; ++i) {
        delete[] buckets[i]; // Free each row
    }
    delete[] buckets; // Free the array of pointers
    cout << "The Sorted Data : ";
    this->displayData();
}

template<typename T>
void SortingSystem<T>::displayData() {
    cout << " [ ";
    for (size_t j = 0; j < size; j++) {
        if (j != size - 1) {
            cout << data[j] << ", ";
        } else {
            cout << data[j];
        }
    }
    cout << " ]" << endl;
}

template<typename T>
void SortingSystem<T>::measureSortTime(void(SortingSystem::*sortFunc)()) {
    auto start = chrono::high_resolution_clock::now();
    (this->*sortFunc)();  // Call the sorting function
    auto end = chrono::high_resolution_clock::now();
    auto res = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Sorting Time: " << res.count() << " ms" << endl;

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

    int choice = 0;
    while (true) {
        cout << "Enter your choice : ";
        cin >> choice;
        if (choice >= 1 && choice <= 9) {
            break;
        }
    }

}


#endif //SORTINGSYSTEM_H
