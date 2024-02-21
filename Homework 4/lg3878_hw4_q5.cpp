#include <iostream>
using namespace std;

int main() {

    int userInput, amountOfAsterisks, amountOfSpaces;

    cout << "Enter a positive integer: ";
    cin >> userInput;

    amountOfAsterisks = (2* userInput) - 1; // the initial amount on the first line
    amountOfSpaces = 0;

    //use 2 for loops to make the size 2 * userInput
    
    //the first half of the hourglass
    for (int i = 0; i < userInput; i++) {
        for (int j = 0; j < amountOfSpaces; j++) {
            cout << " ";
        }
        for (int k = 0; k < amountOfAsterisks; k++) {
            cout << "*";
        }
        amountOfSpaces++;
        amountOfAsterisks = amountOfAsterisks - 2;
        cout << endl;
    }

    //the second half of the hourglass
    amountOfAsterisks = 1;

    for (int i = 0; i < userInput; i++) {
        for (int j = 1; j < amountOfSpaces; j++) {
            cout << " ";
        } 
        for (int k = 0; k < amountOfAsterisks; k++) {
            cout << "*";
        }
        cout << endl;
        amountOfSpaces--;
        amountOfAsterisks = amountOfAsterisks + 2;
    }
    return 0;
}