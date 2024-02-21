#include <iostream>
using namespace std;

const double CLUB_DISCOUNT = 0.10;
int main() {

    double firstItem, secondItem, basePrice, bogoPrice, taxRate;
    char isClubMember;
    double discountAmount, discountPrice, totalPrice;

    cout << "Enter price of first item: ";
    cin >> firstItem;
    cout << "Enter price of second item: ";
    cin >> secondItem;
    cout << "Does customer have a club card? (Y/N): ";
    cin >> isClubMember;

    basePrice = firstItem + secondItem;
    if (firstItem > secondItem) {
        bogoPrice = firstItem + (secondItem/2);
    } 
    else {
        bogoPrice = secondItem + (firstItem/2);
    }

    cout << "Enter tax rate, e.g. 5.5 for 5.5\% tax: ";
    cin >> taxRate;

    if (isClubMember == 'Y' || isClubMember == 'y') {
        discountAmount = CLUB_DISCOUNT * bogoPrice;
    } 
    else {
        discountAmount = 0;
    }

    discountPrice = bogoPrice - discountAmount;
    totalPrice = discountPrice + (discountPrice *(taxRate/100));

    cout << "Base price: " << basePrice << endl;
    cout << "Price after discounts: " << discountPrice << endl;
    cout << "Total Price: " << totalPrice << endl;

    return 0;
}