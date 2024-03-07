#include <iostream>
using namespace std;

int main() {

    int grade;
    int excellent, veryGood, averageGroup, belowAverage; //the groups
    int totalStudents, maxScore, minScore;
    double totalAmount, overallAverage;
    bool userIsTyping;

    cout << "Please enter a sequence of numbers in between 1 and 100, each one in a separate line. End your sequence by typing -1:" << endl;

    excellent = 0;
    veryGood = 0;
    averageGroup = 0;
    belowAverage = 0;
    totalStudents = 0; //will increment each time the loop runs
    maxScore = 0; 
    minScore = 100;
    overallAverage = 0;
    totalAmount = 0;
    userIsTyping = true;

    while (userIsTyping == true) {
        cin >> grade;

        //first check if the user typed in -1
        if (grade == -1) {
            userIsTyping = false;
            // just so -1 is not included in the below code
            break;
        }

        //checking for the group they are in
        if (grade >= 90) {
            excellent++;
        }
        else if (grade >= 80 && grade < 90) {
            veryGood++;
        }
        else if (grade >= 70 && grade < 80) {
            averageGroup++;
        }
        else if (grade < 70) {
            belowAverage++;
        }

        //checking for the max and min
        
        if (grade > maxScore) {
            maxScore = grade;
        }
        else if (grade < minScore) {
            minScore = grade;
        }

        totalAmount = totalAmount + (double)grade;
        totalStudents++;
    }

    //compute average
    overallAverage = totalAmount/(double)totalStudents;

    //the cout statements

    cout << "Number of students in the Excellent Category: " << excellent << endl;
    cout << "Number of students in the Very Good Category: " << veryGood << endl;
    cout << "Number of students in the Average Category: " << averageGroup << endl;
    cout << "Number of students in the Below Average Category: " << belowAverage << endl;
    cout << "Total number of people in the given sequence of scores: " << totalStudents << endl;
    cout << "Maximum score among the given sequence of scores: " << maxScore << endl;
    cout << "Minimum score among the given sequence of scores: " << minScore << endl;
    cout << "Overall Average score of the given sequence of scores: " << overallAverage << endl;


    return 0;
}