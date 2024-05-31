#include <iostream>
#include <vector>
using namespace std;


int getDigits(int n);
int main() {

    vector <int> threeDigit;
    vector <int> fourDigit;
    vector <int> fiveDigit;

    int userInput;
    bool reachedEnd = false;
    int threeDigitSum, fourDigitSum, fiveDigitSum;
    cout << "Please enter a sequence of positive integers (each integer will have at least 3 decimal digits and at most 5 decimal digits and first digit of each integer won’t be 0), each one in a separate line. End your sequence by typing -1:" << endl;

    threeDigitSum = 0;
    fourDigitSum = 0;
    fiveDigitSum = 0;
    while (reachedEnd == false) {
        cin >> userInput;
        if (userInput == -1) {
            reachedEnd = true;
        }
        else {
            if (userInput >= 100 && userInput <= 999) {
                threeDigit.push_back(userInput);
                threeDigitSum += getDigits(userInput);
            }
            else if (userInput >= 1000 && userInput <= 9999) {
                fourDigit.push_back(userInput);
                fourDigitSum += getDigits(userInput);
            }
            else if (userInput >= 10000 && userInput <= 99999) {
                fiveDigit.push_back(userInput);
                fiveDigitSum += getDigits(userInput);
            }
        }
    }

    for (int i = 0; i < threeDigit.size(); i++) {
        cout << threeDigit[i] << endl;
    }

    for (int i = 0; i < fourDigit.size(); i++) {
        cout << fourDigit[i] << endl;
    }

    for (int i = 0; i < fiveDigit.size(); i++) {
        cout << fiveDigit[i] << endl;
    }

    cout << "Summation of all the digits in all the 3 digits integers:" << threeDigitSum << endl;
    cout << "Summation of all the digits in all the 4 digits integers:" << fourDigitSum << endl;
    cout << "Summation of all the digits in all the 5 digits integers:" << fiveDigitSum << endl;
    return 0;
}

int getDigits(int n) {

    int x = n;
    int sum = 0;
    while (x >= 1) {
        int curr = x % 10;
        sum = sum + curr;
        x /= 10;
    }
    return sum;
}