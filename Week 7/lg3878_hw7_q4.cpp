#include <iostream>
#include <string>

using namespace std;

int countWords(string sentence);
string* createWordsArray(string sentence, int& outWordsArrSize);
void printStringArray(string wordArray[], int outWordsArrSize);

int main() {

    string sentence;
    int outWordsArrSize;
    cout << "Enter a sentence:" << endl;
    getline(cin, sentence);
    string* wordArray = createWordsArray(sentence, outWordsArrSize);
    printStringArray(wordArray, outWordsArrSize);

    delete[] wordArray;
    return 0;
}
int countWords(string sentence) {
    bool isWord = true;
    int wordCount = 0;
    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] == ' ') {
            isWord = true;
        }
        else if (isWord == true) {
            isWord = false;
            wordCount++;
        }
    }
    return wordCount;
}
string* createWordsArray(string sentence, int& outWordsArrSize) {
    outWordsArrSize = countWords(sentence);
    string* wordsArray = new string[outWordsArrSize];
    int currIndex = 0, start = 0;
    for (int i = 0; i <= sentence.length(); i++) {
        if (sentence[i] == ' ' || i == sentence.length()) {
            string currWord = sentence.substr(start, i - start);
            wordsArray[currIndex] = currWord;
            start = i + 1;
            currIndex++;
        }
    }
    return wordsArray;
}
void printStringArray(string wordArray[], int outWordsArrSize) {
    cout << "[";
    for (int i = 0; i < outWordsArrSize; i++) {
        if (i != outWordsArrSize - 1) {
            cout << "\"" << wordArray[i] << "\"," << ' ';
        }
        else {
            cout << "\"" << wordArray[i] << "\"";
        }
    }
    cout << "]" << endl;
}