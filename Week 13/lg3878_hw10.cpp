#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class LList;
class Node;

class Person {
public:
    string name;
    double amountPaid;
    double amountOwed;
    double amountWillBePaid;
    Person() {amountOwed = 0.0; amountWillBePaid = 0.0;}
};

//A Linked List of the Person Class
class Node {
private:
    Person Data;
    Node* Next;
public: 
    Node(Person& person) {Data = person; Next = nullptr;}
    friend class LList;
    friend class Person;
};

class LList {
    Node* Head;
    int Size;
    double Total;
public:
    LList() {Head = nullptr; Size = 0; Total = 0.0;}
    ~LList() {clear();}
    LList(const LList& rhs) : Head(nullptr) {*this=rhs;}
    LList& operator=(const LList& rhs) {return *this;}
    void clear();
    bool isEmpty() const;
    void insertAtHead(Person& person);
    void insertAtEnd(Person& person);
    int getSize() const;
    void print() const;
    double getTotal() const {return Total;};
    void calculateAmountOwed();
};

void openFile(ifstream& infile);
int main() {
    ifstream inFile;
    openFile(inFile);
    Person temp;
    LList people;
    while (inFile >> temp.amountPaid) {
        inFile.ignore(9999, ' ');
        getline(inFile, temp.name);
        people.insertAtEnd(temp);
    }
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    people.calculateAmountOwed();
    return 0;
}

void openFile(ifstream& inFile) {
    string filename;
    cout << "What is the name of the file?: ";
    cin >> filename;
    inFile.open(filename);
    while (!inFile) {
        cout << "File failed to open, please enter again: " << endl;
        cin >> filename;
        inFile.clear();
        inFile.open(filename);
    }
}

void LList::clear() {
    while (!isEmpty()) {
        Node* temp = this->Head;
        this->Head = Head->Next;
        delete temp;
    }
}

bool LList::isEmpty() const {
    return Head==nullptr;
}

void LList::insertAtHead(Person& person) {
    Node* newhead = new Node(person);
    Size++;
    if (this->Head == nullptr) {
        this->Head = newhead;
        Total += Head->Data.amountPaid;
    }
    else {
        newhead->Next = Head;
        this->Head = newhead;
        Total += Head->Data.amountPaid;
    }
}

void LList::insertAtEnd(Person& person) {
    if (isEmpty()) {
        insertAtHead(person);
    }
    else {
        Node *newnode = new Node(person);
        Node *end = Head;
        while (end->Next != nullptr) {
            end = end->Next;
        }
        end->Next = newnode;
        newnode->Next = nullptr;
        Size++;
        Total += newnode->Data.amountPaid;
    }
}

int LList::getSize() const {
    int count = 0;
    Node* temp = Head;
    while (temp != nullptr) {
        count++;
        temp = temp->Next;
    }
    return count;
}

void LList::print() const {
    if (Size == 0) {
        cout << "Empty list" << endl;
        return;
    }
    Node* temp = this->Head;
    for (int i = 0; i < Size; i++) {
        cout << temp->Data.name << " " << temp->Data.amountOwed << endl;
        temp = temp->Next;
    }
}

void LList::calculateAmountOwed() {
    double division = this->Total / (double)this->Size;
    Node* temp = this->Head;
    vector <Person> payThisPerson;
    vector <Person> owesMoney;
    while (temp != nullptr) {
        if (temp->Data.amountPaid == division) {
            //if they paid the exact amount, they don't have to pay anything, and they won't be paid anything. Doing nothing with them.
            temp->Data.amountWillBePaid = 0.0;
            temp->Data.amountOwed = 0.0;
            cout << temp->Data.name << ", you don't need to do anything" << endl;
        }
        else if (temp->Data.amountPaid > division) {
            //if they paid more than the division, they don't have to pay anything, and they will be paid
            temp->Data.amountOwed = 0.0;
            temp->Data.amountWillBePaid = temp->Data.amountPaid - division;
            payThisPerson.push_back(temp->Data);
        }
        else if (temp->Data.amountPaid < division) {
            temp->Data.amountOwed = division - temp->Data.amountPaid;
            temp->Data.amountWillBePaid = 0.0;
            owesMoney.push_back(temp->Data);
        }
        temp = temp->Next;
    }
    int oIndex = 0; //keeping track of the owesMoney vector
    for (int i = 0; i < payThisPerson.size(); i++) {
        while (payThisPerson[i].amountWillBePaid > 0 && oIndex < owesMoney.size()) {
            if (owesMoney[oIndex].amountOwed < payThisPerson[i].amountWillBePaid) {
                cout << owesMoney[oIndex].name << ", you give " << payThisPerson[i].name << " $" << owesMoney[oIndex].amountOwed << endl;
                payThisPerson[i].amountWillBePaid = payThisPerson[i].amountWillBePaid - owesMoney[oIndex].amountOwed;
                owesMoney[oIndex].amountOwed = 0;
                oIndex++; 
            }
            else if (owesMoney[oIndex].amountOwed > payThisPerson[i].amountWillBePaid) {
                cout << owesMoney[oIndex].name << ", you give " << payThisPerson[i].name << " $" << payThisPerson[i].amountWillBePaid << endl;
                owesMoney[oIndex].amountOwed = owesMoney[oIndex].amountOwed - payThisPerson[i].amountWillBePaid;
                payThisPerson[i].amountWillBePaid = 0;
            }
            else {
                cout << owesMoney[oIndex].name << ", you give " << payThisPerson[i].name << " $" << payThisPerson[i].amountWillBePaid << endl;
                owesMoney[oIndex].amountOwed = 0;
                payThisPerson[i].amountWillBePaid = 0;
                oIndex++;
            }
        }
    }
    cout << "In the end, you should all have spent around $" << division << endl;
}