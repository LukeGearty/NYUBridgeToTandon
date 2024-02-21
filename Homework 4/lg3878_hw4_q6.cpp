#include <iostream>
using namespace std;

int main() {

    int userInput, currNum, currDigit;
    int oddDigits, evenDigits;
    cout << "Please enter a positive integer: ";
    cin >> userInput;

    for (int i = 1; i < userInput; i++) {
        oddDigits = 0;
        evenDigits = 0;
        currNum = i;
        while (currNum > 0) {
            currDigit = currNum % 10;
            if (currDigit % 2 == 0) {
                evenDigits++;
            } 
            else if (currDigit % 2 == 1) {
                oddDigits++;
            }
            currNum = currNum / 10;
        }
        if (evenDigits > oddDigits) {
            cout << i << endl;
        }
    }
    
    return 0;
}