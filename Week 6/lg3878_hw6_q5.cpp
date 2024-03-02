#include <iostream>
#include <string>
using namespace std;

int main() {

    string lastName, firstName, middleInitial;

    cout << "Enter your first name, middle initial, and last name: " << endl;
    cin >> firstName >> middleInitial >> lastName;

    cout << lastName << ", " << firstName << " " << middleInitial[0]  << "." << endl;

    return 0;
}