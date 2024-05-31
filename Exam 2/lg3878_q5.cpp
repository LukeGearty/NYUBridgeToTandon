#include <iostream>
#include <string>
using namespace std;

bool countEvens(char c);
bool recursiveEven(string str, int strLength);
bool moreEvens(string S);

int main () {

    string str;
    getline(cin, str);

    cout << moreEvens(str) << endl;
    
    return 0;
}

bool countEvens(char c) {
    if (c == '0' || c == '2' || c == '4' || c == '6' || c == '8') {
        return true;
    }
    else {
        return false;
    }
}

bool recursiveEven(string str, int strLength) {
    if (strLength <= 1) {
        return (countEvens(str[0]));
    }
    else {
        int odds = 0;
        int evens = 0;
        char curr = str[strLength - 1];

        if (countEvens(curr)) {
            evens++;
        }
        else {
            odds++;
        }

        
        recursiveEven(str, strLength -1);
        if (odds >= evens) {
            return true;
        }
        else {
            return false;
        }
    }
}

bool moreEvens(string S) {

    if (recursiveEven(S, S.length())) {
        cout << "True" << endl;
        return true;
    }
    else {
        cout << "false" << endl;
        return false;
    }

}