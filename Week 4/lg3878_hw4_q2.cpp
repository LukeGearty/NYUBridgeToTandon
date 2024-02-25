#include <iostream>
#include <string>
using namespace std;

int main() {
    
    int decimalNum, originalNum, currNum, digit;
    int amountOfM; // only if the input number goes past 5 digits
    string romanNum;

    cout << "Enter decimal number: " << endl;
    cin >> originalNum;
    decimalNum = originalNum;
    digit = 1;
    amountOfM = 10;
    romanNum = "";

    while (decimalNum > 0) {
        currNum = decimalNum % 10;
        if (digit == 1) {
            if (currNum < 5) {
                for (int i = 0; i < currNum; i++) {
                    romanNum = "I" + romanNum;
                }
            }
            else if (currNum >= 5) {
                for (int i = 0; i <currNum - 5; i++) {
                    romanNum = romanNum + "I";
                }
                romanNum = "V" + romanNum;
            }
        }
        else if (digit == 2) {
            if (currNum < 5) {
                for (int i = 0; i < currNum; i++) {
                    romanNum = "X" + romanNum;
                }
            }
            else if (currNum >= 5) {
                for (int i = 0; i < currNum - 5; i++) {
                    romanNum = "X" + romanNum;
                }
                romanNum = "L" + romanNum;
            }
        }
        else if (digit == 3) {
            if (currNum < 5) {
                for (int i = 0; i < currNum; i++) {
                    romanNum = "C" + romanNum;
                }
            }
            else if (currNum >= 5) {
                for (int i = 0; i < currNum - 5; i++) {
                    romanNum = "C" + romanNum;
                }
                romanNum = "D" + romanNum;
            }
        }
        else if (digit == 4) {
            for (int i = 0; i < currNum; i++) {
                romanNum = "M" + romanNum;
            }
        }
        else {
            for (int i = 0; i < amountOfM * currNum; i++) {
                romanNum = "M" + romanNum;
            }
            amountOfM = amountOfM * 10;
        }
        decimalNum = decimalNum / 10;
        digit++;
    }
    cout << originalNum << " is " << romanNum << endl;
    return 0;
}