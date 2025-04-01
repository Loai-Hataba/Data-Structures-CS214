#include <iostream>

using namespace std;

int main(){
    int arrz[] = {2,5,8,3,4,1};
    // main iteration
    int count = 0;
    for (int i = 1, j; i < 6;i++){
        int tempo = arrz[i];
        // reverse iteration
        for(j = i; j >0 && tempo < arrz[j-1]; j--){
            arrz[j] = arrz[j-1];
        }
        arrz[j] = tempo;
        cout << "after Iteration no.: " << count << "\n ";
        for (auto i : arrz)
        {
            cout << i << " ";
        }
        count++;
        cout << endl;
    }
    return 0;
}