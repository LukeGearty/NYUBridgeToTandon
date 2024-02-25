#include <iostream>
#include <cmath>
using namespace std;


void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);

int main() {

    int m, outCountDivs, outSumDivs, tempDivs, tempSums;
    cout << "Enter a positive integer >= 2: " << endl;
    cin >> m;

    cout << "Perfect Numbers: " << endl;
    for (int i = 2; i <= m; i++) {
        if (isPerfect(i)) {
            cout << i << endl;
        }
    }

    cout << "Amicable Numbers: " << endl;
    for (int i = 2; i <= m; i++) {
        analyzeDivisors(i, outCountDivs, outSumDivs);
        analyzeDivisors(outSumDivs, tempDivs, tempSums);

        if (i == tempSums && i < outSumDivs) {
            cout << i << " and " << outSumDivs << endl;
        }
    }

    return 0;
}

void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs) {

    int countDivs, sumDivs;
    countDivs = 1;
    sumDivs = 1;

    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            countDivs++;

            if (num / i == i) {
                sumDivs = sumDivs + i;
            }
            else {
                sumDivs = sumDivs + i;
                sumDivs = sumDivs + num / i;
                countDivs++;
            }
        }
    }

    outCountDivs = countDivs;
    outSumDivs = sumDivs;
}

bool isPerfect(int num) {
    int countDivs, sumDivs;
    analyzeDivisors(num, countDivs, sumDivs);

    if (num == sumDivs) {
        return true;
    }
    else {
        return false;
    }
}