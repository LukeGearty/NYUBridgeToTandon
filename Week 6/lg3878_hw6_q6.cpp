#include <iostream>
#include <string>
using namespace std;


bool isDigit(char input);
bool isNumberWord(string word);
bool checkSpace(char input);
string convertWord(string word);

int main() {

    string userInput, changedStr;
    cout << "Please enter a line of text: " << endl;
    getline(cin, userInput);

    int startIndex = 0;
    for (int i = 0; i <= userInput.length(); i++) {
        string word = "";
        if (checkSpace(userInput[i]) || i == userInput.length()) {
            string word = userInput.substr(startIndex, i - startIndex);
            changedStr += convertWord(word) + " ";
            startIndex = i + 1;
        }
    }

    cout << changedStr << endl;
    


    return 0;
}

bool isDigit(char input) {
    if (input < '0' || input > '9') {
        return false;
    }
    return true;
}

bool isNumberWord(string word) {
    for (int i = 0; i < word.length(); i++) {
        if (isDigit(word[i]) == false) {
            return false;
        }
    }
    return true;
}

bool checkSpace(char input) {
    if (input == ' ') {
        return true;
    }
    return false;
}

string convertWord(string word) {
    string convertedWord = "";
    if (isNumberWord(word)) {
        for (int i = 0; i < word.length(); i++) {
            convertedWord += 'x';
        }
        return convertedWord;
    }
    else {
        return word;
    }
}