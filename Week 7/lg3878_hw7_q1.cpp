#include <iostream>
#include <string>
using namespace std;

bool checkLetter(char input);
bool delimeterCheck(char input);
char getLower(char input);
int getNumWords(string str);
void getLetters(string str, int arr[]);

const int ALPHABET_SIZE = 26;
int main() {

    string userInput;
    int arr[ALPHABET_SIZE] = {};
    int numWords;
    char offset = 'a';

    cout << "Please enter a line of text: " << endl;
    getline(cin, userInput);
    numWords = getNumWords(userInput);

    getLetters(userInput, arr);
    cout << numWords << "\twords" << endl;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (arr[i] > 0) {
            char currLetter = offset + i;
            cout << arr[i] << '\t' << currLetter << endl;
        }
    }
}

bool checkLetter(char input) {
    if ((input >= 'A' && input <= 'Z') || (input >= 'a' && input <= 'z')) {
        return true;
    }
    return false;
}
bool delimeterCheck(char input) {
    if (input == ' ' || input == ',' || input == '.' || input == '\n') {
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
int getNumWords(string str) {
    bool isSpace = true;
    int num = 0;
    for (int i = 0; i < str.length(); i++) {
        if (delimeterCheck(str[i])) {
            isSpace = true;
        }
        else if (isSpace == true) {
            isSpace = false;
            num++;
        }
    }
    return num;
}
void getLetters(string str, int arr[]) {
    char currLetter = 'a';
    for (int i = 0; i < str.length(); i++) {
        if (checkLetter(str[i])) {
            currLetter = str[i];
            currLetter = getLower(currLetter);
            arr[currLetter - 'a']++;
        }
    }
}