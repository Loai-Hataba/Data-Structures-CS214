#include <iostream>
using namespace std;

//void displayPoly(int* poly, int size){
//    bool first = true;
//    for (int i = size-1; i >= 0; --i) {
//        if (poly[i] != 0) {
//            if (!first || i != 0) {
//                if (poly[i] > 0) {
//                    cout << " + ";
//                } else cout << " - ";
//            }
//            else if (poly[i] < 0)cout<<'-';
//            if (i == 0) cout<<" = ";
//            if (abs(poly[i]) > 1 && i != 0) {
//                cout << abs(poly[i]);
//            }
//            else cout<<'x';
//            if ()
//            if (i - 2 > 1)cout<<'^'<<i-2;
//        }
//        first = false;
//    }
//    if (first) cout<<"0";
//    cout<<endl;
//}


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
    for (int i = 0; i < sz1; ++i) {
        cin>>poly2[i];
    }

//    cout<<"first polynomial: ";
//    displayPoly(poly1, sz1);
//    cout<<"second polynomial: ";
//    displayPoly(poly2, sz2);

}
