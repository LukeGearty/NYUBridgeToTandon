#include <iostream>
#include <string>
using namespace std;

const double WEEKEND_PRICE = 0.15;
const double WEEKDAY_BETWEEN_EIGHT_SIX = 0.40; //Between eight AM and six PM
const double WEEKDAY_BETWEEN_SIX_EIGHT = 0.25; // After six PM and before eight AM
int main() { 

    int hours24, timeMinutes, callMinutes;
    char temp;
    string day;
    double callPrice;

    cout << "Enter the day of the week as two characters: Mo Tu We Th Fr Sa Su: " << endl;
    cin >> day;
    cout << "Enter the length of the call in minutes: " << endl;
    cin >> callMinutes;
    cout << "Enter the time your call started in 24 hour notation: " << endl;
    cin >> hours24 >> temp >> timeMinutes;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    if (day == "Sa" || day == "Su") {
        callPrice = (double)callMinutes * WEEKEND_PRICE;
    }
    else {
        cout << timeMinutes << endl;
        if (hours24 >= 8 && hours24 <= 18) {
            callPrice = (double)callMinutes * WEEKDAY_BETWEEN_EIGHT_SIX;
        } 
        else if (hours24 < 8 || (hours24 > 18 && timeMinutes > 1)) {
            callPrice = (double)callMinutes * WEEKDAY_BETWEEN_SIX_EIGHT;
        }
    }

    cout << "Your call will cost $" << callPrice << endl;


    return 0;
}