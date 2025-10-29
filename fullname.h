#ifndef FULLNAME_H
#define FULLNAME_H
#include <iostream>
using namespace std;

string getFullName(string firstName, string lastName) {
    return firstName + " " + lastName;
}

void runFullName() {
    string firstName, lastName;
    cout << "Enter first name: ";
    cin >> firstName;
    cout << "Enter last name: ";
    cin >> lastName;
    cout << "Full name = " << getFullName(firstName, lastName) << endl;
}
#endif

