#include <iostream>
using namespace std;

const double VALUE_OF_QUARTERS = 0.25;
const double VALUE_OF_DIMES = 0.10;
const double VALUE_OF_NICKELS = 0.05;
int main() {

    double dollars, cents, totalMoney, remainingMoney;
    int quarters, dimes, nickels, pennies;
    cout << "Please enter your amount in the format of dollars and cents separated by a space:" << endl;
    cin >> dollars >> cents;

    totalMoney = dollars + (cents/100);
    quarters = totalMoney/0.25;
    remainingMoney = totalMoney - ((double)quarters * VALUE_OF_QUARTERS);
    dimes = remainingMoney/0.10;
    remainingMoney = totalMoney - ((double)quarters * VALUE_OF_QUARTERS + (double)dimes * VALUE_OF_DIMES);
    nickels = remainingMoney/0.05;
    remainingMoney = totalMoney - ((double)quarters * VALUE_OF_QUARTERS + (double)dimes * VALUE_OF_DIMES + (double)nickels * VALUE_OF_NICKELS);
    pennies = remainingMoney * 100;

    cout << dollars << " dollars and " << cents << " cents are\n";
    cout << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels and " << pennies << " pennies " << endl;

    return 0;
}