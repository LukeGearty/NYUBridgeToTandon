#include <iostream>
using namespace std;


void printShiftedTriangle(int n, int m, char symbol);
void printPineTree(int n, char symbol);

int main() {

    int n;
    char symbol;

    cout << "Enter number of triangles: " << endl;
    cin >> n;
    cout << "Enter the character: " << endl;
    cin >> symbol;

    cout << "Section B: printPineTree" << endl;
    printPineTree(n, symbol);
    
    return 0;
}

void printShiftedTriangle(int n, int m, char symbol) {

    for (int i = 1; i <= n; i++) {
        //printing out spaces
        for (int j = 1; j <= m; j++) {
            cout << " ";
        }

        //additional spaces needed to make the shape of the triangle
        for (int k = i; k < n; k++) {
            cout << " ";
        }

        //printing out the symbol, it will be i * 2 - 1
        for (int l = 1; l <= (i *2)-1; l++) {
            cout << symbol;
        }

        cout << endl;
    }

}

void printPineTree(int n, char symbol) {

    for (int i = 1; i <= n; i++) {
        printShiftedTriangle(i + 1, n-i, symbol);
    }
}