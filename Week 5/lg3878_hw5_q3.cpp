#include <iostream>
using namespace std;


int printMonthCalender(int numOfDays, int startingDay);
bool isLeapYear(int year);
void printYearCalender(int year, int startingDay);

int main() { 

    int year, startingDay;

    cout << "Enter the year: " << endl;
    cin >> year;
    cout << "Enter the starting day as a number from 1 (Monday) to 7 (Sunday) " << endl;
    cin >> startingDay;

    printYearCalender(year, startingDay);


    return 0;
}

int printMonthCalender(int numOfDays, int startingDay) {

    int position;

    cout << "Mon\tTue\tWed\tThr\tFri\tSat\tSun";
    cout << endl;
    //the initial tabs
    for (int i = 1; i < startingDay; i++) {
        cout << '\t';
    }

    position = startingDay;

    for (int i = 1; i <= numOfDays; i++) {
        cout << i << '\t';
        position++;
        if (position > 7) {
            cout << endl;
            position = 1;
        }
    }
    cout << endl;
    position = position - 1;

    return position;
}

bool isLeapYear(int year) {
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        return true;
    }
    else {
        return false;
    }
}

void printYearCalender(int year, int startingDay) {
    
    int nextStartingDay;
    cout << "January " << year << endl;
    nextStartingDay = printMonthCalender(31, startingDay) + 1;
    cout << endl;

    cout << "February " << year << endl;
    if (isLeapYear(year)) {
        nextStartingDay = printMonthCalender(29, nextStartingDay) + 1;
    }
    else {
        nextStartingDay = printMonthCalender(28, nextStartingDay) + 1;
    }
    cout << endl;

    cout << "March " << year << endl;
    nextStartingDay = printMonthCalender(31, nextStartingDay) + 1;
    cout << endl;

    cout << "April " << year << endl;
    nextStartingDay = printMonthCalender(30, nextStartingDay) + 1;
    cout << endl;

    cout << "May " << year << endl;
    nextStartingDay = printMonthCalender(31, nextStartingDay) + 1;
    cout << endl;

    cout << "June " << year << endl;
    nextStartingDay = printMonthCalender(30, nextStartingDay) + 1;
    cout << endl;

    cout << "July " << year << endl;
    nextStartingDay = printMonthCalender(31, nextStartingDay) + 1;
    cout << endl;

    cout << "August " << year << endl;
    nextStartingDay = printMonthCalender(31, nextStartingDay) + 1;
    cout << endl;

    cout << "September " << year << endl;
    nextStartingDay = printMonthCalender(30, nextStartingDay) + 1;
    cout << endl;

    cout << "October " << year << endl;
    nextStartingDay = printMonthCalender(31, nextStartingDay) + 1;
    cout << endl;

    cout << "November " << year << endl;
    nextStartingDay = printMonthCalender(30, nextStartingDay) + 1;
    cout << endl;

    cout << "December " << year << endl;
    nextStartingDay = printMonthCalender(31, nextStartingDay) + 1;
    cout << endl;
}