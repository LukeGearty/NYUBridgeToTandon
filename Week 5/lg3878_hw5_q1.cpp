#include <iostream>
using namespace std;

int fib(int n);

int main() {

    int num;
    
    cout << "Please enter a positive integer: ";
    cin >> num;

    cout << fib(num) << endl;

    return 0;
}

int fib(int n) {

    int result;
    int firstNum, secondNum, temp;
    result = 1;

    if (n == 1) {
        return result;
    }
    else {
        firstNum = 0;
        secondNum = 1;

        for (int i = 2; i <= n; i++) {
            result = firstNum + secondNum;
            temp = secondNum;
            secondNum = firstNum + secondNum;
            firstNum = temp;
        }

        return result;
    }

    
    return result;


}