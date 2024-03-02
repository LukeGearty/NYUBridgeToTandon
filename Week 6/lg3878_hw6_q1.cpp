#include <iostream>
using namespace std;

int minInArray(int arr[], int arrSize);
void findInArray(int arr[], int arrSize, int value);

int main() {

    int arr[20];
    int size = sizeof(arr)/sizeof(arr[0]);
    int minValue;

    cout << "Please enter 20 integers separated by a space: " << endl;

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    minValue = minInArray(arr, size);
    cout << "The minimum value is " << minValue << " and it is located in the following indices: ";
    findInArray(arr, size, minValue);
    cout << endl;
    
    return 0;
}

int minInArray(int arr[], int arrSize) {

    int minValue;
    minValue = arr[0];

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] < minValue) {
            minValue = arr[i];
        }
    }

    return minValue;
}

void findInArray(int arr[], int arrSize, int value) {
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == value) {
            cout << i << " ";
        }
    }
}