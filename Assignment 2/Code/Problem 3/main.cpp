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
    int k;
    int arr[100];
    int i = 0;              //size
    while(ss >> arr[i]){
        i++;
    }
    infile>>k;

    int cntToK = 0;
    int cntOfSub = 0;
    bool done = false;
    bool inArow = false;    //zeros in a row
    for (int j = 0; j < i; ++j) {
        if (arr[j] == 0 && cntToK < k){         // count zeros to k
            cntToK++;
            done = true;
            inArow = true;
        }
        if (arr[j] == 0 && cntToK == k){
            cntToK = 0;
            cntOfSub++;
            done = true;
            inArow = false;
        }
        if(arr[j] == 1 && cntToK <= k && inArow) {
            done = false;
            break;
        }
    }

    if (!done || cntToK > 0){
        cout<<"-1"<<endl;
    }
    else {
        cout<<cntOfSub<<endl;
    }

}
