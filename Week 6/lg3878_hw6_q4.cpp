#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void printArray(int arr[], int arrSize);
void createEncryptedNums(int arr[], int arrSize);
bool isCorrecPin(int randArr[], int userInput);

const int PIN_SIZE = 5;
const int TEST_PIN[PIN_SIZE] = {3, 6, 9, 4, 2};
const int ARR_SIZE = 10;

int main() {
    int userInput;
    int randomNumbers[ARR_SIZE];

    createEncryptedNums(randomNumbers, ARR_SIZE);
    cout << "Please enter your PIN according to the following mapping: " << endl;
    cout << "PIN\t0 1 2 3 4 5 6 7 8 9";
    cout << endl;
    cout << "NUM:\t";
    printArray(randomNumbers, ARR_SIZE);
    cout << endl;
    cin >> userInput;

    if (isCorrecPin(randomNumbers, userInput)) {
        cout << "Your PIN is correct" << endl;
    }
    else {
        cout << "Your PIN is not correct" << endl;
    }

    return 0;
}

void printArray(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
}

void createEncryptedNums(int arr[], int arrSize) {
    srand(time(0));

    for (int i = 0; i < arrSize; i++) {
        arr[i] = (rand() % 3) + 1;
    }
}

bool isCorrecPin(int randArr[], int userInput) {

    int currDigitEncrypted;
    int currPinIndex = PIN_SIZE - 1; // so it starts at 4
    int currDigitReal;

    for (int i = 0; i < PIN_SIZE; i++) {
        currDigitEncrypted = userInput % 10;
        currDigitReal = TEST_PIN[currPinIndex];

        if (currDigitEncrypted != randArr[currDigitReal]) {
            return false;
        }

        userInput = userInput / 10;
        currPinIndex--;
    }

    return true;
}
