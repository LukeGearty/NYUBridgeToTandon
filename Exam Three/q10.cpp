#include <iostream>
#include <vector>
using namespace std;


class Device {
public:
    virtual void showImage(int x) {}
};

class Television : public Device {
public:
    Television() {}
    void showImage(int x);
};

class Computer : public Device {
public:
    Computer() {}
    void showImage(int x);
};

int main() {
    //this problem asks to provide a main function that puts three chairs int a vector of furniture, but it also asked us to create computer and television and device classes? Did the question mean to ask for three computers in a vector of devices?
    Computer *one;
    Computer *two;
    Computer *three;
    vector <Device*> devices;

    devices.push_back(one);
    devices.push_back(two);
    devices.push_back(three);
    
    return 0;
}

void Television::showImage(int x) {
    cout << x << " Television" << endl;
}

void Computer::showImage(int x) {
    cout << x << " Computer" << endl;
}