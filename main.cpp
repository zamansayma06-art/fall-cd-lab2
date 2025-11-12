#include <iostream>
#include <fstream>
using namespace std;

bool isNum(string s) {
    if (s.empty()) return false;

    if (!(isalpha(s[0]) || s[0] == ' ')) return false;

    for (int i = 1; i < s.length(); i++) {
        if (!(isalnum(s[i]) || s[i] == ' ')) return false;
    }
    return true;
}
bool readFile(string filename) {
    ifstream file(filename);
    if (!file) return false;

    string word;


    cout << "checking identifiers:"<<endl;
    while (file >> word) {
        cout << "String : " << word;
        if (isNum(word))
            cout << " -> valid identifier"<<endl;
        else
            cout << " -> invalid identifier"<<endl;
    }
    return true;
}
int main() {
    string filename = "comp.txt";

    if (readFile(filename))
        cout << "file read and checked successfully!" << endl;
    else
        cout << "failed to read file!" << endl;

    return 0;
}
