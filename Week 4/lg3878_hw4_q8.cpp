#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

    bool userHasGuessed;
    int randomNumber, userGuess, numOfGuessesLeft, numOfGuessesMade;
    int minRange, maxRange;

    cout << "I thought of a number between 1 and 100! Try to guess it." << endl;
    srand(time(0));
    randomNumber = (rand() % 100) + 1;
    userHasGuessed = false;
    minRange = 1;
    maxRange = 100;
    numOfGuessesLeft = 5;
    numOfGuessesMade = 0;

    while (userHasGuessed == false) {
        cout << "Range: [" << minRange << ", " << maxRange << "], Number of guesses left: " << numOfGuessesLeft << endl;
        cout << "Your guess: ";
        cin >> userGuess;
        numOfGuessesMade++;
        numOfGuessesLeft--;

        if (userGuess == randomNumber) {
            cout << "Congrats! You guessed my number in " << numOfGuessesMade << " guesses." << endl;
            userHasGuessed = true;
        }
        else if (numOfGuessesLeft == 0) {
            cout << "Out of guesses! My number is " << randomNumber << endl;
            userHasGuessed = true;
        }
        else {
            if (userGuess > randomNumber) {
                cout << "Wrong! My number is smaller.";
                maxRange = userGuess - 1;
                cout << endl;
            }
            else if (userGuess < randomNumber) {
                cout << "Wrong! My number is bigger.";
                minRange = userGuess + 1;
                cout << endl;
            }
        }
    }

    return 0;
}