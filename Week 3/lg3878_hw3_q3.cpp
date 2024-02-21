#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    double discriminantFormula, solution, solutionTwo;
    
    cout << "Please enter value of a: ";
    cin >> a;
    cout << "Please enter value of b: ";
    cin >> b;
    cout << "Please enter value of c: ";
    cin >> c;

    discriminantFormula = ((b*b) - (4 * a * c));
    solution = ((b * -1) + sqrt((b*b) -(4 * a * c)))/(2 * a);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
    
    if (a == 0 && b == 0 && c == 0) {
        cout << "This equation has an infinite number of solutions" << endl;
    }
    else if (a == 0 && b == 0 && c != 0) {
        cout << "This equation has no solution" << endl;
    }
    else if (discriminantFormula < 0) {
        cout << "This equation has no real solutions" << endl;
    }
    else if (discriminantFormula == 0) {
        cout << "This equation has a single real solution x=" << solution << endl;
    } 
    else if (discriminantFormula > 0) {
        solutionTwo = ((b * -1) - sqrt((b*b) -(4 * a * c)))/(2 * a);
        cout << "This equation has two real solutions x1=" << solution << " and x2 =" << solutionTwo << endl;
    }

    return 0;
}