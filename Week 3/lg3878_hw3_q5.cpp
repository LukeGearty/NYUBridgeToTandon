#include <iostream>
using namespace std;

int main() {
    
    int userHeight, userWeight;
    double heightInMeters, weightInKilos, bmi;

    cout << "Please enter weight (in pounds):" << endl;
    cin >> userWeight;
    cout << "Please enter height (in inches):" << endl;
    cin >> userHeight;

    heightInMeters = (double)userHeight * 0.0254;
    weightInKilos = (double)userWeight * 0.453592;

    bmi = weightInKilos/(heightInMeters*heightInMeters);

    if (bmi < 18.5) {
        cout << "The weight status is: Underweight" << endl;
    }
    else if (bmi >= 18.5 && bmi < 25) {
        cout << "The weight status is: Normal" << endl;
    }
    else if (bmi >= 25 && bmi < 30) {
        cout << "The weight status is: Overweight" << endl;
    }
    else {
        cout << "The weight status is: Obese" << endl;
    }

    return 0;
}