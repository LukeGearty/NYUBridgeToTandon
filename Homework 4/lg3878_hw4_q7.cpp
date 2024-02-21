#include <iostream>
using namespace std;

int main() {

    int userInput, currNum;

    cout << "Please enter a positive integer:" << endl;
    cin >> userInput;

    for (int i = 1; i <= userInput; i++) {
        cout << i << " ";
        cout << "\t";
        for (int j = 2; j <= userInput; j++) {
            cout << i * j;
            cout << "\t";
        }
        cout << endl;
    }

    return 0;
}