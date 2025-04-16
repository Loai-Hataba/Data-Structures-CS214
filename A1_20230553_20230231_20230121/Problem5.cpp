#include <iostream>
#include <limits>

using namespace std;

int getValidChoice(int begin, int end) {
    int choice;
    while (true) {
        cout << "Choice: ";
        if (cin >> choice) {
            if (choice >= begin && choice <= end) {
                break;
            } else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a valid number." << endl;
            }
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number." << endl;
        }
    }
    return choice;
}


template <typename T>
class StatisticsCalculation{
    private:
        T* data;
        int size;
    public:
        StatisticsCalculation(int size): size(size){
            data = new T[size];
        }
        ~StatisticsCalculation(){
            delete[] data;
        }
        // bubble sort
        void sort() {
            for (int i = 0; i < size - 1; ++i) {
                for (int j = 0; j < size - i - 1; ++j) {
                    if (data[j] > data[j + 1]) {
                        swap(data[j], data[j + 1]);
                    }
                }
            }
        }

        T median(){
            // even
            if(size % 2 == 0){
                return (data[size/2] + data[size/2 - 1]) / 2;
            }
            // odd
            return data[size/2];
        }

        T mean(){
            T sum = 0;
            for (int i = 0; i < size; i++){
                sum += data[i];
            }
            return sum / size;
        }

        T min(){
            return data[0];
        }

        T max(){
            return data[size - 1];
        }

        T sum(){
            T sum = 0;
            for (int i = 0; i < size; i++){
                sum += data[i];
            }
            return sum;
        }

        void displayArray(){
            cout << "Array: [";
            for (int i = 0; i < size; i++)
            {
                cout << data[i] << ", ";
            }
            cout << "]" << endl;
            
        }
        void inputData(){
            for (int i = 0; i < size; i++){
                cout << "Enter element " << i + 1 << ": ";
                cin >> data[i];
            }
        }
        int menu(){
            cout << "\nSelect a Statistical summary: " << endl;
            cout << "1. Median" << endl;
            cout << "2. Mean" << endl;
            cout << "3. Min" << endl;
            cout << "4. Max" << endl;
            cout << "5. Sum" << endl;
            cout << "6. Exit" << endl;
            int choice = getValidChoice(1, 6);
            return choice;
        }
};

template <typename T>
void handleData(int size) {
    StatisticsCalculation<T> stat(size);
    stat.inputData();
    stat.sort();
    while (true) {
        int men = stat.menu();
        switch (men)
        {
            case 1:
                cout << "Median: " << stat.median() << endl;
                break;
            case 2:
                cout << "Mean: " << stat.mean() << endl;
                break;
            case 3:
                cout << "Min: " << stat.min() << endl;
                break;
            case 4:
                cout << "Max: " << stat.max() << endl;
                break;
            case 5:
                cout << "Sum: " << stat.sum() << endl;
                break;
            case 6:
                return;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
}
}


int main(){
    while (true){
        cout << "Choose the type of data: \n1. Integer\n2. Float\nChoice: ";
        int type = getValidChoice(1, 2);
        cout << "Enter the size of the array: ";
        int size;
        cin >> size;
        // int
        if(type == 1){
            handleData<int>(size);
        }
        // double
        else if(type == 2){
            handleData<double>(size);
        }
        while (true){
            cout << "Do you want to Enter a new Sequence?\n1. Yes\n2. No\n";
            int cont = getValidChoice(1,2);
            if (cont == 2) {
                return 0;
            }
            else if (cont == 1)
            {
                break;
            }
            else{
                cout << "Invalid choice" << endl;
            }
        }
    }
}