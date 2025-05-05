#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(){
    ifstream infile("test_1.txt");
    if (!infile.is_open()) {
        cout << "Error opening input File\n";
        return 1;
    }

    string line1;
    getline(infile, line1); //only first line

    stringstream ss(line1);
    int capacity = 4;
    int size = 0;
    int* arr = new int[capacity];

    int x;
    while (ss >> x) {
        if (size == capacity) {
            capacity *= 2;
            int* newArr = new int[capacity];

            for (int i = 0; i < size; ++i) {
                newArr[i] = arr[i];
            }

            delete[] arr;
            arr = newArr;
        }

        arr[size++] = x;
    }

    int k;
    infile>>k;

//    int cntToK = 0;
    int cntOfSub = 0;
    bool done = true;
//    bool inArow = false;    //subarr begins
    for (int i = 0; i < size; ++i) {
        if (arr[i] == 0){
            for (int j = 0; j < k; ++j) {
                if (i+j == size){
                    done = false;
                    break;
                }
                arr[i+j] = !arr[i+j];
            }
            cntOfSub++;
        }
        else continue;
//        if (inArow){
//            arr[j] =!arr[j];
//            cntToK++;
//        }
//        else if(arr[j] == 1){
//            continue;
//        }
//        if (cntToK > k){
//            cntToK = 0;
//        }
//        if (arr[j] == 0 && cntToK < k){         // count zeros to k
//            cntToK++;
//            inArow = true;
//        }
//        if (arr[j] == 0 && cntToK == k){
//            cntToK = 0;
//            cntOfSub++;
//            inArow = false;
//        }
//        if(arr[j] == 1 && cntToK <= k && inArow) {
//            done = false;
//            break;
//        }
    }

    if (!done){
        cout<<"-1"<<endl;
    }
    else {
        cout<<cntOfSub<<endl;
    }

}
