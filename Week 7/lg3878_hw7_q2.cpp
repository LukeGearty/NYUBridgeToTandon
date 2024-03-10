#include <iostream>
#include <string>
using namespace std;

bool checkLetter(char input);
char getLower(char input);
void iterateThroughString(string str, int arr[]);
bool checkArrays(int arr1[], int arr2[]);

const int ALPHABET_SIZE = 26;
int main() {

    string input1, input2;
    int arr1[ALPHABET_SIZE] = {};
    int arr2[ALPHABET_SIZE] = {};

    cout << "Enter the first string: " << endl;
    getline(cin, input1);
    cout << "Enter the second string: " << endl;
    getline(cin, input2);
    iterateThroughString(input1, arr1);
    iterateThroughString(input2, arr2);

    if (checkArrays(arr1, arr2)) {
        cout << "The two strings are anagrams" << endl;
    }
    else {
        cout << "The two strings are not anagrams" << endl;
    }
    return 0;
}
bool checkLetter(char input) {
    if ((input >= 'A' && input <= 'Z') || (input >= 'a' && input <= 'z')) {
        return true;
    }
    return false;
}
char getLower(char input) {
    char lowerCase;
    if (input >= 'A' && input <= 'Z') {
        lowerCase = input + 32;
        return lowerCase;
    }
    return input;
}
void iterateThroughString(string str, int arr[]) {
    char currLetter;
    for (int i = 0; i < str.size(); i++) {
        if (checkLetter(str[i])) {
            currLetter = getLower(str[i]);
            arr[currLetter - 'a']++;
        }
    }
}
bool checkArrays(int arr1[], int arr2[]) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}