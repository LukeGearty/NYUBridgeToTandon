#include <iostream>
using namespace std;

void printArray(int arr[], int arrSize);
void oddsKeepEvensFlip(int arr[], int arrSize);

int main() {
    //test case 1
    int arr1[6] = {5, 2, 11, 7, 6, 4};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    cout << "Test case 1: " << endl;
    cout << "Before function: " << endl;
    printArray(arr1, size1);
    cout << "After function: " << endl;
    oddsKeepEvensFlip(arr1, size1);
    printArray(arr1, size1);
    cout << endl;

    //test case 2
    int arr2[7] = {2, 4, 6, 8, 11, 15, 97};
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    cout << "Test Case 2: " << endl;
    cout << "Before function: " << endl;
    printArray(arr2, size2);
    cout << "After function: " << endl;
    oddsKeepEvensFlip(arr2, size2);
    printArray(arr2, size2);
    cout << endl;

    //test case 3
    int arr3[10] = {-8, 1, 9, 14, 17, 21, 22, 100, 10, 4};
    int size3 = sizeof(arr3)/sizeof(arr3[0]);
    cout << "Test Case 3: " << endl;
    cout << "Before function: " << endl;
    printArray(arr3, size3);
    cout << "After Function: " << endl;
    oddsKeepEvensFlip(arr3, size3);
    printArray(arr3, size3);
    cout << endl;

    return 0;
}

void printArray(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void oddsKeepEvensFlip(int arr[], int arrSize) {
    int oddIndex = 0;
    int evenIndex = arrSize - 1;
    int *temp = new int[arrSize];

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 == 0) {
            temp[evenIndex] = arr[i];
            evenIndex--;
        } 
        else if (arr[i] % 2 == 1) {
            temp[oddIndex] = arr[i];
            oddIndex++;
        }
    }
    for (int i = 0; i < arrSize; i++) {
        arr[i] = temp[i];
    }

    delete[] temp;
}