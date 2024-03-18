#include <iostream>
using namespace std;

void printTriangle(int n);
void printOppositeTriangles(int n);
void printRuler(int n);

int main() {

    cout << "Section A: " << endl;
    int n; 
    cout << "Enter a positive integer: " << endl;
    cin >> n;
    printTriangle(n);
    cout << endl;

    cout << "Section B: " << endl;
    int m;
    cout << "Enter a positive integer: " << endl;
    cin >> m;
    printOppositeTriangles(m);
    cout << endl;

    cout << "Section C: " << endl;
    int x;
    cout << "Enter a positive integer: " << endl;
    cin >> x;
    printRuler(x);

    cout << endl;

    return 0;
}
void printTriangle(int n) {
    if (n == 0) {
        return;
    }
    else {
        printTriangle(n - 1);
        for (int i = 0; i < n; i++) {
            cout << "*";
        }
        cout << endl;
    }
}
void printOppositeTriangles(int n) {
    if (n == 0) {
        return;
    }
    else {
        for (int i = 0; i < n; i++) {
            cout << "*";
        }
        cout << endl;
        printOppositeTriangles(n - 1);
        for (int i = 0; i < n; i++) {
            cout << "*";
        }
        cout << endl;
    }
   
}
void printRuler(int n) {
    if (n == 0) {
        return;
    }
    else {
        printRuler(n - 1);
        for (int i = 0; i < n; i++) {
            cout << "-";
        }
        cout << endl;
        printRuler(n -1);
    }
}