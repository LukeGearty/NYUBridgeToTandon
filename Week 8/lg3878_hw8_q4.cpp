#include <iostream>
using namespace std;

int jumpItGame(int arr[], int arrSize);
void printArray(int arr[], int arrSize);
int main() {
    
    int arr1[6] = {0, 3, 80, 6, 57, 10};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    printArray(arr1, size1);
    cout << jumpItGame(arr1, size1) << endl;

    int arr2[7] = {1, 3, 8, 10, 9, 4, 7};
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    printArray(arr2, size2);
    cout << jumpItGame(arr2, size2) << endl;
    return 0;
}

void printArray(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int jumpItGame(int arr[], int arrSize) {
    int total = 0;
    if (arrSize <= 3) {
        total += arr[arrSize - 1];
        return total;
    }
    else {
        total += arr[arrSize - 1];
        int nextOver = jumpItGame(arr, arrSize - 1);
        int jump = jumpItGame(arr, arrSize - 2);

        if (total + nextOver > total + jump) {
            return total + jump;
        }
        else {
            return total + nextOver;
        }
    }
}