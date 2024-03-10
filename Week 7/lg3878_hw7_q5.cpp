#include <iostream>
using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);

void printArray(int arr[], int arrSize);

int main() {

    int arr[6] = {3, -1, -3, 0, 6, 4};
    int arrSize = sizeof(arr)/sizeof(arr[0]);

    cout << "Before functions: " << endl;
    printArray(arr, arrSize);

    cout << "getPosNums1" << endl;
    int outPosArrSize;
    int *getPos1 = getPosNums1(arr, arrSize, outPosArrSize);
    printArray(getPos1, outPosArrSize);
    delete [] getPos1;

    cout << "getPosNums2 " << endl;
    int test = 0;
    int *outPosArrSizePtr = &test;
    int *getPos2 = getPosNums2(arr, arrSize, outPosArrSizePtr);
    printArray(getPos2, *outPosArrSizePtr);
    delete [] getPos2;

    cout << "getPosNums3" << endl;
    int posNum3Size;
    int *getPos3;
    getPosNums3(arr, arrSize, getPos3, posNum3Size);
    printArray(getPos3, posNum3Size);
    delete [] getPos3;

    cout << "getPosNums4" << endl;
    int test4 = 0;
    int *outPosArrSize4 = &test4;
    int *getPos4;
    getPosNums4(arr, arrSize, &getPos4, outPosArrSize4);
    printArray(getPos4, *outPosArrSize4);
    delete [] getPos4;

    return 0;
}
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
    int* posNums1 = new int[arrSize];
    outPosArrSize = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            posNums1[outPosArrSize] = arr[i];
            outPosArrSize++;
        }
    }
    return posNums1;
}
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr) {
    int newSize = 0;
    int *posNums2 = new int[arrSize];
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            posNums2[newSize] = arr[i];
            newSize++;
        }
    }
    *outPosArrSizePtr = newSize;
    return posNums2;
}
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
    int newSize = 0;
    int* getPosNum3 = new int[arrSize];
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            getPosNum3[newSize] = arr[i];
            newSize++;
        }
    }
    outPosArrSize = newSize;
    outPosArr = getPosNum3;
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
    int newSize = 0;
    int* getPosNum4 = new int[arrSize];
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            getPosNum4[newSize] = arr[i];
            newSize++;
        }
    }
    *outPosArrPtr = getPosNum4;
    *outPosArrSizePtr = newSize;
}
void printArray(int arr[], int arrSize) {
    cout << "[ ";
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}