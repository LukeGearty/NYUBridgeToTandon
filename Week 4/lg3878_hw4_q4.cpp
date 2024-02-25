#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int length, curr, total;
    double geometricMeanA, geometricMeanB;
    bool endOfInput;

    cout << "section a" << endl;

    cout << "Please enter the length of the sequence:";
    cin >> length;

    total = 1;
    cout << "Please enter your sequence: " << endl;
    for (int i = 0; i < length; i++) {
        cin >> curr;
        total = total * curr;
    }

    geometricMeanA= pow(total, 1.0/length);
    cout << "The geometric mean is: " << geometricMeanA << endl;

    cout << "section b" << endl;
    endOfInput = false;
    length = 0;
    total = 1;

    cout << "Please enter a non-empty sequence of positive integers, each one in a separate line. End your sequence by typing -1:" << endl;

    while (endOfInput == false) {
        cin >> curr;
        if (curr == -1) {
            endOfInput = true;
        }
        else {
            total = total * curr;
            length++;
        }
    }

    geometricMeanB = pow(total, 1.0/length);

    cout << "The geometric mean is: " << geometricMeanB << endl;


    return 0;
}