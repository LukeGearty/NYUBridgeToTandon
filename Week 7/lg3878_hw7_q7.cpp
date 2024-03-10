#include <iostream>
using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);
void printArray(int arr[], int n);

int main() {

    int arr[5] = {4, 3, 5, 0, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int resArrSize;
    int *newArr = findMissing(arr, n, resArrSize);
    cout << "Before the function: " << endl;
    printArray(arr, n);
    cout << "After function: " << endl;
    printArray(newArr, resArrSize);
    cout << "Size: " << sizeof(newArr) << endl;

    delete [] newArr;
    //test 2
    int testArr2[6] = {3, 1, 3, 0, 6, 4};
    int secondN = sizeof(testArr2)/sizeof(testArr2[0]);
    int secondResArrSize;
    int *secondNewArr = findMissing(testArr2, secondN, secondResArrSize);
    cout << "Before the function: " << endl;
    printArray(testArr2, secondN);
    cout << "After the function: " << endl;
    printArray(secondNewArr, secondResArrSize);
    delete [] secondNewArr;

    cout << endl;
    return 0;
}
int* findMissing(int arr[], int n, int& resArrSize) {
    resArrSize = 0;
    int* newArr = new int[resArrSize];
    int* notInArray = new int[n + 1];
    for (int i = 0; i < n; i++) {
        notInArray[arr[i]]++;
    }
    for (int i = 0; i <= n; i++) {
        if (notInArray[i] == 0) {
            newArr[resArrSize] = i;
            resArrSize++;
        }
    }
    delete [] notInArray;

    return newArr;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}