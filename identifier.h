#ifndef IDENTIFIER_H
#define IDENTIFIER_H
#include <iostream>
#include <cctype>
using namespace std;

bool validIdentifier(const string& s) {
    if (!(isalpha(s[0]) || s[0] == '_')) {
        return false;
    }
    for (int i = 1; i < s.length(); i++) {
        if (!(isalnum(s[i]) || s[i] == '_')) {
            return false;
        }
    }
    return true;
}

void runIdentifier() {
    string s;
    cout << "Enter an input: ";
    cin >> s;

    if (validIdentifier(s)) {
        cout << "Valid identifier" << endl;
    } else {
        cout << "Invalid identifier" << endl;
    }
}
#endif

