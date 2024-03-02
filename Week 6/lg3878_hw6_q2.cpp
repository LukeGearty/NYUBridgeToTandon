#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str);
int main() {

    string userInput;

    cout << "Please enter a word: ";
    cin >> userInput;

    if (isPalindrome(userInput)) {
        cout << userInput << " is a palindrome" << endl;
    }
    else {
        cout << userInput << " is not a palindrome" << endl;
    }

    return 0;
}

bool isPalindrome(string str) {

    int length = str.length();

    for (int i = 0; i < length; i++) {
        if (str[i] != str[length - i - 1]) {
            return false;
        }
    }

    return true;

}