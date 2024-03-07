#include <iostream>
using namespace std;

int main() {

    int n;

    cout << "Please enter a positive integer: " << endl;
    cin >> n; 

    //initialize the loop so it prints out 1 to n+1 times
    for (int i = 1; i <= n+1; i++) {
        
        //if i is an even number, then we just print out the asterisks = n
        if (i % 2 == 0) {
            for (int j = 1; j <= n; j++) {
                cout << "*";
            }
        }
        //if i is not an even number, then we need to print out spaces = n -i / 2, and print out asterisks equal to i
        else if (i % 2 == 1) {
            for (int k = 1; k <= (n-i)/2; k++) {
                cout << " ";
            }
            for (int m = 1; m <= i; m++) {
                cout << "*";
            }

        }
        cout << endl;
    }

    return 0;
}