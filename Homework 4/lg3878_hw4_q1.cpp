#include <iostream>
using namespace std;

int main() {

    int inputNum, firstCount, secondCount;

    cout << "Please enter a positive integer: ";
    cin >> inputNum;

    cout << "section a" << endl;
    firstCount = 1;
    while (firstCount <= inputNum) {
        cout << firstCount * 2 << endl;
        firstCount++;
    }
    
    cout << "section b" << endl;
    for (secondCount = 1; secondCount <= inputNum; secondCount++) {
        cout << secondCount * 2 << endl;
    }

    return 0;
}