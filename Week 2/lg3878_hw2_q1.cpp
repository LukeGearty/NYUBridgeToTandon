#include <iostream>
using namespace std;

const double VALUE_OF_QUARTERS = 0.25;
const double VALUE_OF_DIMES = 0.10;
const double VALUE_OF_NICKELS = 0.05;
int main() {

    double quarters, dimes, nickels, pennies, totalMoney;
    int totalDollars, totalCents;

    cout << "Please enter number of coins: " << endl;
    cout << "# of quarters: ";
    cin >> quarters;
    cout << "# of dimes: ";
    cin >> dimes;
    cout << "# of nickels: ";
    cin >> nickels;
    cout << "# of pennies: ";
    cin >> pennies;

    totalMoney = (quarters * VALUE_OF_QUARTERS) + (dimes * VALUE_OF_DIMES) + (nickels * VALUE_OF_NICKELS) + (pennies * 0.01);

    totalDollars = totalMoney;
    totalCents = (totalMoney - (double)totalDollars) * 100;

    cout << "The total is " << totalDollars << " dollars and " << totalCents << " cents" << endl;
    return 0;
}