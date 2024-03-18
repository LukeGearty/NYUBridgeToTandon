#include <iostream>
using namespace std;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);
void printArray(int arr[], int arrSize);

int main () {

    cout << "Section A: sumOfSquares" << endl;
    int arr[4] = {2, -1, 3, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, size);
    int sum = sumOfSquares(arr, size);
    cout << sum << endl;


    cout << "Section B: isSorted" << endl;
    int sortedArr[5] = {1, 2, 3, 4, 5};
    int sizeSorted = sizeof(sortedArr)/sizeof(sortedArr[0]);
    printArray(sortedArr, sizeSorted);
    if (isSorted(sortedArr,sizeSorted)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    int unsortedArr[9] = {10, 93, 19, 45, 100, 33, -1001, 22, -7};
    int sizeUnsorted = sizeof(unsortedArr)/sizeof(unsortedArr[0]);
    printArray(unsortedArr, sizeUnsorted);
    if (isSorted(unsortedArr, sizeUnsorted)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    int sortedArr2[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int sortedSize2 = sizeof(sortedArr2)/sizeof(sortedArr2[0]);
    printArray(sortedArr2, sortedSize2);
    if (isSorted(sortedArr2,sortedSize2)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    int unsortedArr2[5] = {100, 90, 80, 70, 60};
    int unsortedSize2 = sizeof(unsortedArr2)/sizeof(unsortedArr2[0]);
    printArray(unsortedArr2, unsortedSize2);
    if (isSorted(unsortedArr2,unsortedSize2)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    return 0;
}
int sumOfSquares(int arr[], int arrSize) {
    if (arrSize == 1) {
        return (arr[0] * arr[0]);
    }
    else {
        return sumOfSquares(arr, arrSize - 1) + arr[arrSize - 1] * arr[arrSize - 1];
    }
}

bool isSorted(int arr[], int arrSize) {
    if (arrSize == 1) {
        return true;
    }
    else {
        int first = arr[arrSize - 1];
        int second = arr[arrSize - 2];
        if (first > second) {
            return isSorted(arr, arrSize - 1);
        }
        else {
            return false;
        }
    }
}

void printArray(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}