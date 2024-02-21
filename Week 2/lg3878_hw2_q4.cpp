#include <iostream>
using namespace std;

int main() {

    int numOne, numTwo, sum, difference, product, integerQuotient, remainder;
    double decimalQuotient;

    cout << "Please enter two positive integers, separated by a space: " << endl;
    cin >> numOne >> numTwo;

    sum = numOne + numTwo;
    difference = numOne - numTwo;
    product = numOne * numTwo;
    decimalQuotient = (double)numOne / (double)numTwo;
    integerQuotient = numOne / numTwo;
    remainder = numOne % numTwo;

    cout << numOne << " + " << numTwo << " = " << sum << endl;
    cout << numOne << " - " << numTwo << " = " << difference << endl;
    cout << numOne << " * " << numTwo << " = " << product << endl;
    cout << numOne << " / " << numTwo << " = " << decimalQuotient << endl;
    cout << numOne << " div " << numTwo << " = " << integerQuotient << endl;
    cout << numOne << " mod " << numTwo << " = " << remainder << endl;

    return 0;
}