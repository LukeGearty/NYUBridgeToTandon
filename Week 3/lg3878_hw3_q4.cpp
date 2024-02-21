#include <iostream>
using namespace std;

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;
int main() {

    double userNumber, result;
    int roundingMethod, integerPart;
    double decimalPart;

    cout << "Please enter a Real number:" << endl;
    cin >> userNumber;

    cout << "Choose your rounding method:\n1. Floor round\n2. Ceiling round\n3. Round to the nearest whole number" << endl;
    cin >> roundingMethod;
    
    if (roundingMethod == FLOOR_ROUND || roundingMethod == CEILING_ROUND || roundingMethod == ROUND) {

        integerPart = userNumber / 1;
        decimalPart = (userNumber - (double)integerPart);

        switch(roundingMethod) {
            case FLOOR_ROUND:
                if (userNumber > 0) {
                    result = integerPart;
                    cout << result << endl;
                } 
                else {
                    result = integerPart - 1;
                    cout << result << endl;
                }
                break;
            case CEILING_ROUND:
                if (userNumber > 0 && decimalPart > 0) {
                    result = integerPart + 1;
                    cout << result << endl;
                }
                else {
                    result = integerPart;
                    cout << result << endl;
                }
                break;
            case ROUND:
                if (userNumber > 0) {
                    if (decimalPart > .5) {
                        result = integerPart + 1;
                        cout << result << endl;
                    }
                    else {
                        result = integerPart;
                        cout << result << endl;
                    }
                }
                else {
                    if (decimalPart > -.50) {
                        result = integerPart;
                        cout << result << endl;
                    } 
                    else {
                        result = integerPart - 1;
                        cout << result << endl;
                    }
                }
                break;
        }
    }
    else {
        cout << "Invalid input" << endl;
    }
    return 0;
}