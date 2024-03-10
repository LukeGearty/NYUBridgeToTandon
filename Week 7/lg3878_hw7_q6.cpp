#include <iostream>
#include <vector>
using namespace std;

//array functions
void readNumbers(int *arr, int& arrSize, int& physicalSize);
void resizeArray(int *arr, int& arrSize, int& physicalSize);
void findNum(int *arr, int arrSize, int num);
void main1();
//vector functions
vector <int> createVector();
void findNumVector(vector <int> intVector);
void main2();

int main() {
    int choice;
    cout << "Enter 1 for the function main1, press 2 for the function main2: " << endl;
    cin >> choice;

    if (choice == 1) {
        main1();
    }
    else if (choice == 2) {
        main2();
    }

    return 0;
}
void readNumbers(int *arr, int& arrSize, int& physicalSize) {
    arrSize = 0;
    physicalSize = 1;
    bool seenEndOfText = false;
    int currNum;
    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "End you input by typing -1." << endl;

    while (seenEndOfText == false) {
        cin >> currNum;
        if (currNum == -1) {
            seenEndOfText = true;
        }
        else {
            if (arrSize == physicalSize) {
                resizeArray(arr, arrSize, physicalSize);
            }
            arr[arrSize] = currNum;
            arrSize++;
        }
    }
}
void resizeArray(int *arr, int& arrSize, int& physicalSize) {
    int *newArr = new int[physicalSize * 2];
    for (int i = 0; i < arrSize; i++) {
        newArr[i] = arr[i];
    }
    delete [] newArr;
    arr = newArr;
    physicalSize *= 2;
}
void main1() {
    int* arr = new int[1];
    int arrSize = 0;
    int physicalSize = 1;
    int num;

    readNumbers(arr, arrSize, physicalSize);
    cout << "Please enter a number you want to search: " << endl;
    cin >> num;

    findNum(arr, arrSize, num);

    delete [] arr;

}

void findNum(int *arr, int arrSize, int num) {
    int numOfTimes = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == num) {
            numOfTimes++;
        }
    }
    if (numOfTimes == 0) {
        cout << num << " is not in array" << endl;
    }
    else {
        cout << num << " shows in lines ";
        for (int i = 0; i < arrSize; i++) {
            int line = i + 1;
            if (arr[i] == num) {
                numOfTimes--;
                if (numOfTimes == 0) {
                    cout << line << ".";
                }
                else {
                    cout << line << ", ";
                }
            }
        }
    }
    cout << endl;
}
vector <int> createVector() {
    vector <int> intVector;
    bool seenEndOfText;
    int currNum;

    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "End you input by typing -1." << endl;
    seenEndOfText = false;

    while (seenEndOfText == false) {
        cin >> currNum;
        if (currNum == -1) {
            seenEndOfText = true;
        }
        else {
            intVector.push_back(currNum);
        }
    }

    return intVector;
}
void findNumVector(vector <int> intVector, int num) {
    int numOfTimes = 0;
    for (auto search : intVector) {
        if (search == num) {
            numOfTimes++;
        }
    }

    if (numOfTimes == 0) {
        cout << num << " is not in vector" << endl;
    }
    else {
        cout << num << " shows in lines ";
        int line = 0;
        for (auto element: intVector) {
            line++;
            if (element == num) {
                numOfTimes--;
                if (numOfTimes == 0) {
                    cout << line << ".";
                }
                else {
                    cout << line << ", ";
                }
            }
        }
    }
    cout << endl;
}
void main2() {
    int num;
    vector <int> intVector = createVector();
    cout << "Please enter a number you want to search: " << endl;
    cin >> num;

    findNumVector(intVector, num);

}