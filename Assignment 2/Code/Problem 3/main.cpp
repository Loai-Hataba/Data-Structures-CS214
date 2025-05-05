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
    for (int j = 0; j < i; ++j) {
        cout<<arr[j];
    }
    cout<<endl;
    cout<<k<<endl;

}
