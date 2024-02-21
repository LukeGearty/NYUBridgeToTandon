#include <iostream>
using namespace std;

const int MINUTES_IN_HOURS = 60;
const int HOURS_IN_DAY = 24;
int main() {

    int johnDays, johnHours, johnMinutes, billDays, billHours, billMinutes;
    int totalDays, totalHours, totalMinutes;

    cout << "Please enter the number of days John has worked: ";
    cin >> johnDays;
    cout << "Please enter the number of hours John has worked: ";
    cin >> johnHours;
    cout << "Please enter the number of minutes John has worked: ";
    cin >> johnMinutes;

    cout << endl;

    cout << "Please enter the number of days Bill has worked: ";
    cin >> billDays;
    cout << "Please enter the number of hours Bill has worked: ";
    cin >> billHours;
    cout << "Please enter the number of minutes Bill has worked: ";
    cin >> billMinutes;

    totalMinutes = (johnMinutes + billMinutes) % MINUTES_IN_HOURS;
    totalHours = ((johnHours + billHours) % HOURS_IN_DAY) + ((johnMinutes + billMinutes) / MINUTES_IN_HOURS);
    totalDays = (johnDays + billDays) + ((johnHours + billHours) / HOURS_IN_DAY);

    cout << "The total time both of them worked together is: " << totalDays << " days, " << totalHours << " hours, and " << totalMinutes << " minutes." << endl;
    return 0;
}