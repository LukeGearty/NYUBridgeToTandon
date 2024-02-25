#include <iostream>
using namespace std;

int main() {

    int originalNum, decimalNum, numOfDigits, currExponent, exponent;

    cout << "Enter decimal number:" << endl;
    cin >> originalNum;

    decimalNum = originalNum;
    numOfDigits = 0; // the number of binary digits

    while (decimalNum > 0) {
        decimalNum = decimalNum / 2;
        numOfDigits++;
    }

    cout << numOfDigits << endl;
    decimalNum = originalNum;


    cout << "The binary representation of " << originalNum << " is ";
    while (numOfDigits > 0) {
        currExponent = 1;
        for (int i = 1; i < numOfDigits; i++) {
            currExponent = currExponent * 2;
        }
        if (decimalNum - currExponent >= 0) {
            cout << "1";
            decimalNum = decimalNum - currExponent;
        } 
        else {
            cout << "0";
        }
        numOfDigits--;
    }

    cout << endl;
    
    return 0;
}