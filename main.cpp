#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;

string keywords[] = {
    "int", "float", "char", "double", "string", "if", "else", "while", "for", "return"
};
int keywordCount = 10;

bool isKeyword(string word) {
    for (int i = 0; i < keywordCount; i++) {
        if (keywords[i] == word)
        return true;
    }
    return false;
}

bool isOperator(char c) {
    string ops = "+-*/=%<>";

    for (char op : ops)
    if (c == op) return true;

    return false;
}

bool isPunctuation(char c) {
    string punc = ";(),{}[]";

    for (char p : punc)
    if (c == p) return true;

    return false;
}

int main() {

    ifstream file("sample.txt");
    if (!file) {
        cout << "Error: Could not open sample.txt\n";
        return 1;
    }

    cout << "=== Lexical Analyzer Output ===\n\n";

    char c;
    string token = "";

    while (file.get(c)) {

        if (isspace(c)) {
            continue;
        }

        if (isalpha(c)) {
            token = "";
            token += c;

            while (file.get(c) && (isalnum(c) || c == '_')) {
                token += c;
            }
            file.unget();

            if (isKeyword(token))
            cout << token << " ---> KEYWORD\n";
            else
            cout << token << " ---> IDENTIFIER\n";
        }

        else if (isdigit(c)) {
            token = "";
            token += c;

            while (file.get(c) && isdigit(c)) {
                token += c;
            }
            file.unget();

            cout << token << " ---> CONSTANT\n";
        }


        else if (c == '"') {
            token = "";
            while (file.get(c) && c != '"') {
                token += c;
            }
            cout << "\"" << token << "\" ---> STRING CONSTANT\n";
        }


        else if (isOperator(c)) {
            cout << c << " ---> OPERATOR\n";
        }


        else if (isPunctuation(c)) {
            cout << c << " ---> PUNCTUATION\n";
        }

        else {
            cout << c << " ---> UNKNOWN\n";
        }
    }

    return 0;
}
