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

int* sum(int* poly1, int*poly2, int* res, int size1, int size2, int maxSize){
    for (int i = 0; i < maxSize; ++i) {
        if (i >= size1){
            res[i] = poly2[i];
        }
        else if (i >= size2){
            res[i] = poly1[i];
        }
        else res[i] = poly1[i] + poly2[i];
    }
    return res;
}
int* diff(int* poly1, int* poly2, int *res, int size1, int size2, int maxSize){
    for (int i = 0; i < maxSize; ++i) {
        if (i >= size1){
            res[i] = poly2[i];
        }
        else if (i >= size2){
            res[i] = poly1[i];
        }
        else res[i] = poly2[i] - poly1[i];
    }
    return res;
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

    int maxSZ = max(sz1,sz2);

    cout<<"Enter polynomial: ";
    for (int i = 0; i < sz2; ++i) {
        cin>>poly2[i];
    }

    cout<<"first polynomial: ";
    displayPoly(poly1, sz1);
    cout<<"second polynomial: ";
    displayPoly(poly2, sz2);


    int* sumPoly = new int[maxSZ];
    sumPoly = sum(poly1, poly2, sumPoly, sz1, sz2, maxSZ);
    cout<<"Sum of the two polynomials: ";
    displayPoly(sumPoly, maxSZ);

    int* diffPoly = new int[maxSZ];
    diffPoly = diff(poly1, poly2, diffPoly, sz1, sz2, maxSZ);
    cout<<"Difference of the two polynomials: ";
    displayPoly(diffPoly, maxSZ);

    delete[] poly1;
    delete[] poly2;
    delete[] sumPoly;
    delete[] diffPoly;
}
