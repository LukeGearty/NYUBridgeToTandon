#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


int main() {

    ifstream fileOne("1.txt");
    ifstream fileTwo("2.txt");
    ofstream fileThree("3.txt");

    int temp;
    int tempTwo;
    //read both in
    while (fileOne >> temp && fileTwo >> tempTwo) {
       if (temp < tempTwo) {
            fileThree << temp << endl;
            fileThree << tempTwo << endl;
       }
       else {
        fileThree << tempTwo << endl;
        fileThree << temp << endl;
       }
    }
    fileOne.close();
    fileTwo.close();
    fileThree.close();
    return 0;
}