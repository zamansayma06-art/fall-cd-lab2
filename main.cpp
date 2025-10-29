#include <iostream>
using namespace std;

#include "identifier.h"
#include "average.h"
#include "minmax.h"
#include "fullname.h"

int main() {
    int choice;
    cout << "=== Program Menu ===\n";
    cout << "1. Check valid identifier\n";
    cout << "2. Calculate average\n";
    cout << "3. Find min and max\n";
    cout << "4. Get full name\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: runIdentifier(); break;
        case 2: runAverage(); break;
        case 3: runMinMax(); break;
        case 4: runFullName(); break;
        default: cout << "Invalid choice!" << endl;
    }

    return 0;
}

