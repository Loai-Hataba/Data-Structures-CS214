#include <iostream>
using namespace std;

void displayPoly(int* poly, int size){
    bool first = true;
    bool beforeLast = false;
    int deg = size - 2;
    int lhsIsEmpty = true;
    for (int i = size-1; i >= 0; --i) {
        if (i == 0) {
            if (lhsIsEmpty){
                cout<<'0';
            }
            cout << " = " << poly[i];
            break;
        }
        if (poly[i] != 0) {
            if (!first) {
                if (poly[i] > 0) {
                    cout << " + ";
                } else if (poly[i] < 0) cout << " - ";
            } else if (poly[i] < 0)cout << '-';
            if (beforeLast){
                cout<<abs(poly[i]);
                continue;
            }
            else if(abs(poly[i]) > 1){
                cout<<abs(poly[i]);
            }
            if (deg > 1){
                cout<<"x^"<<deg;
                lhsIsEmpty = false;
            }
            else {
                cout<<'x';
                lhsIsEmpty = false;
            }
            first = false;
        }
        if (deg == 1 ){
            beforeLast = true;
        }
        deg--;
    }
    cout << endl;
}




int main() {
    int deg1, deg2;

    cout<<"Order of first polynomial: ";
    cin>>deg1;
    int sz1 = deg1+2;
    int* poly1 = new int[sz1];

    cout<<"Enter polynomial: ";
    for (int i = 0; i < sz1; ++i) {
        cin>>poly1[i];
    }

    cout<<"Order of second polynomial: ";
    cin>>deg2;
    int sz2 = deg2+2;
    int* poly2 = new int[sz2];

    cout<<"Enter polynomial: ";
    for (int i = 0; i < sz2; ++i) {
        cin>>poly2[i];
    }

    cout<<"first polynomial: ";
    displayPoly(poly1, sz1);
    cout<<"second polynomial: ";
    displayPoly(poly2, sz2);

}
