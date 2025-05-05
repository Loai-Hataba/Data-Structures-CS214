#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream infile("test_1.txt");
    if (!infile.is_open()) {
        cout << "Error opening input File\n";
        return 1;
    }

    int k;
    int *poly1 = new int[100];
    int i = 0;
    while(infile >> poly1[i]){
        i++;
    }
    for (int j = 0; j < i; ++j) {
        cout<<poly1[j];
    }

}
